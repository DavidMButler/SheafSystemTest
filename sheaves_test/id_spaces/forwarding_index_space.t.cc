


//
// Copyright (c) 2013 Limit Point Systems, Inc. 
//

/// @example forwarding_index_space.t.cc
/// Test driver for forwarding id spaces.

#include "assert_contract.h"
#include "arg_list.h"
#include "error_message.h"
#include "index_space_family.h"
#include "forwarding_index_space_handle.h"
#include "constant_index_space_interval.h"
#include "namespace_poset.h"
#include "std_iostream.h"
#include "std_strstream.h"
#include "test_index_spaces.impl.h"

using namespace sheaf;

int main( int argc, char* argv[])
{
  // Preconditions:

  // Body:

  namespace_poset::initialize_id_space_prototypes();

  index_space_family lid_spaces;
  lid_spaces.new_primary_state(6);

  string lname("test_forwarding_id_space");

  pod_index_type lspace_id =
    make_id_space_interval(lid_spaces,
			   "constant_index_space_interval",
			   constant_index_space_interval::make_arg_list(2),
			   2);

  // Give the id space a name.

  strstream lspace_name;
  lspace_name << "implicit_" << lspace_id;

  lid_spaces.put_name(lspace_id, lspace_name.str());

  // Test handle facet.

  test_handle_facet<forwarding_index_space_handle>(lid_spaces, lspace_id);

  // Test state facet.

  test_state_facet(lid_spaces, lspace_id, 0, 2);

  // Miscellaneous tests.

  print_out_header("Testing miscellaneous handle functions");

  // Postconditions:

  // Exit:

  return 0;
}

  
