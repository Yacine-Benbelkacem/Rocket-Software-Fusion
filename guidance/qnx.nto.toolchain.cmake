cmake_minimum_required(VERSION 3.5)

set(CMAKE_SYSTEM_NAME QNX)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR aarch64)
set(QNX_VERSION "qnx7.1.0")



set(CMAKE_AS "$ENV{QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-unknown-nto-${QNX_VERSION}-as")
set(CMAKE_C_COMPILER "$ENV{QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-unknown-nto-${QNX_VERSION}-gcc")
set(CMAKE_CXX_COMPILER "$ENV{QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-unknown-nto-${QNX_VERSION}-g++")

set(CMAKE_FIND_ROOT_PATH $ENV{QNX_TARGET})
set(CMAKE_SYSROOT $ENV{QNX_TARGET})

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)



set(ENV{CFLAGS} "--sysroot=$ENV{QNX_TARGET} $ENV{CFLAGS}")

# Add '-rpath' to the linker flags
set(ENV{LDFLAGS} "--sysroot=$ENV{QNX_TARGET} -Wl,-rpath,$ENV{QNX_TARGET} $ENV{LDFLAGS}")


add_definitions(-D__AARCH64_QNX__)
add_definitions(-D_POSIX_C_SOURCE=200112L -D_QNX_SOURCE -D_FILE_OFFSET_BITS=64)
message("Compiler settings for qnx ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "$ENV{CFLAGS}  ${CMAKE_CXX_FLAGS} -lsocket -fexceptions -fPIC -D_XOPEN_SOURCE=700 -std=c++17")
set(CMAKE_C_FLAGS "$ENV{CFLAG} ${CMAKE_C_FLAGS} -std=gnu99 -lsocket -fPIC -D_XOPEN_SOURCE=700")


set(CMAKE_C_COMPILER_TARGET aarch64)
set(CMAKE_CXX_COMPILER_TARGET aarch64)
set(CMAKE_LINKER $ENV{QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-unknown-nto-${QNX_VERSION}-ld)
set(LINKER_FLAGS "$ENV{LDFLAGS} -Wl,--no-undefined -Wl,--gc-sections -Wl,-z,relro -Wl,-z,now,-lc")



set(CMAKE_SHARED_LINKER_FLAGS "${LINKER_FLAGS} ${CMAKE_SHARED_LINKER_FLAGS}")
set(CMAKE_MODULE_LINKER_FLAGS "${LINKER_FLAGS} ${CMAKE_MODULE_LINKER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS}")

set(CMAKE_SYSTEM_PREFIX_PATH "/usr/aarch64-unknown-nto-qnx/aarch64le")

set(DOPENSSL_ROOT_DIR "$ENV{QNX_TARGET}/usr/include/openssl")
set(DOPENSSL_CRYPTO_LIBRARY "$ENV{QNX_TARGET}/usr/include/openssl/lib")

set(FOONATHAN_MEMORY_CONTAINER_NODE_SIZES_IMPL $ENV{FOONATHAN_MEMORY_CONTAINER_NODE_SIZES_IMPL})

set(fastrtps_DIR ${QNX_TARGET}/aarch64le/lib)
set(fastcdr_DIR ${QNX_TARGET}/aarch64le/lib)


set(fastrtps_INCLUDE_DIR ${QNX_TARGET}/aarch64le/include/fastrtps)
set(fastcdr_INDLUDE_DIR ${QNX_TARGET}/aarch64le/include/fastcdr)


message("Including the header directories")


include_directories(
  $ENV{QNX_TARGET}/aarch64le/include #eprosima files
  $ENV{QNX_TARGET}/aarch64le/fastrtps
  $ENV{QNX_TARGET}/aarch64le/fastcdr
  $ENV{QNX_TARGET}/usr/include/c++/v1
)

link_directories(
  $ENV{QNX_TARGET}/aarch64le/lib
  $ENV{QNX_TARGET}/usr/include/c++/v1
)



# search for programs in the build host directories



