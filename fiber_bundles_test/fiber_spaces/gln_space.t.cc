// $RCSfile: gln_space.t.cc,v $ $Revision: 1.7 $ $Date: 2012/07/04 16:42:08 $

// $Name: HEAD $
//
// Copyright (c) 2012 Limit Point Systems, Inc. 
//

/// @example gln_space.t.cc
/// Test driver for gln_space.

#include "gln_space.h"

#include "arg_list.h"
#include "at0.h"
#include "at0_space.h"
#include "at1_space.h"
#include "assert_contract.h"
#include "error_message.h"
#include "e2.h"
#include "fiber_bundles_namespace.h"
#include "gl2.h"
#include "schema_descriptor.h"
#include "schema_poset_member.h"
#include "std_iostream.h"
#include "storage_agent.h"
#include "vd_space.h"
#include "wsv_block.h"

using namespace fiber_bundle;

namespace
{

  void test_shallow_instantiation(fiber_bundles_namespace& xns)
  {

    // Make a scalar space, use standard schema.

    arg_list lscalar_args = at0_space::make_arg_list();
    poset_path lscalar_schema_path = at0_space::standard_schema_path();
    at0_space* lscalar_space = new at0_space(xns, 
					     "at0_space_test", 
					     lscalar_args,
					     lscalar_schema_path,
					     true);

    poset_path lscalar_path = lscalar_space->path();

    //cout << *lscalar_space << endl;  

    // Make a vector space schema; copied from e2::make_standard_schema().

    string lvector_dof_specs = "x DOUBLE false y DOUBLE false";

    schema_poset_member lvector_schema(xns,
				       "vd_space_test_schema",
				       vd_space::standard_schema_path(),
				       lvector_dof_specs,
				       true,
				       true);

    poset_path lvector_schema_path = lvector_schema.path();
    lvector_schema.detach_from_state();

    arg_list lvector_args = vd_space::make_arg_list(lscalar_path);
  
    vd_space* lvector_space = new vd_space(xns, 
					   "vd_space_test", 
					   lvector_args, 
					   lvector_schema_path, 
					   true);
  
    poset_path lvector_path = lvector_space->path();

    //cout << *lvector_space << endl;

    // Make a gln space schema; copied from gl2::make_standard_schema().

    string lgln_dof_specs = "bxx DOUBLE false ";
    lgln_dof_specs       += "bxy DOUBLE false ";
    lgln_dof_specs       += "byx DOUBLE false ";
    lgln_dof_specs       += "byy DOUBLE false";
    lgln_dof_specs       += "cxx DOUBLE false ";
    lgln_dof_specs       += "cxy DOUBLE false ";
    lgln_dof_specs       += "cyx DOUBLE false ";
    lgln_dof_specs       += "cyy DOUBLE false";


    schema_poset_member lgln_schema(xns,
				    "gln_space_test_schema",
				    gln_space::standard_schema_path(),
				    lgln_dof_specs,
				    true,
				    true);

    poset_path lgln_schema_path = lgln_schema.path();
    lgln_schema.detach_from_state();

    arg_list lgln_args = gln_space::make_arg_list(2, lscalar_path, lvector_path);
  
    gln_space* lgln_space = new gln_space(xns, 
					  "gln_space_test", 
					  lgln_args, 
					  lgln_schema_path, 
					  true);
  };
  

  void test_deep_instantiation(fiber_bundles_namespace& xns)
  {
    gln_space& lspace = xns.new_group_space<gl2>("deep_instantiation_test_gl2_space");
  };

} // End unnamed namespace.


int main(int xargc, char* xargv[])
{
  // Preconditions:

  require(xargc > 0);
  
  // Body:

  string filename = filename_from_cmdline(*xargv);
 
  fiber_bundles_namespace lns(filename);

  test_shallow_instantiation(lns);
  test_deep_instantiation(lns);
  

  //cout << lns << endl;

  lns.get_read_write_access();
  storage_agent sa(filename + ".hdf", sheaf_file::READ_WRITE, true, false);
  sa.write_entire(lns);

  // Done.

  return 0;
}

  