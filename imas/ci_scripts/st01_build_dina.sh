#!/bin/bash
# Build script for DINA
#
# This script loads the environment and builds DINA

set -e -o pipefail

# Get the directory where this script is located
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

# Source the header script to set up environment
echo "Sourcing environment setup..."
source "${SCRIPT_DIR}/st00_header.sh"

# Change to the repository root directory
cd "${DINA_ROOT}"

echo "Building DINA..."
make dina

echo "DINA build completed successfully!"
