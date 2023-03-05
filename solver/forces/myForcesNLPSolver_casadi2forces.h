#ifdef __cplusplus
extern "C" {
#endif
    
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
										 solver_int32_default stage,     /* stage number (0 indexed)                            */
										 solver_int32_default iteration, /* iteration number of solver                          */
										 solver_int32_default threadID  /* Id of caller thread */);

#ifdef __cplusplus
} /* extern "C" */
#endif
