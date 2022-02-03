#!/bin/bash

#./pipex.a ./test_files/infile "ls -l" "wc -l" ./test_files/outfile
./pipex.a ./test_files/infile "grep a1" "wc -w" ./test_files/outfile
