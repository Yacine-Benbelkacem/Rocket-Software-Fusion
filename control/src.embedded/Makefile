aarch= -Vgcc_ntoaarch64le
CC=qcc
CXX=q++
CFLAGS= -Y_gpp -lstdc++ -lc -lsocket -std=c99

ad_target=adtools
casadi_target=casadi
mpc_target=mpc



$(ad_target)_includes= -I./RocketSolver/include
$(ad_target)_srcs= ./RocketSolver/interface/RocketSolver_adtool2forces.c
$(ad_target)_libs= -lRocketSolver
$(ad_target)_libs_path = -L./RocketSolver/lib

$(casadi_target)_srcs= ./RocketSolver/interface/RocketSolver_casadi.c

$(mpc_target)_srcs = ./src/main.cxx  ./src/mpc.cxx
$(mpc_target)_obj = RocketSolver_adtool2forces.o RocketSolver_casadi.o

all:$(ad_target) $(casadi_target)

$(ad_target):
	$(CC) $(aarch) -static -c $($@_srcs) $($@_libs) $(CFLAGS) $($@_libs_path) $($@_includes)

$(casadi_target):
	$(CC) $(aarch) -static -c $($@_srcs) $($@_libs) $(CFLAGS) $($@_libs_path) $($@_includes) 



$(mpc_target): $($(mpc_target)_obj)
	$(CC) $(aarch) -static -c $($@_srcs) $($@_libs) $(CFLAGS) $($@_libs_path) $($@_includes) 



