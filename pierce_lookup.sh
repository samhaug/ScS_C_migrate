#!/bin/bash

seq 0 1 100 > deg.dat

#Conversion depth and event depth sequences
c_dep=$(seq 220 5 720)
ev_dep=$(seq 60 40 660)

cmd="taup_pierce -mod prem"
n="/dev/null"

count=0
for ev in $ev_dep
do
    echo $ev_dp
    for c in $c_dep
    do
        echo $count
        # ScS family
        $cmd -h $ev -ph ScSScS^${c}ScS -rev -pierce $c -o ${ev}_ScS^${c}ScS<deg.dat>$n
        # ScSScS family
        ((count++))
    done
done

