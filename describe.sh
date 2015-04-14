#!/bin/bash

for d in */; do
  echo -n `basename $d`
  for ((i=0; i< (25 - ${#d}); i++)){ echo -n "-"; }
  cat $d/desc.txt
done
