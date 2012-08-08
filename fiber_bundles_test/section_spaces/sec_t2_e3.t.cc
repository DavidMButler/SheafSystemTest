
// $RCSfile: sec_t2_e3.t.cc,v $ $Revision: 1.9 $ $Date: 2012/03/01 00:40:57 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example sec_t2_e3.t.cc
/// Test driver for class sec_t2_e3.

#include "assert_contract.h"
#include "fiber_bundles_namespace.h"
#include "sec_t2_e3.h"
#include "storage_agent.h"
#include "test_sections.impl.h"

using namespace fiber_bundle;

///
int
main(int xargc, char *xargv[])
{
  // Preconditions:

  // Body:

  string filename = filename_from_cmdline(*xargv);

  print_sec_header("Testing " + filename);

  // Create the namespace.

  fiber_bundles_namespace ns(filename);

  ns.get_read_write_access();

  size_type i_size = 2;
  size_type j_size = 2;
  size_type k_size = 2;

  // Make a base space.

  const poset_path& lbase_path =
    make_test_base_space(ns, i_size, j_size, k_size);

  // Run tests.

  // Test assignment:

  test_assignment<sec_t2_e3>(ns, lbase_path);

  // Test vd facet:

  test_sec_vd_facet<sec_t2_e3>(ns, lbase_path);

  test_sec_tp_facet<sec_t2_e3>(ns, lbase_path);

  test_sec_tensor_product<sec_e3, sec_e3, sec_t2_e3>(ns, lbase_path);

  test_sec_tensor_product<sec_t2_e3, sec_e3, sec_t3_e3>(ns, lbase_path);

  test_sec_contract<sec_t2_e3, sec_at0>(ns, lbase_path);

  // Write the namespace to standard out.

  //cout << ns << endl;

  // Write the namespace to a file.
 
  storage_agent write_agent(filename + ".hdf");

  write_agent.write_entire(ns);

  // Postconditions:

  // Exit:

  return 0;
}
