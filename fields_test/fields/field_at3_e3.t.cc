
// $RCSfile: field_at3_e3.t.cc,v $ $Revision: 1.9 $ $Date: 2012/03/01 00:41:03 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example field_at3_e3.t.cc
/// Test driver for class field_at3_e3.

#include "assert_contract.h"
#include "atp_space.h"
#include "base_space_member.h"
#include "fiber_bundles_namespace.h"
#include "field_at2_e3.h"
#include "field_at3_e3.h"
#include "sec_at1_space.h"
#include "sec_at2_e3.h"
#include "sec_at3_e3.h"
#include "sec_e3.h"
#include "storage_agent.h"
#include "test_fields.impl.h"

using namespace fields;

///
int
main(int xargc, char *xargv[])
{
  // Preconditions:

  // Body:

  string filename = filename_from_cmdline(*xargv);

  print_field_header("Testing " + filename);

  // Create the namespace.

  fiber_bundles_namespace lns(filename);

  lns.get_read_write_access();

  // Make a base space.

  size_type i_size = 2;
  size_type j_size = 2;
  size_type k_size = 2;

  const poset_path& lbase_path =
    make_test_base_space(lns, i_size, j_size, k_size);

  // Create the coordinates section.

  const poset_path& lcoords_path = make_test_coordinates_3d(lns, lbase_path);

  // Run tests.

  // Test assignment:

  test_field_assignment<field_at3_e3>(lns, lbase_path, lcoords_path);

  // Test vd facet:

  test_field_vd_facet<field_at3_e3>(lns, lbase_path, lcoords_path);

  // Test atp facet:

  test_field_hook_product<field_at3_e3, field_e3, field_at2_e3>
    (lns, lbase_path, lcoords_path);

  test_field_star_operator<field_at3_e3, field_at0>
    (lns, lbase_path, lcoords_path);

  test_field_star_operator<field_at0, field_at3_e3>
    (lns, lbase_path, lcoords_path);

  test_field_wedge_product<field_at2_e3, field_e3, field_at3_e3>
    (lns, lbase_path, lcoords_path);

  // Write the namespace to standard out.

  //cout << ns << endl;

  // Write the namespace to a file.

  storage_agent write_agent(filename + ".hdf");

  write_agent.write_entire(lns);

  // Postconditions:

  // Exit:

  return 0;
}