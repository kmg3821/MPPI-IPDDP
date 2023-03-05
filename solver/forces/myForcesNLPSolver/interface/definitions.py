import numpy
import ctypes

name = "myForcesNLPSolver"
requires_callback = True
lib = "lib/myForcesNLPSolver.dll"
lib_static = "lib/myForcesNLPSolver_static.lib"
c_header = "include/myForcesNLPSolver.h"
nstages = 52

# Parameter             | Type    | Scalar type      | Ctypes type    | Numpy type   | Shape     | Len
params = \
[("lb"                  , "dense" , ""               , ctypes.c_double, numpy.float64, (100,   1),  100),
 ("ub"                  , "dense" , ""               , ctypes.c_double, numpy.float64, (100,   1),  100),
 ("xinit"               , "dense" , ""               , ctypes.c_double, numpy.float64, (  3,   1),    3),
 ("xfinal"              , "dense" , ""               , ctypes.c_double, numpy.float64, (  3,   1),    3),
 ("x0"                  , "dense" , ""               , ctypes.c_double, numpy.float64, (253,   1),  253),
 ("all_parameters"      , "dense" , ""               , ctypes.c_double, numpy.float64, (204,   1),  204)]

# Output                | Type    | Scalar type      | Ctypes type    | Numpy type   | Shape     | Len
outputs = \
[("MVopt"               , ""      , ""               , ctypes.c_double, numpy.float64,     (  2,),  100),
 ("Xopt"                , ""      , ""               , ctypes.c_double, numpy.float64,     (  3,),  153),
 ("z"                   , ""      , ""               , ctypes.c_double, numpy.float64,     (253,),  253)]

# Info Struct Fields
info = \
[('it', ctypes.c_int),
('it2opt', ctypes.c_int),
('res_eq', ctypes.c_double),
('res_ineq', ctypes.c_double),
('rsnorm', ctypes.c_double),
('rcompnorm', ctypes.c_double),
('pobj', ctypes.c_double),
('dobj', ctypes.c_double),
('dgap', ctypes.c_double),
('rdgap', ctypes.c_double),
('mu', ctypes.c_double),
('mu_aff', ctypes.c_double),
('sigma', ctypes.c_double),
('lsit_aff', ctypes.c_int),
('lsit_cc', ctypes.c_int),
('step_aff', ctypes.c_double),
('step_cc', ctypes.c_double),
('solvetime', ctypes.c_double),
('fevalstime', ctypes.c_double)
]

# Dynamics dimensions
#   nvar    |   neq   |   dimh    |   dimp    |   diml    |   dimu    |   dimhl   |   dimhu    
dynamics_dims = [
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(5, 3, 1, 4, 2, 2, 0, 1), 
	(3, 3, 0, 4, 0, 0, 0, 0), 
	(0, 3, 0, 0, 0, 0, 0, 0)
]