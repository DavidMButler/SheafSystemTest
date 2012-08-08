// $RCSfile: sheaves_namespace.t.cc,v $ $Revision: 1.18 $ $Date: 2012/03/01 00:41:38 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example test_posets/sheaves_namespace.t.cc
/// Test driver for class sheaves_namespace

#include "sheaves_namespace.h"
#include "assert_contract.h"
#include "std_string.h"
#include "storage_agent.h"
#include "subposet_member_iterator.h"

using namespace sheaf;

///
/// Test the constructor that takes a name.
///
void test_named_ctor(const string& xfilename)
{
  // Preconditions:


  // Body:

  // Construct an unattached namespace handle with the default constructor.

  sheaves_namespace* lns = new sheaves_namespace("test_named_ctor");

  // Output a text version to stdout

  cout << *lns << endl;

  // Write it to a file;
  // need read-write access in order to write it
  // and to delete it.

  lns->get_read_write_access();
  storage_agent sa(xfilename + ".hdf", sheaf_file::READ_WRITE);
  sa.put_member_record_buffer_ub(15);
  sa.put_dof_tuple_record_buffer_ub(15);
  sa.write_entire(*lns);

  // Delete it.

  delete lns;

  // Postconditions:


  // Exit:

  return;
}

///
/// The main routine for this test driver.
///
int main(int xargc, char *xargv[])
{
  int result = 0;

   string filename = filename_from_cmdline(*xargv);

  test_named_ctor(filename);

  return result;
}

