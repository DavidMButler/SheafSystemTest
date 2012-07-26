// $RCSfile: refining_section_pusher_2d.t.cc,v $ $Revision: 1.5 $ $Date: 2012/03/01 00:41:12 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example refining_section_pusher_2d.t.cc

/// @file
/// Test driver for refining_section_pusher.

#include "assert_contract.h"
#include "base_space_member.h"
#include "fiber_bundles_namespace.h"
#include "field_factory.h"
#include "fields.h"
#include "sec_ed_invertible.h"
#include "section_dof_iterator.h"
#include "section_pusher.h"
#include "std_iostream.h"
#include "storage_agent.h"
#include "field_vd.h"
#include "wsv_block.h"
#include "refining_section_pusher.h"

//#define DIAGNOSTIC_OUTPUT 1

using namespace fields;
using namespace fields;

namespace
{

///
/// Step function.
///
void
step_fcn(block<sec_vd_value_type>& xglobal_coords,
         block<sec_vd_dof_type>& xproperty_dofs)
{
  // Preconditions:

  require(xglobal_coords.ct() >= 1);
  require(xproperty_dofs.ct() == 1);

  // Body:

  // Not exactly a step, really a ramp.
  // Test case centers coarse mesh zone on
  // origin of coordinates, so make sure
  // test function not symmetric (or antisymmetric).
  // Otherwise, the error at the center may
  // be unexpectedly small.

  sec_vd_value_type x = xglobal_coords[0];

  if(x < -0.5)
  {
    xproperty_dofs[0] = -1.0;
  }
  else if(x > 0.0)
  {
    xproperty_dofs[0] = 1.0;
  }
  else
  {
    xproperty_dofs[0] = 4.0*x + 1.0;
  }


  // Postconditions:

  // Exit:

  return;
}

///
/// Test fine to coarse push with refinement.
///
void test_fine_to_coarse_with_refinement(bool xuse_quads)
{
  fiber_bundles_namespace lns("refining_section_pusher_2d.t");
  lns.get_read_write_access();

  // An 8x8 element fine mesh on with xmin = -2.0 and xmax = 2.0,
  // with a step in it.

  wsv_block<sec_vd_value_type> xlower("-2.0 -2.0");
  wsv_block<sec_vd_value_type> xupper("2.0 2.0");

  field_vd* fine =
    field_factory::new_scalar_field_2d_unstructured(lns,
        "fine",
        8,
        8,
        xuse_quads,
        xlower,
        xupper,
        step_fcn);

  // A 3x3 element coarse mesh with the same bounds and property == 0.

  field_vd* coarse =
    field_factory::new_scalar_field_2d_unstructured(lns,
        "coarse",
        3,
        3,
        xuse_quads,
        xlower,
        xupper,
        field_factory::zero);

  coarse->print_property_dofs(cout,
                              field_factory::zero,
                              "Before pushing unstructured fine >>"
                              " unstructured coarse:",
                              true,
                              true);

  // Push the "fine" field to the "coarse" field and
  // print the result compared to the exact value.

  refining_section_pusher lpusher(*coarse->base_space().host(),
                                  "edge_centered_refiner_family",
                                  "zone_centered_error_bound_refinement_policy",
                                  true);

  lpusher.push(*fine, *coarse, true);
  coarse->print_property_dofs(cout,
                              step_fcn,
                              "After pushing unstructured fine >>"
                              " unstructured coarse with refinement:",
                              true,
                              true);

  storage_agent sa("refining_section_pusher_2d.t.hdf");
  sa.write_entire(coarse->name_space());

}

} //namespace

///
/// Main routine.
///
int
main(int argc, char* argv[])
{

  // Test the refining section pusher.

  test_fine_to_coarse_with_refinement(true);

  return 0;
}


