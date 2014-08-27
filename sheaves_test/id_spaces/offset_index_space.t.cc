
//
// Copyright (c) 2014 Limit Point Systems, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/// @example offset_index_space.t.cc
/// Test driver for offset id spaces.

#include "ComLimitPoint/sheaf/assert_contract.h"
#include "ComLimitPoint/sheaf/error_message.h"
#include "ComLimitPoint/sheaf/index_space_family.h"
#include "ComLimitPoint/sheaf/offset_index_space_handle.h"
#include "offset_index_space_iterator.h"
#include "ComLimitPoint/sheaf/offset_index_space_state.h"
#include "ComLimitPoint/sheaf/namespace_poset.h"
#include "std_iostream.h"
#include "test_index_spaces.impl.h"

using namespace std;
using namespace sheaf;

int main( int argc, char* argv[])
{
  // Preconditions:

  // Body:

  namespace_poset::initialize_id_space_prototypes();

  test_index_space_family lid_spaces;
  lid_spaces.new_primary_space(6);

  string lname("test_offset_id_space");

  offset_index_space_handle lhandle =
    offset_index_space_handle::new_space(lid_spaces, lname, 2, 4);

  pod_index_type lspace_id = lhandle.index();

  // Test handle facet.

  test_handle_facet<offset_index_space_handle>(lid_spaces, lspace_id);

  print_out_header("Testing miscellaneous handle functions");

  cout << "offset() = " << lhandle.offset() << endl;

  // Test iterator facet.

  test_iterator_facet<offset_index_space_iterator>(lid_spaces, lspace_id);

  print_out_header("Testing miscellaneous iterator functions");

  offset_index_space_iterator litr(lid_spaces, lspace_id);
  cout << "offset() = " << litr.offset() << endl;
  cout << "ct()     = " << litr.ct() << endl;

  // Test state facet.

  test_state_facet(lid_spaces, lspace_id, 0, 2);

  // Postconditions:

  // Exit:

  return 0;
}

  
