#!/bin/bash

echo --------- INICIO DE PRUEBAS ----------
echo Prueba para ls -l wc -w

echo Original:
# <./test_files/infile ls -l | wc -l >./test_files/ls_outfile
cat ./test_files/ls_outfile
echo Mío:
./pipex.a ./test_files/infile "ls -l" "wc -l" ./outfile
cat outfile

echo ---------------------------------------------------------
echo Prueba para grep a1 wc -w
echo Original:
# <./test_files/infile grep a1 | wc -w >./test_files/grep_outfile
cat ./test_files/grep_outfile
echo Mío:
./pipex.a ./test_files/infile "grep a1" "wc -w" ./outfile
cat outfile
