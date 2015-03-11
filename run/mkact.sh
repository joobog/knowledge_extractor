#!/bin/bash

#siox-inst posix,mpi mpiexec -n 1 ~/codeblocks/mpi/bin/Debug/mpi
#LD_PRELOAD=$HOME/install/siox/lib/libsiox-posix-dlsym.so siox-inst posix /bin/dd if=/dev/random of=./rand count=10 bs=1M
siox-inst posix cp ./rand ./rand2
rm ./rand2
#siox-inst posix fwrite


