#!/bin/bash

./b2 install toolset=qcc target-os=qnxnto threadapi=pthread link=shared -l24\
--layout=system --without-python --without-mpi --without-graph_parallel \
cxxflags="-Vgcc/8.3.0,gcc_ntoaarch64le -Y_cxx -Wc, -std=gnu++17 -D_LITTLE_ENDIAN" \
linkflags="-Vgcc/8.3.0,gcc_ntoaarch64le -Y_cxx -lang-c++" \
-j4 \
--prefix=$qnxexternal/install
