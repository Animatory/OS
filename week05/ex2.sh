#!/usr/bin/env bash
if ln ex2.sh ex2.sh.lock
then
    for i in {1..100}
    do
        text=($(<"./r.txt"))
        let "a=((${text[-1]}+1))"
        echo -n " ${a}" >> r.txt
    done
    rm -f ex2.sh.lock
fi