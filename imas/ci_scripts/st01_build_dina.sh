#!/bin/bash
#
# DINA BUILD SCRIPT FOR CI/CD
# ============================
#
# This script sets up the environment and builds the DINA project.
# It automatically sources the module configuration and executes the build.
#
# USAGE:
#   ./st01_build_dina.sh
#
# PREREQUISITES:
#   - st00_header.sh must be in the same directory
#   - Valid Makefile with 'dina' target in repository root
#   - Proper module environment setup
#
set -e -o pipefail

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

echo "Sourcing environment setup..."
source "${SCRIPT_DIR}/st00_header.sh"

cd "${DINA_ROOT}"

echo "Building DINA..."
make dina
echo "DINA build completed successfully!"
