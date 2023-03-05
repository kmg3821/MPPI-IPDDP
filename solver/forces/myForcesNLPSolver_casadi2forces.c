/*
 * CasADi to FORCESPRO Template - missing information to be filled in by createCasadi.m 
 * (C) embotech AG, Zurich, Switzerland, 2013-2021. All rights reserved.
 *
 * This file is part of the FORCESPRO client, and carries the same license.
 */ 

#ifdef __cplusplus
extern "C" {
#endif
    
#include "myForcesNLPSolver/include/myForcesNLPSolver.h"

#ifndef NULL
#define NULL ((void *) 0)
#endif


#include "myForcesNLPSolver_casadi.h"



/* copies data from sparse matrix into a dense one */
static void sparse2fullcopy(solver_int32_default nrow, solver_int32_default ncol, const solver_int32_default *colidx, const solver_int32_default *row, myForcesNLPSolver_callback_float *data, myForcesNLPSolver_float *out)
{
    solver_int32_default i, j;
    
    /* copy data into dense matrix */
    for(i=0; i<ncol; i++)
    {
        for(j=colidx[i]; j<colidx[i+1]; j++)
        {
            out[i*nrow + row[j]] = ((myForcesNLPSolver_float) data[j]);
        }
    }
}




/* CasADi to FORCESPRO interface */
extern void myForcesNLPSolver_casadi2forces(myForcesNLPSolver_float *x,        /* primal vars                                         */
                                 myForcesNLPSolver_float *y,        /* eq. constraint multiplers                           */
                                 myForcesNLPSolver_float *l,        /* ineq. constraint multipliers                        */
                                 myForcesNLPSolver_float *p,        /* parameters                                          */
                                 myForcesNLPSolver_float *f,        /* objective function (scalar)                         */
                                 myForcesNLPSolver_float *nabla_f,  /* gradient of objective function                      */
                                 myForcesNLPSolver_float *c,        /* dynamics                                            */
                                 myForcesNLPSolver_float *nabla_c,  /* Jacobian of the dynamics (column major)             */
                                 myForcesNLPSolver_float *h,        /* inequality constraints                              */
                                 myForcesNLPSolver_float *nabla_h,  /* Jacobian of inequality constraints (column major)   */
                                 myForcesNLPSolver_float *hess,     /* Hessian (column major)                              */
                                 solver_int32_default stage,     /* stage number (0 indexed)                           */
								 solver_int32_default iteration, /* iteration number of solver                         */
								 solver_int32_default threadID   /* Id of caller thread                                */)
{
    /* CasADi input and output arrays */
    const myForcesNLPSolver_callback_float *in[4];
    myForcesNLPSolver_callback_float *out[7];
	

	/* Allocate working arrays for CasADi */
	myForcesNLPSolver_callback_float w[12];
	
    /* temporary storage for CasADi sparse output */
    myForcesNLPSolver_callback_float this_f;
    myForcesNLPSolver_callback_float nabla_f_sparse[4];
    myForcesNLPSolver_callback_float h_sparse[1];
    myForcesNLPSolver_callback_float nabla_h_sparse[2];
    myForcesNLPSolver_callback_float c_sparse[3];
    myForcesNLPSolver_callback_float nabla_c_sparse[10];
            
    
    /* pointers to row and column info for 
     * column compressed format used by CasADi */
    solver_int32_default nrow, ncol;
    const solver_int32_default *colind, *row;
    
    /* set inputs for CasADi */
	in[0] = x;
	in[1] = p;
	in[2] = l;
	in[3] = y;

	if ((stage >= 0) && (stage < 50))
	{
		out[0] = &this_f;
		out[1] = nabla_f_sparse;
		myForcesNLPSolver_objective_1(in, out, NULL, w, 0);
		if (nabla_f != NULL)
		{
			nrow = myForcesNLPSolver_objective_1_sparsity_out(1)[0];
			ncol = myForcesNLPSolver_objective_1_sparsity_out(1)[1];
			colind = myForcesNLPSolver_objective_1_sparsity_out(1) + 2;
			row = myForcesNLPSolver_objective_1_sparsity_out(1) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, nabla_f_sparse, nabla_f);
		}

		out[0] = c_sparse;
		out[1] = nabla_c_sparse;
		myForcesNLPSolver_dynamics_1(in, out, NULL, w, 0);
		if (c != NULL)
		{
			nrow = myForcesNLPSolver_dynamics_1_sparsity_out(0)[0];
			ncol = myForcesNLPSolver_dynamics_1_sparsity_out(0)[1];
			colind = myForcesNLPSolver_dynamics_1_sparsity_out(0) + 2;
			row = myForcesNLPSolver_dynamics_1_sparsity_out(0) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, c_sparse, c);
		}

		if (nabla_c != NULL)
		{
			nrow = myForcesNLPSolver_dynamics_1_sparsity_out(1)[0];
			ncol = myForcesNLPSolver_dynamics_1_sparsity_out(1)[1];
			colind = myForcesNLPSolver_dynamics_1_sparsity_out(1) + 2;
			row = myForcesNLPSolver_dynamics_1_sparsity_out(1) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, nabla_c_sparse, nabla_c);
		}

		out[0] = h_sparse;
		out[1] = nabla_h_sparse;
		myForcesNLPSolver_inequalities_1(in, out, NULL, w, 0);
		if (h != NULL)
		{
			nrow = myForcesNLPSolver_inequalities_1_sparsity_out(0)[0];
			ncol = myForcesNLPSolver_inequalities_1_sparsity_out(0)[1];
			colind = myForcesNLPSolver_inequalities_1_sparsity_out(0) + 2;
			row = myForcesNLPSolver_inequalities_1_sparsity_out(0) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, h_sparse, h);
		}

		if (nabla_h != NULL)
		{
			nrow = myForcesNLPSolver_inequalities_1_sparsity_out(1)[0];
			ncol = myForcesNLPSolver_inequalities_1_sparsity_out(1)[1];
			colind = myForcesNLPSolver_inequalities_1_sparsity_out(1) + 2;
			row = myForcesNLPSolver_inequalities_1_sparsity_out(1) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, nabla_h_sparse, nabla_h);
		}

	}

	if ((stage >= 50) && (stage < 51))
	{
		out[0] = &this_f;
		out[1] = nabla_f_sparse;
		myForcesNLPSolver_objective_51(in, out, NULL, w, 0);
		if (nabla_f != NULL)
		{
			nrow = myForcesNLPSolver_objective_51_sparsity_out(1)[0];
			ncol = myForcesNLPSolver_objective_51_sparsity_out(1)[1];
			colind = myForcesNLPSolver_objective_51_sparsity_out(1) + 2;
			row = myForcesNLPSolver_objective_51_sparsity_out(1) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, nabla_f_sparse, nabla_f);
		}

	}


    
    /* add to objective */
    if (f != NULL)
    {
        *f += ((myForcesNLPSolver_float) this_f);
    }
}

#ifdef __cplusplus
} /* extern "C" */
#endif
