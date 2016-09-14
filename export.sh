#!/bin/bash

var_path=$(dirname -- $(readlink -fn -- "$0"))

#ls $var_path/gcc-4.6.1/bin

export PATH=$PATH:$var_path/gcc-4.6.1/bin

#export PATH=$PATH:home/redecker/Documents/hellfireos/gcc-4.6.1/bin/
