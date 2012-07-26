//
// $RCSfile: tools_common_binding_includes.i,v $ $Revision: 1.5 $ $Date: 2012/03/01 00:41:42 $
//
//
// Copyright (c) 2012 Limit Point Systems, Inc.
//
//
// Common Swig interface file for tools modules
//

//=============================================================================

//$$SCRIBBLE: This file contains only the part of the Swig interface which
//            is to be inserted directly into the generated code.
//            We have to break the interface into two parts because
//            of the way Swig handles "%import" versus "%include".
//            If you change this file make sure you also change
//            "tools_common_binding.i" as well.

//=============================================================================

%{
#include "vtk_poly_data_builder.h"
#include "vtk_abstract_grid_builder.h"
#include "vtk_unstructured_grid_builder.h"
%}
