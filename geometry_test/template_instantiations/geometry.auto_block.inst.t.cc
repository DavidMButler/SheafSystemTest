// $RCSfile: geometry_auto_block.inst.t.cc,v $ $Revision: 1.1.2.3 $ $Date: 2012/10/24 02:00:34 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example
/// Unit test driver for template class auto_block.

#include "auto_block.h"
#include "block.h"
#include "geometry.h"

#include "d_bounding_box.h"
#include "db0_point_locator.h"
#include "d_tree_point_locator_node.h"
#include "test_utils.h"
#include "test_sheaves.impl.h"

#include "kd_plane.h"
#include "kd_bounding_box.h"

#include "std_slist.h"
#include "std_utility.h"

using namespace geometry;

int
main(int xargc, char* xargv[])
{
  // Preconditions:

  // Body:

  bool ltest = true;

  //============================================================================

  // kd_plane:

  print_header("Begin testing auto_block<kd_plane>");
  ltest &= test_auto_block_facet_un<kd_plane>();
  ltest &= test_auto_block_facet_equal_un<kd_plane>();
  ltest &= test_auto_block_facet_insertion_un<kd_plane>();
  ltest &= test_auto_block_facet_deep_size_un<kd_plane>();
  print_footer("End testing auto_block<kd_plane>");

  // kd_bounding_box:

  print_header("Begin testing auto_block<kd_bounding_box>");
  ltest &= test_auto_block_facet_un<kd_bounding_box>();
  ltest &= test_auto_block_facet_equal_un<kd_bounding_box>();
  ltest &= test_auto_block_facet_insertion_un<kd_bounding_box>();
  ltest &= test_auto_block_facet_deep_size_un<kd_bounding_box>();
  print_footer("End testing auto_block<kd_bounding_box>");

  //============================================================================

  // d_bounding_box<1, 0> 

  print_header("Begin testing auto_block<d_bounding_box<1, 0> >");
  ltest &= test_auto_block_facet_un<d_bounding_box<1, 0> >();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<1, 0> >();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<1, 0> >();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<1, 0> >();
  print_footer("End testing auto_block<d_bounding_box<1, 0> >");

  // d_bounding_box<1, 1> 

  print_header("Begin testing auto_block<d_bounding_box<1, 1> >");
  ltest &= test_auto_block_facet_un<d_bounding_box<1, 1> >();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<1, 1> >();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<1, 1> >();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<1, 1> >();
  print_footer("End testing auto_block<d_bounding_box<1, 1> >");

  // d_bounding_box<2, 0> 

  print_header("Begin testing auto_block<d_bounding_box<2, 0> >");
  ltest &= test_auto_block_facet_un<d_bounding_box<2, 0> >();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<2, 0> >();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<2, 0> >();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<2, 0> >();
  print_footer("End testing auto_block<d_bounding_box<2, 0> >");

  // d_bounding_box<2, 2> 

  print_header("Begin testing auto_block<d_bounding_box<2, 2> >");
  ltest &= test_auto_block_facet_un<d_bounding_box<2, 2> >();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<2, 2> >();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<2, 2> >();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<2, 2> >();
  print_footer("End testing auto_block<d_bounding_box<2, 2> >");

  // d_bounding_box<3, 0> 

  print_header("Begin testing auto_block<d_bounding_box<3, 0> >");
  ltest &= test_auto_block_facet_un<d_bounding_box<3, 0> >();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<3, 0> >();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<3, 0> >();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<3, 0> >();
  print_footer("End testing auto_block<d_bounding_box<3, 0> >");

  // d_bounding_box<3, 1> 

  print_header("Begin testing auto_block<d_bounding_box<3, 1> >");
  ltest &= test_auto_block_facet_un<d_bounding_box<3, 1> >();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<3, 1> >();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<3, 1> >();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<3, 1> >();
  print_footer("End testing auto_block<d_bounding_box<3, 1> >");

  // d_bounding_box<3, 2> 

  print_header("Begin testing auto_block<d_bounding_box<3, 2> >");
  ltest &= test_auto_block_facet_un<d_bounding_box<3, 2> >();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<3, 2> >();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<3, 2> >();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<3, 2> >();
  print_footer("End testing auto_block<d_bounding_box<3, 2> >");

  // d_bounding_box<3, 3> 

  print_header("Begin testing auto_block<d_bounding_box<3, 3> >");
  ltest &= test_auto_block_facet_un<d_bounding_box<3, 3> >();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<3, 3> >();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<3, 3> >();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<3, 3> >();
  print_footer("End testing auto_block<d_bounding_box<3, 3> >");

  // d_bounding_box<4, 4> 

  print_header("Begin testing auto_block<d_bounding_box<4, 4> >");
  ltest &= test_auto_block_facet_un<d_bounding_box<4, 4> >();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<4, 4> >();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<4, 4> >();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<4, 4> >();
  print_footer("End testing auto_block<d_bounding_box<4, 4> >");

  //============================================================================

  // d_bounding_box<1, 0> const*

  print_header("Begin testing auto_block<d_bounding_box<1, 0> const*>");
  ltest &= test_auto_block_facet_un<d_bounding_box<1, 0> const*>();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<1, 0> const*>();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<1, 0> const*>();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<1, 0> const*>();
  print_footer("End testing auto_block<d_bounding_box<1, 0> const*>");

  // d_bounding_box<1, 1> const*

  print_header("Begin testing auto_block<d_bounding_box<1, 1> const*>");
  ltest &= test_auto_block_facet_un<d_bounding_box<1, 1> const*>();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<1, 1> const*>();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<1, 1> const*>();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<1, 1> const*>();
  print_footer("End testing auto_block<d_bounding_box<1, 1> const*>");

  // d_bounding_box<2, 0> const* 

  print_header("Begin testing auto_block<d_bounding_box<2, 0> const*>");
  ltest &= test_auto_block_facet_un<d_bounding_box<2, 0> const*>();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<2, 0> const*>();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<2, 0> const*>();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<2, 0> const*>();
  print_footer("End testing auto_block<d_bounding_box<2, 0> const*>");

  // d_bounding_box<2, 2> const* 

  print_header("Begin testing auto_block<d_bounding_box<2, 2> const*>");
  ltest &= test_auto_block_facet_un<d_bounding_box<2, 2> const*>();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<2, 2> const*>();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<2, 2> const*>();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<2, 2> const*>();
  print_footer("End testing auto_block<d_bounding_box<2, 2> const*>");

  // d_bounding_box<3, 0> const* 

  print_header("Begin testing auto_block<d_bounding_box<3, 0> const*>");
  ltest &= test_auto_block_facet_un<d_bounding_box<3, 0> const*>();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<3, 0> const*>();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<3, 0> const*>();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<3, 0> const*>();
  print_footer("End testing auto_block<d_bounding_box<3, 0> const*>");

  // d_bounding_box<3, 1> const* 

  print_header("Begin testing auto_block<d_bounding_box<3, 1> const*>");
  ltest &= test_auto_block_facet_un<d_bounding_box<3, 1> const*>();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<3, 1> const*>();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<3, 1> const*>();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<3, 1> const*>();
  print_footer("End testing auto_block<d_bounding_box<3, 1> const*>");

  // d_bounding_box<3, 2> const* 

  print_header("Begin testing auto_block<d_bounding_box<3, 2> const*>");
  ltest &= test_auto_block_facet_un<d_bounding_box<3, 2> const*>();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<3, 2> const*>();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<3, 2> const*>();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<3, 2> const*>();
  print_footer("End testing auto_block<d_bounding_box<3, 2> const*>");

  // d_bounding_box<3, 3> const* 

  print_header("Begin testing auto_block<d_bounding_box<3, 3> const*>");
  ltest &= test_auto_block_facet_un<d_bounding_box<3, 3> const*>();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<3, 3> const*>();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<3, 3> const*>();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<3, 3> const*>();
  print_footer("End testing auto_block<d_bounding_box<3, 3> const*>");

  // d_bounding_box<4, 4> const* 

  print_header("Begin testing auto_block<d_bounding_box<4, 4> const*>");
  ltest &= test_auto_block_facet_un<d_bounding_box<4, 4> const*>();
  //ltest &= test_auto_block_facet_equal_un<d_bounding_box<4, 4> const*>();
  ltest &= test_auto_block_facet_insertion_un<d_bounding_box<4, 4> const*>();
  //ltest &= test_auto_block_facet_deep_size_un<d_bounding_box<4, 4> const*>();
  print_footer("End testing auto_block<d_bounding_box<4, 4> const*>");


  //============================================================================

  // block<d_bounding_box<1, 0> > 

  print_header("Begin testing auto_block<block<d_bounding_box<1, 0> > >");
  ltest &= test_auto_block_facet_un<block<d_bounding_box<1, 0> > >();
  ltest &= test_auto_block_facet_equal_un<block<d_bounding_box<1, 0> > >();
  ltest &= test_auto_block_facet_insertion_un<block<d_bounding_box<1, 0> > >();
  //ltest &= test_auto_block_facet_deep_size_un<block<d_bounding_box<1, 0> > >();
  print_footer("End testing auto_block<block<d_bounding_box<1, 0> > >");
 
  // block<d_bounding_box<1, 1> >

  print_header("Begin testing auto_block<block<d_bounding_box<1, 1> > >");
  ltest &= test_auto_block_facet_un<block<d_bounding_box<1, 1> > >();
  ltest &= test_auto_block_facet_equal_un<block<d_bounding_box<1, 1> > >();
  ltest &= test_auto_block_facet_insertion_un<block<d_bounding_box<1, 1> > >();
  //ltest &= test_auto_block_facet_deep_size_un<block<d_bounding_box<1, 1> > >();
  print_footer("End testing auto_block<block<d_bounding_box<1, 1> > >");

  // block<d_bounding_box<2, 0> > 

  print_header("Begin testing auto_block<block<d_bounding_box<2, 0> > >");
  ltest &= test_auto_block_facet_un<block<d_bounding_box<2, 0> > >();
  ltest &= test_auto_block_facet_equal_un<block<d_bounding_box<2, 0> > >();
  ltest &= test_auto_block_facet_insertion_un<block<d_bounding_box<2, 0> > >();
  //ltest &= test_auto_block_facet_deep_size_un<block<d_bounding_box<2, 0> > >();
  print_footer("End testing auto_block<block<d_bounding_box<2, 0> > >");

  // block<d_bounding_box<2, 2> > 

  print_header("Begin testing auto_block<block<d_bounding_box<2, 2> > >");
  ltest &= test_auto_block_facet_un<block<d_bounding_box<2, 2> > >();
  ltest &= test_auto_block_facet_equal_un<block<d_bounding_box<2, 2> > >();
  ltest &= test_auto_block_facet_insertion_un<block<d_bounding_box<2, 2> > >();
  //ltest &= test_auto_block_facet_deep_size_un<block<d_bounding_box<2, 2> > >();
  print_footer("End testing auto_block<block<d_bounding_box<2, 2> > >");

  // block<d_bounding_box<3, 0> > 

  print_header("Begin testing auto_block<block<d_bounding_box<3, 0> > >");
  ltest &= test_auto_block_facet_un<block<d_bounding_box<3, 0> > >();
  ltest &= test_auto_block_facet_equal_un<block<d_bounding_box<3, 0> > >();
  ltest &= test_auto_block_facet_insertion_un<block<d_bounding_box<3, 0> > >();
  //ltest &= test_auto_block_facet_deep_size_un<block<d_bounding_box<3, 0> > >();
  print_footer("End testing auto_block<block<d_bounding_box<3, 0> > >");

  // block<d_bounding_box<3, 1> > 

  print_header("Begin testing auto_block<block<d_bounding_box<3, 1> > >");
  ltest &= test_auto_block_facet_un<block<d_bounding_box<3, 1> > >();
  ltest &= test_auto_block_facet_equal_un<block<d_bounding_box<3, 1> > >();
  ltest &= test_auto_block_facet_insertion_un<block<d_bounding_box<3, 1> > >();
  //ltest &= test_auto_block_facet_deep_size_un<block<d_bounding_box<3, 1> > >();
  print_footer("End testing auto_block<block<d_bounding_box<3, 1> > >");

  // block<d_bounding_box<3, 2> > 

  print_header("Begin testing auto_block<block<d_bounding_box<3, 2> > >");
  ltest &= test_auto_block_facet_un<block<d_bounding_box<3, 2> > >();
  ltest &= test_auto_block_facet_equal_un<block<d_bounding_box<3, 2> > >();
  ltest &= test_auto_block_facet_insertion_un<block<d_bounding_box<3, 2> > >();
  //ltest &= test_auto_block_facet_deep_size_un<block<d_bounding_box<3, 2> > >();
  print_footer("End testing auto_block<block<d_bounding_box<3, 2> > >");

  // block<d_bounding_box<3, 3> > 

  print_header("Begin testing auto_block<block<d_bounding_box<3, 3> > >");
  ltest &= test_auto_block_facet_un<block<d_bounding_box<3, 3> > >();
  ltest &= test_auto_block_facet_equal_un<block<d_bounding_box<3, 3> > >();
  ltest &= test_auto_block_facet_insertion_un<block<d_bounding_box<3, 3> > >();
  //ltest &= test_auto_block_facet_deep_size_un<block<d_bounding_box<3, 3> > >();
  print_footer("End testing auto_block<block<d_bounding_box<3, 3> > >");

  // block<d_bounding_box<4, 4> > 

  print_header("Begin testing auto_block<block<d_bounding_box<4, 4> > >");
  ltest &= test_auto_block_facet_un<block<d_bounding_box<4, 4> > >();
  ltest &= test_auto_block_facet_equal_un<block<d_bounding_box<4, 4> > >();
  ltest &= test_auto_block_facet_insertion_un<block<d_bounding_box<4, 4> > >();
  //ltest &= test_auto_block_facet_deep_size_un<block<d_bounding_box<4, 4> > >();
  print_footer("End testing auto_block<block<d_bounding_box<4, 4> > >");

  //============================================================================

  // slist<d_bounding_box<1, 0> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<1, 0> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<1, 0> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<1, 0> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<1, 0> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<1, 0> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<1, 0> const*> >");
 
  // slist<d_bounding_box<1, 1> const*>

  print_header("Begin testing auto_block<slist<d_bounding_box<1, 1> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<1, 1> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<1, 1> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<1, 1> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<1, 1> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<1, 1> const*> >");

  // slist<d_bounding_box<2, 0> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<2, 0> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<2, 0> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<2, 0> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<2, 0> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<2, 0> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<2, 0> const*> >");

  // slist<d_bounding_box<2, 2> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<2, 2> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<2, 2> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<2, 2> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<2, 2> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<2, 2> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<2, 2> const*> >");

  // slist<d_bounding_box<3, 0> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<3, 0> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<3, 0> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<3, 0> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<3, 0> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<3, 0> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<3, 0> const*> >");

  // slist<d_bounding_box<3, 1> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<3, 1> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<3, 1> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<3, 1> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<3, 1> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<3, 1> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<3, 1> const*> >");

  // slist<d_bounding_box<3, 2> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<3, 2> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<3, 2> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<3, 2> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<3, 2> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<3, 2> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<3, 2> const*> >");

  // slist<d_bounding_box<3, 3> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<3, 3> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<3, 3> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<3, 3> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<3, 3> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<3, 3> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<3, 3> const*> >");

  // slist<d_bounding_box<4, 4> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<4, 4> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<4, 4> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<4, 4> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<4, 4> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<4, 4> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<4, 4> const*> >");


  //============================================================================

  // slist<d_bounding_box<1, 0>*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<1, 0>*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<1, 0>*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<1, 0>*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<1, 0>*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<1, 0>*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<1, 0>*> >");
 
  // slist<d_bounding_box<1, 1>*>

  print_header("Begin testing auto_block<slist<d_bounding_box<1, 1>*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<1, 1>*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<1, 1>*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<1, 1>*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<1, 1>*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<1, 1>*> >");

  // slist<d_bounding_box<2, 0>*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<2, 0>*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<2, 0>*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<2, 0>*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<2, 0>*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<2, 0>*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<2, 0>*> >");

  // slist<d_bounding_box<2, 2>*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<2, 2>*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<2, 2>*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<2, 2>*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<2, 2>*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<2, 2>*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<2, 2>*> >");

  // slist<d_bounding_box<3, 0>*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<3, 0>*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<3, 0>*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<3, 0>*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<3, 0>*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<3, 0>*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<3, 0>*> >");

  // slist<d_bounding_box<3, 1>*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<3, 1>*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<3, 1>*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<3, 1>*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<3, 1>*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<3, 1>*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<3, 1>*> >");

  // slist<d_bounding_box<3, 2>*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<3, 2>*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<3, 2>*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<3, 2>*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<3, 2>*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<3, 2>*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<3, 2>*> >");

  // slist<d_bounding_box<3, 3>*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<3, 3>*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<3, 3>*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<3, 3>*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<3, 3>*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<3, 3>*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<3, 3>*> >");

  // slist<d_bounding_box<4, 4>*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<4, 4>*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<4, 4>*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<4, 4>*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<4, 4>*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<4, 4>*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<4, 4>*> >");

  //============================================================================

  // slist<d_bounding_box<1, 0> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<1, 0> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<1, 0> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<1, 0> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<1, 0> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<1, 0> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<1, 0> const*> >");
 
  // slist<d_bounding_box<1, 1> const*>

  print_header("Begin testing auto_block<slist<d_bounding_box<1, 1> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<1, 1> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<1, 1> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<1, 1> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<1, 1> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<1, 1> const*> >");

  // slist<d_bounding_box<2, 0> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<2, 0> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<2, 0> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<2, 0> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<2, 0> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<2, 0> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<2, 0> const*> >");

  // slist<d_bounding_box<2, 2> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<2, 2> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<2, 2> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<2, 2> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<2, 2> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<2, 2> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<2, 2> const*> >");

  // slist<d_bounding_box<3, 0> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<3, 0> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<3, 0> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<3, 0> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<3, 0> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<3, 0> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<3, 0> const*> >");

  // slist<d_bounding_box<3, 1> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<3, 1> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<3, 1> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<3, 1> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<3, 1> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<3, 1> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<3, 1> const*> >");

  // slist<d_bounding_box<3, 2> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<3, 2> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<3, 2> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<3, 2> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<3, 2> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<3, 2> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<3, 2> const*> >");

  // slist<d_bounding_box<3, 3> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<3, 3> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<3, 3> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<3, 3> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<3, 3> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<3, 3> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<3, 3> const*> >");

  // slist<d_bounding_box<4, 4> const*> 

  print_header("Begin testing auto_block<slist<d_bounding_box<4, 4> const*> >");
  ltest &= test_auto_block_facet_un<slist<d_bounding_box<4, 4> const*> >();
  //ltest &= test_auto_block_facet_equal_un<slist<d_bounding_box<4, 4> const*> >();
  //ltest &= test_auto_block_facet_insertion_un<slist<d_bounding_box<4, 4> const*> >();
  //ltest &= test_auto_block_facet_deep_size_un<slist<d_bounding_box<4, 4> const*> >();
  print_footer("End testing auto_block<slist<d_bounding_box<4, 4> const*> >");

  //============================================================================

  //$$SCRIBBLE: db0_point_locator<DC>::vertex_type> is protected.

  // slist<geometry::db0_point_locator<1>::vertex_type>

//   print_header("Begin testing auto_block<slist<db0_point_locator<1>::vertex_type> >");
//   //ltest &= test_auto_block_facet_un<slist<db0_point_locator<1>::vertex_type> >();
//   //ltest &= test_auto_block_facet_equal_un<slist<db0_point_locator<1>::vertex_type> >();
//   //ltest &= test_auto_block_facet_insertion_un<slist<db0_point_locator<1>::vertex_type> >();
//   //ltest &= test_auto_block_facet_deep_size_un<slist<db0_point_locator<1>::vertex_type >();
//   print_footer("End testing auto_block<slist<db0_point_locator<1>::vertex_type> >");

//   // slist<geometry::db0_point_locator<2>::vertex_type>

//   print_header("Begin testing auto_block<slist<db0_point_locator<2>::vertex_type> >");
//   //ltest &= test_auto_block_facet_un<slist<db0_point_locator<2>::vertex_type> >();
//   //ltest &= test_auto_block_facet_equal_un<slist<db0_point_locator<2>::vertex_type> >();
//   //ltest &= test_auto_block_facet_insertion_un<slist<db0_point_locator<2>::vertex_type> >();
//   //ltest &= test_auto_block_facet_deep_size_un<slist<db0_point_locator<2>::vertex_type >();
//   print_footer("End testing auto_block<slist<db0_point_locator<2>::vertex_type> >");

//   // slist<geometry::db0_point_locator<3>::vertex_type>

//   print_header("Begin testing auto_block<slist<db0_point_locator<3>::vertex_type> >");
//   //ltest &= test_auto_block_facet_un<slist<db0_point_locator<3>::vertex_type> >();
//   //ltest &= test_auto_block_facet_equal_un<slist<db0_point_locator<3>::vertex_type> >();
//   //ltest &= test_auto_block_facet_insertion_un<slist<db0_point_locator<3>::vertex_type> >();
//   //ltest &= test_auto_block_facet_deep_size_un<slist<db0_point_locator<3>::vertex_type >();
//   print_footer("End testing auto_block<slist<db0_point_locator<3>::vertex_type> >");

  //============================================================================

  // d_tree_point_locator_node<1, 1>

  print_header("Begin testing auto_block<d_tree_point_locator_node<1, 1> >");
  ltest &= test_auto_block_facet_un<d_tree_point_locator_node<1, 1> >();
  ltest &= test_auto_block_facet_equal_un<d_tree_point_locator_node<1, 1> >();
  ltest &= test_auto_block_facet_insertion_un<d_tree_point_locator_node<1, 1> >();
  //ltest &= test_auto_block_facet_deep_size_un<d_tree_point_locator_node<1, 1> >();
  print_footer("End testing auto_block<d_tree_point_locator_node<1, 1> >");

  // d_tree_point_locator_node<2, 2>

  print_header("Begin testing auto_block<d_tree_point_locator_node<2, 2> >");
  ltest &= test_auto_block_facet_un<d_tree_point_locator_node<2, 2> >();
  ltest &= test_auto_block_facet_equal_un<d_tree_point_locator_node<2, 2> >();
  ltest &= test_auto_block_facet_insertion_un<d_tree_point_locator_node<2, 2> >();
  //ltest &= test_auto_block_facet_deep_size_un<d_tree_point_locator_node<2, 2> >();
  print_footer("End testing auto_block<d_tree_point_locator_node<2, 2> >");

  // d_tree_point_locator_node<3, 3>

  print_header("Begin testing auto_block<d_tree_point_locator_node<3, 3> >");
  ltest &= test_auto_block_facet_un<d_tree_point_locator_node<3, 3> >();
  ltest &= test_auto_block_facet_equal_un<d_tree_point_locator_node<3, 3> >();
  ltest &= test_auto_block_facet_insertion_un<d_tree_point_locator_node<3, 3> >();
  //ltest &= test_auto_block_facet_deep_size_un<d_tree_point_locator_node<3, 3> >();
  print_footer("End testing auto_block<d_tree_point_locator_node<3, 3> >");

//   // d_tree_point_locator_node<4, 4> not instantiated

//   print_header("Begin testing auto_block<d_tree_point_locator_node<4, 4> >");
//   ltest &= test_auto_block_facet_un<d_tree_point_locator_node<4, 4> >();
//   ltest &= test_auto_block_facet_equal_un<d_tree_point_locator_node<4, 4> >();
//   ltest &= test_auto_block_facet_insertion_un<d_tree_point_locator_node<4, 4> >();
//   //ltest &= test_auto_block_facet_deep_size_un<d_tree_point_locator_node<4, 4> >();
//   print_footer("End testing auto_block<d_tree_point_locator_node<4, 4> >");

  //============================================================================


  int lresult = ltest ? 0 : 1;

  // Postconditions:

  // Exit:

  return lresult;
}