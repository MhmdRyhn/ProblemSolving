#!/bin/bash

read n

ans=0

# c style for loop
for (( c=1; c<=$n; c++ )); do
	read a
	ans=$(( $ans+$a ))
done

printf "%0.3f" $(echo "$ans/$n" | bc -l)

