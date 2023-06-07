#!/bin/bash

# Change the current directory to the root of the Git repository
cd "$(git rev-parse --show-toplevel)"

# Enable globstar option in bash
shopt -s globstar

# List all ignored files
git check-ignore **