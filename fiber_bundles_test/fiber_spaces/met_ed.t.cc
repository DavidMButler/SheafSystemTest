

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

/// @example met_ed.t.cc
/// Unit test driver for class met_ed.

#include "met_ed.h"

#include "assert_contract.h"
#include "fiber_bundles_namespace.h"
#include "met_e2.h"
#include "std_iomanip.h"
#include "std_iostream.h"
#include "stp_space.h"
#include "test_fibers.impl.h"
//#include "storage_agent.h"

using namespace fiber_bundle;

namespace
{
  void
  test_met_ed_volatile()
  {
    // Preconditions:

    // Body:

    //==========================================================================

    test_volatile_common<met_ed_lite>();

    test_volatile_class_tp_facet<met_ed_lite>();

    //==========================================================================

    // Postconditions:

    // Exit:

    return;

  }

  void
  test_met_ed_persistent()
  {
    // Preconditions:

    // Body:

    //==========================================================================

    // Create the namespace.

    fiber_bundles_namespace lns("test_namespace");
    lns.get_read_write_access();

    // Run tests.

    test_persistent_common<met_ed, met_e2>(lns);

    // Write the namespace to standard out.

    //cout << lns << endl;

    // Write the namespace to a file.

    //storage_agent write_agent("test_namespace.hdf");
    //write_agent.write_entire(lns);

    //==========================================================================

    // Postconditions:

    // Exit:

    return;

  }

} // end namespace

int
main(int xargc, char* xargv[])
{
  // Preconditions:

  // Body:

  // Run tests.

  test_met_ed_volatile();
  test_met_ed_persistent();

  // Postconditions:

  // Exit:

  return 0;
}