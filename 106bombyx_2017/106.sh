#!/bin/bash

n=0
state=0
k=0
i0=0
i1=0

read -p "number of first generation individuals : " n

read -p "curve or synthetic sheme ? (1/2) : " state

while [ $state != 1 ] && [ $state != 2 ];
do
    read -p "curve or synthetic sheme ? (1/2) : " state
done

if [ $state -eq 1 ]
then
    read -p "growth rate from 1 to 4 : " k
    ./106bombyx $n $k > data
    cat drawer.gnu | gnuplot
    exit 0
fi
if [ $state -eq 2 ]
then
    read -p "initial generation (included) : " i0
    read -p "final generation (included) : " i1
    ./106bombyx $n $i0 $i1 > data
    cat drawer.gnu | gnuplot
    exit 0
fi
