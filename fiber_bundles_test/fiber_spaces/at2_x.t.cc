
// $RCSfile: at2_x.t.cc,v $ $Revision: 1.10 $ $Date: 2012/03/01 00:40:41 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example at2_x.t.cc
/// Test driver for class at2.

#include "at2.h"

#include "assert_contract.h"
#include "fiber_bundles_namespace.h"
#include "std_iomanip.h"
#include "std_iostream.h"
#include "test_fibers_x.impl.h"
//#include "storage_agent.h"


using namespace fiber_bundle;

namespace
{

  void
  test_at2_volatile()
  {
    // Preconditions:

    // Body:

    //==========================================================================

    test_volatile_common<at2_lite>();

    test_volatile_tp_facet<at2_lite>();

    //==========================================================================

    //at2_lite(const row_dofs_type& xrow_dofs);

     at2_lite::row_dofs_type lrow_dofs;
     at2_lite lfiber(lrow_dofs);


     //at2_lite& operator=(const row_dofs_type& xrow_dofs);

     at2_lite lfiber_assign = lrow_dofs;

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

  //string filename = filename_from_cmdline(*xargv);

  // Create the namespace.

  //fiber_bundles_namespace lns(filename);
  //lns.get_read_write_access();

  // Run tests.

  test_at2_volatile();

  // Write the namespace to standard out.

  //cout << lns << endl;

  // Write the namespace to a file.

  //storage_agent write_agent(filename + ".hdf");
  //write_agent.write_entire(lns);

  // Postconditions:

  // Exit:

  return 0;
}
