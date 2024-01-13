#ifdef __cplusplus
extern "C" {
#endif
    
extern solver_int32_default RocketSolver_adtool2forces(RocketSolver_float *x,        /* primal vars                                         */
										 RocketSolver_float *y,        /* eq. constraint multiplers                           */
										 RocketSolver_float *l,        /* ineq. constraint multipliers                        */
										 RocketSolver_float *p,        /* parameters                                          */
										 RocketSolver_float *f,        /* objective function (scalar)                         */
										 RocketSolver_float *nabla_f,  /* gradient of objective function                      */
										 RocketSolver_float *c,        /* dynamics                                            */
										 RocketSolver_float *nabla_c,  /* Jacobian of the dynamics (column major)             */
										 RocketSolver_float *h,        /* inequality constraints                              */
										 RocketSolver_float *nabla_h,  /* Jacobian of inequality constraints (column major)   */
										 RocketSolver_float *hess,     /* Hessian (column major)                              */
										 solver_int32_default stage,     /* stage number (0 indexed)                            */
										 solver_int32_default iteration, /* iteration number of solver                          */
										 solver_int32_default threadID  /* Id of caller thread */);

#ifdef __cplusplus
} /* extern "C" */
#endif
