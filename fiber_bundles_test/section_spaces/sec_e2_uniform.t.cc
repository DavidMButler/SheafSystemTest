
//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

/// @example section_spaces/sec_e2_uniform.t.cc
/// Unit test for class sec_e2_uniform.

#include "sec_e2_uniform.h"

#include "assert_contract.h"
#include "std_iostream.h"
#include "test_sections.impl.h"
#include "test_utils.h"
#include "wsv_block.h"

using namespace fiber_bundle;

int
main(int argc, char* argv[])
{
  // Preconditions:

  // Body:

  print_header("Begin testing " + lsection_name);

  typedef sec_e2_uniform S;

  size_t i_size = (argc > 1) ? atoi(argv[1]) : 2;
  size_t j_size = (argc > 2) ? atoi(argv[2]) : 3;

  const string& lsection_name = S::static_class_name();

  // Create the namespace.

  fiber_bundles_namespace lns(lsection_name + ".t");
  lns.get_read_write_access();

  // Make a base space.

  const poset_path& lbase_path = make_test_base_space(lns, i_size, j_size);

  // Make the section space.

  S::host_type& lhost =
    new_host_space<sec_e2_uniform>(lns, "uniform_coordinates_host", lbase_path);
  
  // Make the section.

  wsv_block<sec_vd_dof_type> llower("-2.0 -3.0");
  wsv_block<sec_vd_dof_type> lupper("2.0 3.0");

  S lcoords(&lhost, llower, lupper, true);
  lcoords.put_name("uniform_coordinates", true, true);

  // Print the result.

  //cout << lns << endl;

  // Clean-up

  lcoords.detach_from_state();

  //============================================================================

  test_section_common_unattached<S>();
  test_section_common_attached<S>(lns, lbase_path);

  //============================================================================

  print_footer("End testing " + lsection_name);

  // Postconditions:

  // Exit:

  return 0;
}

