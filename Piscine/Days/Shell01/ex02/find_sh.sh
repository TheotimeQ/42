#!/bin/bash
find . -type f -name "*.sh" -print | sed 's/.\/.*\///g' | sed 's/\.sh//g' | sed 's/\.\///g'
