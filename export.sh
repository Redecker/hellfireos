#!/bin/bash

var_path=$(dirname -- $(readlink -fn -- "$0"))

export PATH=$PATH:$var_path/gcc-4.6.1/bin

echo $PATH

