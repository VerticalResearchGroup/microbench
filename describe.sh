#!/bin/bash

for d in */; do
  echo -n `basename $d`
  for ((i=0; i< (18 - ${#d}); i++)){ echo -n "-"; }
  cat $d/desc.txt
done
