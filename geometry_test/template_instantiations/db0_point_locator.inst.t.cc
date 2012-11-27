// $RCSfile: db0_point_locator.inst.t.cc,v $ $Revision: 1.1.2.4 $ $Date: 2012/10/24 02:00:34 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example
/// Unit test driver for class db0_point_locator.

#include "db0_point_locator.h"

#include "sec_e1.h"
#include "sec_e2.h"
#include "sec_e3.h"
#include "sec_ed_invertible.h"
#include "sec_at1_space.h"
#include "fiber_bundles_namespace.h"
#include "sec_rep_descriptor.h" 

#include "geometry.h"
#include "test_utils.h"

#include "test_sections.h"


using namespace geometry;

namespace
{

// template<int DC>
// bool
// test_db0_point_locator_facet()
// {

//   sec_ed sec;
//   db0_point_locator<DC> lloc(sec);
//   return true;
// }

} //end namespace

int
main(int xargc, char* xargv[])
{
  // Preconditions:

  // Body:

  print_header("Begin testing db0_point_locator_facet<DC>:");

  bool ltest = true;


//   //============================================================================

//   fiber_bundles_namespace lns("test_namespace");
//   lns.get_read_write_access();

//   // Make a base space.

// //   const poset_path& lbase_path = make_test_base_space(lns, 2); // 1d
// //   const poset_path& lbase_path = make_test_base_space(lns, 2, 2); // 2d
//   const poset_path& lbase_path = make_test_base_space(lns, 2, 2, 3); // 3d

//   poset_path lcoordinates_path("coordinate_section_space/coordinates_0");

//   sec_at1_space* lcoords_space =
//     &(lns.new_section_space<sec_e3>(lcoordinates_path.poset_name(),
//                                     lbase_path,
//                                     "sec_rep_descriptors/vertex_vertex_constant",
//                                     true));

//   lcoords_space->get_read_write_access();

//   sec_e1 lcoords(lcoords_space);
//   lcoords.put_name(lcoordinates_path.member_name(), true, false);


//   cout << lcoords.schema().rep().name() << endl;

//   sec_ed_invertible lsec_inv(lcoords);
//   lsec_inv.initialize_point_locator(false);

//   //db0_point_locator<1> lloc(lcoords);
//   //db0_point_locator<1> lloc(lsec_inv);

// //   block<size_type> lbin_ub;
// //   lbin_ub.push_back(10);

// //   //db0_point_locator<1> lloc(lcoords, lbin_ub);
// //   db0_point_locator<1> lloc(lsec_inv, lbin_ub);

//   const point_locator& lloc = lsec_inv.inverter();

//   //test_db0_point_locator_facet<1>(lcoords);


//   //============================================================================
//   // point_locator facet:

//   // sec_ed& coordinates() const;

//   sec_ed& lcoord_section = lloc.coordinates();

//   // const block<sec_vd_value_type>& lb() const;
  
//   const block<sec_vd_value_type>& llb = lloc.lb();

//   // const block<sec_vd_value_type>& ub() const;
  
//   const block<sec_vd_value_type>& lub = lloc.ub();

//   // int dc() const;

//   int ldc = lloc.dc();

//   // int db() const;

//   int ldb = lloc.db();

  //============================================================================

  int lresult = ltest ? EXIT_SUCCESS : EXIT_FAILURE;

  print_footer("End testing db0_point_locator_facet<DC>:");

  // Postconditions:

  // Exit:

  return lresult;
}

