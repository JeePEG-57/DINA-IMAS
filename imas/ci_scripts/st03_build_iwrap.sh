#!/bin/bash
#
# IWRAP ACTOR BUILD SCRIPT FOR CI/CD
# ===================================
#
# This script sets up the environment and builds the iWrap actor component.
# It automatically sources the module configuration and creates the iWrap actor.
#
# USAGE:
#   ./st03_build_iwrap.sh
#
# PREREQUISITES:
#   - st00_header.sh must be in the same directory
#   - Valid Makefile with 'iwrap' target in repository root
#   - Proper iWrap module environment setup
#


set -e -o pipefail

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

echo "Sourcing environment setup..."
source "${SCRIPT_DIR}/st00_header.sh"

cd "${DINA_ROOT}"

echo "Building iwrap actor..."
make iwrap
echo "iwrap actor created successfully!"
