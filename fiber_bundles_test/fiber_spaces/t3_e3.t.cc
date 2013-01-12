

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

/// @example t3_e3.t.cc
/// Test driver for class t3_e3.

#include "assert_contract.h"
#include "at0_space.h"
#include "at1_space.h"
#include "e3.h"
#include "storage_agent.h"
#include "stp_space.h"
#include "t3_e3.h"
#include "test_fibers.impl.h"

using namespace fiber_bundle;

int
main(int xargc, char* xargv[])
{
  // Preconditions:

  // Body:

  string filename = filename_from_cmdline(*xargv);

  // Create the namespace.

  fiber_bundles_namespace ns(filename);
  ns.get_read_write_access();

  // Run tests.

  test_persistent_tensor_type<t3_e3>(ns);

  test_volatile_type<t3_e3>();

  test_tensor_conversions<t3_e3>(ns);

  // Test vd facet:

  test_tensor_vd_facet<t3_e3>(ns);

  // Test tp facet:

  test_tp_facet<t3_e3>(ns);

  test_tensor< t2_e3, e3, t3_e3>(ns);
  test_tensor<at2_e3, e3, t3_e3>(ns);
  test_tensor<st2_e3, e3, t3_e3>(ns);
  test_tensor<met_e3, e3, t3_e3>(ns);

  test_contract<t3_e3, e3>(ns);

  // Write the namespace to standard out.

  //cout << ns << endl;

  // Write the namespace to a file.

  storage_agent write_agent(filename + ".hdf");
  write_agent.write_entire(ns);

  // Postconditions:

  // Exit:

  return 0;
}
