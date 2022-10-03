#!/bin/bash
find . -name "*" | wc -l | sed 's/ //g' 
