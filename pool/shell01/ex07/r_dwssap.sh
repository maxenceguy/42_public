#!/bin/sh
cat /etc/passwd | grep -v '^#' | sed -n 'n;p' | awk -F: '{print $2 ":" $1}' | rev | sort -r | awk 'NR >= ENVIRON["FT_LINE1"] && NR <= ENVIRON["FT_LINE2"]'
