#!/usr/bin/env python3
import xml.etree.ElementTree as ET
import shutil
import argparse
import re
from pathlib import Path

def parse_config(xml_file, section="output"):
    """Parse the XML file and extract the path to the IDSs."""
    try:
        tree = ET.parse(xml_file)
        root = tree.getroot()
        
        # Find the output section
        output_section = root.find(section)
        if output_section is None:
            raise ValueError(f"No <{section}> section found in XML file")

        # Extract uri field in the section
        uri = output_section.find('uri')
        if uri is None:
            raise ValueError(f"Missing required field 'uri' in <{section}> section")
        print(f"URI found in <{section}> section: {uri.text}")
        
        # extract the path query from uri
        uri_path = re.search(r'[?&]path=([^&]+)', uri.text).group(1)
        if uri_path is None:
            raise ValueError(f"Could not find the path query in the uri")
        print(f"Extracted path from URI: {uri_path}")

        return uri_path
    
    except ET.ParseError as e:
        raise ValueError(f"Failed to parse XML file: {e}")

def copy_xml_files(source_dir, target_dir):
    """Copy all XML files from source directory to target directory."""
    source_path = Path(source_dir)
    target_path = Path(target_dir)
    
    # Create target directory if it doesn't exist
    target_path.mkdir(parents=True, exist_ok=True)
    
    # Find all XML files in current directory
    xml_files = list(source_path.glob("*.xml"))
    
    if not xml_files:
        print(f"No XML files found in {source_dir}")
        return
    
    copied_files = []
    for xml_file in xml_files:
        target_file = target_path / xml_file.name
        try:
            shutil.copy2(xml_file, target_file)
            copied_files.append(xml_file.name)
            print(f"Copied: {xml_file.name} -> {target_file}")
        except Exception as e:
            print(f"Error copying {xml_file.name}: {e}")
    
    print(f"Successfully copied {len(copied_files)} XML files to {target_path}")
    return copied_files

def copy_bin_files(source_dir, target_dir):
    """Copy all *.bin files from source directory to target directory."""
    source_path = Path(source_dir)
    target_path = Path(target_dir)
    
    # Create target directory if it doesn't exist
    target_path.mkdir(parents=True, exist_ok=True)

    # Find all .bin files in source directory
    bin_files = list(source_path.glob("*.bin"))

    if not bin_files:
        print(f"No .bin files found in {source_dir}")
        return

    copied_files = []
    for bin_file in bin_files:
        target_file = target_path / bin_file.name
        try:
            shutil.copy2(bin_file, target_file)
            copied_files.append(bin_file.name)
            print(f"Copied: {bin_file.name} -> {target_file}")
        except Exception as e:
            print(f"Error copying {bin_file.name}: {e}")

    print(f"Successfully copied {len(copied_files)} .bin files to {target_path}")
    return copied_files




    
def main():
    parser = argparse.ArgumentParser(description="Copy XML files based on configuration")
    parser.add_argument("wfconfig", help="Input XML configuration file")
    parser.add_argument("--source-dir", default=".", help="Source directory (default: current directory)")
    
    args = parser.parse_args()
    if args.source_dir == ".":
        args.source_dir = str(Path.cwd())
        print(f"Using current directory as source: {args.source_dir}\n")
    
    try:
        # Parse the configuration TCV controller binary files
        uri_path_ps = parse_config(args.wfconfig, section="pulse_schedule")
        print(f"Pulse_schedule section parsed successfully:")
        # Copy TCV controller binary files
        print(f"Copying TCV controller binary files...")
        print(f"Copy from: {uri_path_ps}")
        print(f"Copy to: {args.source_dir}")
        copy_bin_files(uri_path_ps, args.source_dir)
        print(f"TCV controller binary files copied successfully\n")
        
        # Parse the configuration XML
        uri_path_out = parse_config(args.wfconfig, section="output")
        print(f"Output section parsed successfully:")
       # Copy XML files
        print(f"Copying XML config files and controller binary files...")
        print(f"Copy from: {args.source_dir}")
        print(f"Copy to: {uri_path_out}")
        copy_xml_files(args.source_dir, uri_path_out)
        copy_bin_files(args.source_dir, uri_path_out)

                
    except Exception as e:
        print(f"Error: {e}")
        return 1
    
    return 0

if __name__ == "__main__":
    exit(main())