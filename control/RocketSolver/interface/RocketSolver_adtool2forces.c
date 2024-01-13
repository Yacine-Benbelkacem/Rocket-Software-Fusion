/*
 * AD tool to FORCESPRO Template - missing information to be filled in by createADTool.m 
 * (C) embotech AG, Zurich, Switzerland, 2013-2022. All rights reserved.
 *
 * This file is part of the FORCESPRO client, and carries the same license.
 */ 

#ifdef __cplusplus
extern "C" {
#endif
    
#include "RocketSolver/include/RocketSolver.h"

#ifndef NULL
#define NULL ((void *) 0)
#endif


#include "RocketSolver_casadi.h"



/* copies data from sparse matrix into a dense one */
static void RocketSolver_sparse2fullcopy(solver_int32_default nrow, solver_int32_default ncol, const solver_int32_default *colidx, const solver_int32_default *row, RocketSolver_callback_float *data, RocketSolver_float *out)
{
    solver_int32_default i, j;
    
    /* copy data into dense matrix */
    for(i=0; i<ncol; i++)
    {
        for(j=colidx[i]; j<colidx[i+1]; j++)
        {
            out[i*nrow + row[j]] = ((RocketSolver_float) data[j]);
        }
    }
}




/* AD tool to FORCESPRO interface */
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
                                 solver_int32_default stage,     /* stage number (0 indexed)                           */
								 solver_int32_default iteration, /* iteration number of solver                         */
								 solver_int32_default threadID   /* Id of caller thread                                */)
{
    /* AD tool input and output arrays */
    const RocketSolver_callback_float *in[4];
    RocketSolver_callback_float *out[7];
	

	/* Allocate working arrays for AD tool */
	RocketSolver_callback_float w[131];
	
    /* temporary storage for AD tool sparse output */
    RocketSolver_callback_float this_f = (RocketSolver_callback_float) 0.0;
    RocketSolver_callback_float nabla_f_sparse[13];
    RocketSolver_callback_float h_sparse[5];
    RocketSolver_callback_float nabla_h_sparse[15];
    RocketSolver_callback_float c_sparse[13];
    RocketSolver_callback_float nabla_c_sparse[120];
            
    
    /* pointers to row and column info for 
     * column compressed format used by AD tool */
    solver_int32_default nrow, ncol;
    const solver_int32_default *colind, *row;
    
    /* set inputs for AD tool */
	in[0] = x;
	in[1] = p;
	in[2] = l;
	in[3] = y;

	if ((stage >= 0) && (stage < 9))
	{
		out[0] = &this_f;
		out[1] = nabla_f_sparse;
		RocketSolver_objective_1(in, out, NULL, w, 0);
		if (nabla_f != NULL)
		{
			nrow = RocketSolver_objective_1_sparsity_out(1)[0];
			ncol = RocketSolver_objective_1_sparsity_out(1)[1];
			colind = RocketSolver_objective_1_sparsity_out(1) + 2;
			row = RocketSolver_objective_1_sparsity_out(1) + 2 + (ncol + 1);
			RocketSolver_sparse2fullcopy(nrow, ncol, colind, row, nabla_f_sparse, nabla_f);
		}

		out[0] = c_sparse;
		out[1] = nabla_c_sparse;
		RocketSolver_dynamics_1(in, out, NULL, w, 0);
		if (c != NULL)
		{
			nrow = RocketSolver_dynamics_1_sparsity_out(0)[0];
			ncol = RocketSolver_dynamics_1_sparsity_out(0)[1];
			colind = RocketSolver_dynamics_1_sparsity_out(0) + 2;
			row = RocketSolver_dynamics_1_sparsity_out(0) + 2 + (ncol + 1);
			RocketSolver_sparse2fullcopy(nrow, ncol, colind, row, c_sparse, c);
		}

		if (nabla_c != NULL)
		{
			nrow = RocketSolver_dynamics_1_sparsity_out(1)[0];
			ncol = RocketSolver_dynamics_1_sparsity_out(1)[1];
			colind = RocketSolver_dynamics_1_sparsity_out(1) + 2;
			row = RocketSolver_dynamics_1_sparsity_out(1) + 2 + (ncol + 1);
			RocketSolver_sparse2fullcopy(nrow, ncol, colind, row, nabla_c_sparse, nabla_c);
		}

		out[0] = h_sparse;
		out[1] = nabla_h_sparse;
		RocketSolver_inequalities_1(in, out, NULL, w, 0);
		if (h != NULL)
		{
			nrow = RocketSolver_inequalities_1_sparsity_out(0)[0];
			ncol = RocketSolver_inequalities_1_sparsity_out(0)[1];
			colind = RocketSolver_inequalities_1_sparsity_out(0) + 2;
			row = RocketSolver_inequalities_1_sparsity_out(0) + 2 + (ncol + 1);
			RocketSolver_sparse2fullcopy(nrow, ncol, colind, row, h_sparse, h);
		}

		if (nabla_h != NULL)
		{
			nrow = RocketSolver_inequalities_1_sparsity_out(1)[0];
			ncol = RocketSolver_inequalities_1_sparsity_out(1)[1];
			colind = RocketSolver_inequalities_1_sparsity_out(1) + 2;
			row = RocketSolver_inequalities_1_sparsity_out(1) + 2 + (ncol + 1);
			RocketSolver_sparse2fullcopy(nrow, ncol, colind, row, nabla_h_sparse, nabla_h);
		}

	}

	if ((stage >= 9) && (stage < 10))
	{
		out[0] = &this_f;
		out[1] = nabla_f_sparse;
		RocketSolver_objective_10(in, out, NULL, w, 0);
		if (nabla_f != NULL)
		{
			nrow = RocketSolver_objective_10_sparsity_out(1)[0];
			ncol = RocketSolver_objective_10_sparsity_out(1)[1];
			colind = RocketSolver_objective_10_sparsity_out(1) + 2;
			row = RocketSolver_objective_10_sparsity_out(1) + 2 + (ncol + 1);
			RocketSolver_sparse2fullcopy(nrow, ncol, colind, row, nabla_f_sparse, nabla_f);
		}

		out[0] = h_sparse;
		out[1] = nabla_h_sparse;
		RocketSolver_inequalities_10(in, out, NULL, w, 0);
		if (h != NULL)
		{
			nrow = RocketSolver_inequalities_10_sparsity_out(0)[0];
			ncol = RocketSolver_inequalities_10_sparsity_out(0)[1];
			colind = RocketSolver_inequalities_10_sparsity_out(0) + 2;
			row = RocketSolver_inequalities_10_sparsity_out(0) + 2 + (ncol + 1);
			RocketSolver_sparse2fullcopy(nrow, ncol, colind, row, h_sparse, h);
		}

		if (nabla_h != NULL)
		{
			nrow = RocketSolver_inequalities_10_sparsity_out(1)[0];
			ncol = RocketSolver_inequalities_10_sparsity_out(1)[1];
			colind = RocketSolver_inequalities_10_sparsity_out(1) + 2;
			row = RocketSolver_inequalities_10_sparsity_out(1) + 2 + (ncol + 1);
			RocketSolver_sparse2fullcopy(nrow, ncol, colind, row, nabla_h_sparse, nabla_h);
		}

	}


    
    /* add to objective */
    if (f != NULL)
    {
        *f += ((RocketSolver_float) this_f);
    }

    return 0;
}

#ifdef __cplusplus
} /* extern "C" */
#endif
