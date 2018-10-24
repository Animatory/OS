#!/bin/bash
link ../week01/file.txt _ex2.txt > ex2.txt
ls -i _ex2.txt
find -inum 17169973580057080 >> ex2.txt
find -inum 17169973580057080 -exec rm {} \; >> ex2.txt