#!/bin/bash

read n


: <<'comment'
** Noticable: $ before parantesis 
** `bc` util command, which means `basic calculator`
** -l or --mathlib: Uses the predefined math routines which is for 
comment

printf "%0.3f" $(echo "$n" | bc -l)

