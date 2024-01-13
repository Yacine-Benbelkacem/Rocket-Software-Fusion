
#ifndef ROCKETSOLVER_CASADI_H
#define ROCKETSOLVER_CASADI_H

/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int int
#endif

int RocketSolver_objective_1(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem);

void RocketSolver_objective_1_incref(void);

const casadi_int* RocketSolver_objective_1_sparsity_out(casadi_int i);

int RocketSolver_dynamics_1(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem);

void RocketSolver_dynamics_1_incref(void);

const casadi_int* RocketSolver_dynamics_1_sparsity_out(casadi_int i);

int RocketSolver_inequalities_1(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem);

void RocketSolver_inequalities_1_incref(void);

const casadi_int* RocketSolver_inequalities_1_sparsity_out(casadi_int i);

int RocketSolver_objective_10(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem);

void RocketSolver_objective_10_incref(void);

const casadi_int* RocketSolver_objective_10_sparsity_out(casadi_int i);

int RocketSolver_inequalities_10(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem);

void RocketSolver_inequalities_10_incref(void);

const casadi_int* RocketSolver_inequalities_10_sparsity_out(casadi_int i);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif
