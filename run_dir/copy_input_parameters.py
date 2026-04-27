#!/usr/bin/env python3
import xml.etree.ElementTree as ET
import os
import shutil
import glob
import argparse
from pathlib import Path

def parse_config(xml_file, section="output"):
    """Parse the XML file and extract output configuration."""
    try:
        tree = ET.parse(xml_file)
        root = tree.getroot()
        
        # Find the output section
        output_section = root.find(section)
        if output_section is None:
            raise ValueError(f"No <{section}> section found in XML file")

        # Extract values
        user = output_section.find('user')
        database = output_section.find('database')
        pulse = output_section.find('pulse')
        run = output_section.find('run')
        
        if any(elem is None for elem in [user, database, pulse, run]):
            raise ValueError(f"Missing required fields in <{section}> section")

        return {
            'user': user.text,
            'database': database.text,
            'pulse': pulse.text,
            'run': run.text
        }
    except ET.ParseError as e:
        raise ValueError(f"Failed to parse XML file: {e}")

def build_path(config, base_path="/home/ITER"):
    """Build the output directory path from configuration."""

    return Path(base_path) / config['user'] / "public" / "imasdb" / config['database'] / "3" / config['pulse'] / config['run']

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
    
    print(f"\nSuccessfully copied {len(copied_files)} XML files to {target_path}")
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

    print(f"\nSuccessfully copied {len(copied_files)} .bin files to {target_path}")
    return copied_files




    
def main():
    parser = argparse.ArgumentParser(description="Copy XML files based on configuration")
    parser.add_argument("wfconfig", help="Input XML configuration file")
    parser.add_argument("--source-dir", default=".", help="Source directory (default: current directory)")
    parser.add_argument("--base-path", default="/home/ITER", help="Base path for output directory")
    
    args = parser.parse_args()
    try:
        # Parse the configuration TCV controller binary files
        config = parse_config(args.wfconfig, section="pulse_schedule")
        print(f"Configuration TCV CONTROLLER parsed:")
        print(f"  User: {config['user']}")
        print(f"  Database: {config['database']}")
        print(f"  Pulse: {config['pulse']}")
        print(f"  Run: {config['run']}")
        
        # Copy TCV controller binary files
        path2 = build_path(config, args.base_path)
        print(f"Copying TCV controller binary files...")
        print(f"Copy from: {path2}")
        print(f"Copy to: {args.source_dir}")
        copy_bin_files(path2, args.source_dir)    
        
        
        # Parse the configuration XML
        config = parse_config(args.wfconfig, section="output")
        print(f"Configuration OUTPUT parsed:")
        print(f"  User: {config['user']}")
        print(f"  Database: {config['database']}")
        print(f"  Pulse: {config['pulse']}")
        print(f"  Run: {config['run']}")
        
       # Copy XML files
        path1 = build_path(config, args.base_path)
        print(f"Copying XML files...")
        print(f"Copy from: {args.source_dir}")
        print(f"Copy to: {path1}")
        copy_xml_files(args.source_dir, path1)
        copy_bin_files(args.source_dir, path1)
        
                
    except Exception as e:
        print(f"Error: {e}")
        return 1
    
    return 0

if __name__ == "__main__":
    exit(main())