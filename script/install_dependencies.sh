#!/bin/bash

# CUnit - (unit test in c)
sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev

# valgrind - (mem leck check)
sudo apt-get install valgrind

# Python - (install norminette)
sudo apt-get install python3

# Norminette - (syntax norm check)
python3 -m pip install --upgrade pip setuptools
python3 -m pip install norminette
