// $RCSfile: name_multimap.inst.t.cc,v $ $Revision: 1.1.2.6 $ $Date: 2012/10/17 00:37:18 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example template_instantiations/name_multimap.inst.t.cc
/// Unit test driver for template class name_multimap.

#include "name_multimap.h"
#include "scoped_index.h"
#include "test_sheaves.impl.h"

using namespace sheaf;

int
main(int xargc, char* xargv[])
{
  // Preconditions:

  // Body:

  //string filename = filename_from_cmdline(*xargv);

  bool ltest = true;

  // pod_index_type

  print_header("Begin testing name_multimap<pod_index_type>");
  ltest &= test_any_facet<name_multimap<pod_index_type> >();
  ltest &= test_name_multimap_facet<pod_index_type>();
  print_footer("End testing name_multimap<pod_index_type>");

  // scoped_index

  print_header("Begin testing name_multimap<scoped_index>");
  ltest &= test_any_facet<name_multimap<scoped_index> >();
  ltest &= test_name_multimap_facet<scoped_index>();
  print_footer("End testing name_multimap<scoped_index>");

  int lresult = ltest ? 0 : 1;

  // Postconditions:

  // Exit:

  return lresult;
}

