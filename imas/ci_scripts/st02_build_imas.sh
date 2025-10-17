#!/bin/bash
#
# IMAS INTERFACE BUILD SCRIPT FOR CI/CD
# ======================================
#
# This script sets up the environment and builds the IMAS interface component.
# It automatically sources the module configuration and executes the interface build.
#
# USAGE:
#   ./st02_build_imas.sh
#
# PREREQUISITES:
#   - st00_header.sh must be in the same directory
#   - Valid Makefile with 'interface' target in repository root
#   - Proper IMAS module environment setup
#

set -e -o pipefail

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

echo "Sourcing environment setup..."
source "${SCRIPT_DIR}/st00_header.sh"

cd "${DINA_ROOT}"

echo "Building IMAS interface..."
make interface
echo "IMAS interface build completed successfully!"
