#!/bin/bash

cat ontology.dat | grep -E "domain|name" | sed 's/<domain>//g' | sed ':a;N;$!ba;s/\n/ /g' | sed 's/<\/domain>/\n/g' | sed 's/<name>//g' | sed 's/<\/name>//g' | sed 's/\t\t/\t/g'
