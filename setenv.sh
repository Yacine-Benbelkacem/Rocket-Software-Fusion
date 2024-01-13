#!/bin/bash
export qnxexternal=$(pwd)
export install_folder_name=install

export fusion_bin_install=$(pwd)/$install_folder_name/bin
export fusion_libs_install=$(pwd)/$install_folder_name/lib
export fusion_includes_install=$(pwd)/$install_folder_name/include

export fusion_messages_includes_install=$(pwd)/$install_folder_name/include/messages

export qnx_toolchain=$(pwd)/qnx.nto.toolchain.cmake
