#!/bin/bash

find . -type d -name 'venv' -prune -o \( -type f \( -name "*.cpp" -o -name "*.py" \) -print \) | wc -l





