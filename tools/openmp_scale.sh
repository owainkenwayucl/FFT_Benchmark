#!/usr/bin/env bash

# This script loops over values of OMP_NUM_THREADS and runs the FFT_Bench code.

# WARNING: This script intentionally truncates output.txt

rm -f output.txt
for a in $(seq 1 $1)
do
  export OMP_NUM_THREADS=${a}
  echo Threads: ${a} >> output.txt
  ./FFT_Bench -f -c 10
done
