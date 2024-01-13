cmake_minimum_required(VERSION 3.5)

#set(CMAKE_IGNORE_PATH "/usr/local/lib")

set(CMAKE_SYSTEM_NAME QNX)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR aarch64)
set(QNX_VERSION "qnx7.1.0")


set(CMAKE_FIND_ROOT_PATH $ENV{QNX_TARGET})
set(CMAKE_SYSROOT $ENV{QNX_TARGET})

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

#set(CMAKE_SYSTEM_NAME QNX)

#set(arch gcc_ntoaarch64le)
#set(ntoarch aarch64le)
#set(QNX_PROCESSOR aarch64le)

#set(CMAKE_C_COMPILER qcc)
#set(CMAKE_C_COMPILER_TARGET ${arch})

#set(CMAKE_CXX_COMPILER qcc -lang-c++)
#set(CMAKE_CXX_COMPILER_TARGET ${arch})


#file(GLOB_RECURSE libgcc_a
#	"$ENV{QNX_HOST}/usr/lib/gcc/aarch64-unknown-nto-qnx7.1.0/8.3.0/pic/libgcc.a")

#set(CMAKE_C_STANDARD_LIBRARIES_INIT
#	"${libgcc_a} -lc -Bsatic -lcS ${libgcc_a}")

#set(CMAKE_CXX_STANDARD_LIBRARIES_INIT
#	"-lc++ -lm ${CMAKE_C_STANDARD_LIBRARIES_INIT}")
#set(CMAKE_EXE_LINKER_FLAGS_INIT "-nodefaultlibs")
#set(CMAKE_SHARED_LINKER_FLAGS_INIT "-nodefaultlibs")
#set(CMAKE_MODULE_LINKER_FLAGS_INIT "-nodefaultlibs")

#set(CMAKE_ASM_COMPILER qcc -V${arch})
#set(CMAKE_ASM_DEFINE_FLAG "-Wa,--defsym,")

#set(CMAKE_RANLIB $ENV{QNX_HOST}/usr/bin/nto${ntoarch}-ranlib 
#	CACHE PATH "QNX ranlib Program" FORCE)
#set(CMAKE_AR $ENV{QNX_HOST}/usr/bin/nto${ntoarch}-ar
#    CACHE PATH "QNX qr Program" FORCE)




set(CMAKE_AS "$ENV{QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-unknown-nto-${QNX_VERSION}-as")

set(CMAKE_C_COMPILER "$ENV{QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-unknown-nto-${QNX_VERSION}-gcc")
set(CMAKE_CXX_COMPILER "$ENV{QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-unknown-nto-${QNX_VERSION}-g++")

#set(CMAKE_C_COMPILER "$ENV{QNX_HOST}/usr/bin/ntoaarch64-gcc")
#set(CMAKE_CXX_COMPILER "$ENV{QNX_HOST}/usr/bin/ntoaarch64-g++")

#set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)
#set(CMAKE_CXX_COMPILER aarch64-linux-gnu-cpp)



set(ENV{CFLAGS} "--sysroot=$ENV{QNX_TARGET} $ENV{CFLAGS}")

# Add '-rpath' to the linker flags
set(ENV{LDFLAGS} "--sysroot=$ENV{QNX_TARGET} -Wl,-rpath,$ENV{QNX_TARGET} $ENV{LDFLAGS}")


add_definitions(-D__AARCH64_QNX__)
add_definitions(-D_POSIX_C_SOURCE=200112L -D_QNX_SOURCE  -D_FILE_OFFSET_BITS=64)
message("Compiler settings for qnx ${CMAKE_CXX_FLAGS}")

#set(CMAKE_CXX_FLAGS "-fexceptions -fPIC -std=c++11 -D_XOPEN_SOURCE=700")
set(CMAKE_CXX_FLAGS "$ENV{CFLAGS}  ${CMAKE_CXX_FLAGS} -lsocket -fexceptions -fPIC -D_XOPEN_SOURCE=700 -std=c++17")
set(CMAKE_C_FLAGS "$ENV{CFLAG} ${CMAKE_C_FLAGS} -std=gnu99 -lsocket -fPIC -D_XOPEN_SOURCE=700")
#set(CMAKE_C_FLAGS "-std=c99 -fPIC -D_XOPEN_SOURCE=700")



