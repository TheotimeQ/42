#!/bin/bash
cat /etc/passwd | grep -v '#' | awk 'NR%2==0' | cut -d ":" -f1 | rev | sort -r | awk -v s="$FT_LINE1" -v e="$FT_LINE2" 'NR>=s&&NR<=e' | tr '\n' ' ' | sed 's/ /, /g' | sed 's/, $/./g' | tr -d "\n"