set(CMAKE_LINKER $ENV{QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-unknown-nto-${QNX_VERSION}-ld)
#set(CMAKE_LINKER $ENV{QNX_HOST}/usr/bin/ntoaarch64-ld)
set(LINKER_FLAGS "-Wl,--no-undefined -Wl,--gc-sections -Wl,-z,relro -Wl,-z,now")



set(CMAKE_SHARED_LINKER_FLAGS "${LINKER_FLAGS} ${CMAKE_SHARED_LINKER_FLAGS}")
set(CMAKE_MODULE_LINKER_FLAGS "${LINKER_FLAGS} ${CMAKE_MODULE_LINKER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS}")

set(CMAKE_SYSTEM_PREFIX_PATH "/usr/aarch64-unknown-nto-qnx/aarch64le")

set(DOPENSSL_ROOT_DIR "$ENV{QNX_TARGET}/usr/include/openssl")
set(DOPENSSL_CRYPTO_LIBRARY "$ENV{QNX_TARGET}/usr/include/openssl/lib")



# custom libraries
#tinyxml2
#set(TINYXML2_DIR $ENV{qnxexternal}/install/lib/cmake/tinyxml2)
#set(TINYXML2_INCLUDE_DIR $ENV{qnxexternal}/install/include)
#set(TinyXML2_DIR $ENV{qnxexternal}/install/lib/cmake/tinyxml2)
#set(TinyXML2_INCLUDE_DIR $ENV{qnxexternal}/install/include)
set(tinyxml2_DIR $ENV{qnxexternal}/install/lib/cmake/tinyxml2)
set(tinyxml2_INCLUDE_DIR $ENV{qnxexternal}/install/include)
find_package(tinyxml2)

#fastrtps
set(fastrtps_DIR $ENV{qnxexternal}/install/share/fastrtps/cmake)
set(fastrtps_INCLUDE_DIR $ENV{qnxexternal}/install/include/fastrtps)
#fastcdr
set(fastcdr_DIR $ENV{qnxexternal}/install/lib/cmake/fastcdr)
set(fastcdr_INCLUDE_DIR $ENV{qnxexternal}/include/fastcdr)
#foonathan memroy
set(foonathan_memory_DIR $ENV{qnxexternal}/install/lib/foonathan_memory/cmake/)
set(foonathan_memory_INCLUDE_DIR $ENV{qnxexternal}/install/include)
#FIND_PACKAGE(foonathan_memory)


#asio
#set(tinyxml2_DIR $ENV{qnxexternal}/install/lib/cmake/tinyxml2)
set(Asio_INCLUDE_DIR $ENV{qnxexternal}/install/include)
set(ASIO_INCLUDE_DIR $ENV{qnxexternal}/install/include)

#FIND_PACKAGE(Asio)



#boost
#set(Boost_DIR $ENV{qnxexternal}/install/lib)
set(Boost_INCLUDE_DIR $ENV{qnxexternal}/install/include)
add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)
FIND_PACKAGE(Boost REQUIRED)
IF(Boost_FOUND)
	message(STATUS "FOUND BOOST")
	INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
	ADD_DEFINITIONS("-DHAS_BOOST")
ENDIF()



message("Including the header directories")

# search for programs in the build host directories
include_directories(
  $ENV{QNX_TARGET}/aarch64le/usr/include
  $ENV{QNX_TARGET}/usr/include
  $ENV{QNX_TARGET}/usr/include/aarch64
  $ENV{QNX_TARGET}/usr/include/aarch64/usr/lib
  $ENV{QNX_TARGET}/usr/include/c++/v1
  $ENV{qnxexternal}/install/include
  $ENV{qnxexternal}/mpc/RocketSolver/include
)

link_directories(
  $ENV{QNX_TARGET}/aarch64le/usr/lib
  $ENV{QNX_TARGET}/aarch64le/lib
  $ENV{qnxexternal}/install/lib
  $ENV{qnxexternal}/install/lib/cmake
)


