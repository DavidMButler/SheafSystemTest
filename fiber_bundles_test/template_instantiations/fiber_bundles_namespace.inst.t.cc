// $RCSfile: fiber_bundles_namespace.inst.t.cc,v $ $Revision: 1.1.2.5 $ $Date: 2012/11/05 23:28:35 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example template_instantiations/fiber_bundles_namespace.inst.t.cc
/// Unit test driver for class fiber_bundles_namespace templated functions.

#include "fiber_bundles_namespace.h"

#include "arg_list.h"
#include "at0.h"
#include "at0_space.h"
#include "at1.h"
#include "at1_space.h"
#include "at2.h"
#include "at2_e2.h"
#include "at2_e3.h"
#include "at3.h"
#include "at3_e3.h"
#include "atp.h"
#include "atp_space.h"
#include "e1.h"
#include "e2.h"
#include "e3.h"
#include "e4.h"
#include "ed.h"
#include "gl2.h"
#include "gl3.h"
#include "gln.h"
#include "gln_space.h"
#include "jcb.h"
#include "jcb_e13.h"
#include "jcb_e23.h"
#include "jcb_e33.h"
#include "jcb_ed.h"
#include "jcb_space.h"
#include "met.h"
#include "met_e1.h"
#include "met_e2.h"
#include "met_e3.h"
#include "met_ed.h"
#include "sec_at0.h"
#include "sec_at0_space.h"
#include "sec_at1.h"
#include "sec_at1_space.h"
#include "sec_at2.h"
#include "sec_at2_e2.h"
#include "sec_at2_e3.h"
#include "sec_at3.h"
#include "sec_at3_e3.h"
#include "sec_atp.h"
#include "sec_atp_space.h"
#include "sec_e1.h"
#include "sec_e1_uniform.h"
#include "sec_e2.h"
#include "sec_e2_uniform.h"
#include "sec_e3.h"
#include "sec_e3_uniform.h"
#include "sec_e4.h"
#include "sec_ed.h"
#include "sec_jcb.h"
#include "sec_jcb_e13.h"
#include "sec_jcb_e23.h"
#include "sec_jcb_e33.h"
#include "sec_jcb_ed.h"
#include "sec_jcb_space.h"
#include "sec_met.h"
#include "sec_met_e1.h"
#include "sec_met_e2.h"
#include "sec_met_e3.h"
#include "sec_met_ed.h"
#include "sec_st2.h"
#include "sec_st2_e2.h"
#include "sec_st2_e3.h"
#include "sec_st3.h"
#include "sec_st3_e3.h"
#include "sec_st4.h"
#include "sec_st4_e2.h"
#include "sec_st4_e3.h"
#include "sec_stp.h"
#include "sec_stp_space.h"
#include "sec_t2.h"
#include "sec_t2_e2.h"
#include "sec_t2_e3.h"
#include "sec_t3.h"
#include "sec_t3_e3.h"
#include "sec_t4.h"
#include "sec_t4_e2.h"
#include "sec_t4_e3.h"
#include "sec_tp.h"
#include "sec_tp_space.h"
#include "sec_tuple.h"
#include "sec_tuple_space.h"
#include "sec_vd.h"
#include "sec_vd_space.h"
#include "st2.h"
#include "st2_e2.h"
#include "st2_e3.h"
#include "st3.h"
#include "st3_e3.h"
#include "st4.h"
#include "st4_e2.h"
#include "st4_e3.h"
#include "stp.h"
#include "stp_space.h"
#include "t2.h"
#include "t2_e2.h"
#include "t2_e3.h"
#include "t3.h"
#include "t3_e3.h"
#include "t4.h"
#include "t4_e2.h"
#include "t4_e3.h"
#include "test_utils.h"
#include "tp.h"
#include "tp_space.h"
#include "tuple.h"
#include "tuple_space.h"
#include "vd.h"
#include "vd_space.h"

using namespace fiber_bundle;

// Uncomment this #define to cause the failures in new section functions.

//#define DO_FAIL 

int
main(int xargc, char* xargv[])
{
  // Preconditions:

  // Body:

  print_header("Begin testing fiber_bundles_namespace instantiations.");

  bool ltest = true;

  cout << "Begin creating namespace..." << endl;

  fiber_bundles_namespace lns("test_namespace");
  lns.get_read_write_access();

  cout << "Finished creating namespace." << endl;

  //============================================================================

  // Commented out function for new_fiber_spaces, etc. have trailing comments to
  // indicate the failure message (not location though).  Probably should not
  // invoke these for the types (eg: at2), but you can try!

  lns.new_fiber_space<at0>();
  lns.new_fiber_space<at1>();

  ////lns.new_fiber_space<at2>(); //xi >= xj

  lns.new_fiber_space<at2_e2>();
  lns.new_fiber_space<at2_e3>();

  ////lns.new_fiber_space<at3>(); //xi >= xj

  lns.new_fiber_space<at3_e3>();

  ////lns.new_fiber_space<atp>(); //completed_p<F>(xfiber_space_path, xfiber_space_args, xauto_access) >= 0

  lns.new_fiber_space<e1>();
  lns.new_fiber_space<e2>();
  lns.new_fiber_space<e3>();
  lns.new_fiber_space<e4>();
  lns.new_fiber_space<ed>();
  lns.new_fiber_space<gl2>();
  lns.new_fiber_space<gl3>();
  lns.new_fiber_space<gln>();
  lns.new_fiber_space<jcb_e13>();
  lns.new_fiber_space<jcb_e23>();
  lns.new_fiber_space<jcb_e33>();
  lns.new_fiber_space<jcb_ed>();
  lns.new_fiber_space<jcb>();
  lns.new_fiber_space<met_e1>();
  lns.new_fiber_space<met_e2>();
  lns.new_fiber_space<met_e3>();

  ////lns.new_fiber_space<met_ed>(); //xi >= xj'
  ////lns.new_fiber_space<met>();    //xi >= xj'

  lns.new_fiber_space<st2_e2>();
  lns.new_fiber_space<st2_e3>();

  ////lns.new_fiber_space<st2>(); //xi >= xj'

  lns.new_fiber_space<st3_e3>();

  ////lns.new_fiber_space<st3>(); //xi >= xj'

  lns.new_fiber_space<st4_e2>();
  lns.new_fiber_space<st4_e3>();

  ////lns.new_fiber_space<st4>(); //xi >= xj'
  ////lns.new_fiber_space<stp>(); //completed_p<F>(xfiber_space_path, xfiber_space_args, xauto_access) >= 0

  lns.new_fiber_space<t2_e2>();
  lns.new_fiber_space<t2_e3>();
  lns.new_fiber_space<t2>();
  lns.new_fiber_space<t3_e3>();
  lns.new_fiber_space<t3>();
  lns.new_fiber_space<t4_e2>();
  lns.new_fiber_space<t4_e3>();
  lns.new_fiber_space<t4>();

  ////lns.new_fiber_space<tp>(); //completed_p<F>(xfiber_space_path, xfiber_space_args, xauto_access) >= 0

  lns.new_fiber_space<tuple>();
  lns.new_fiber_space<vd>();

  //============================================================================

  lns.new_scalar_space<at0>();

  //============================================================================

  lns.new_vector_space<at1>();
  lns.new_vector_space<e1>();
  lns.new_vector_space<e2>();
  lns.new_vector_space<e3>();
  lns.new_vector_space<e4>();
  lns.new_vector_space<ed>();

  //============================================================================

  ////lns.new_tensor_space<at2>(); //xi >= xj

  lns.new_tensor_space<at2_e2>();
  lns.new_tensor_space<at2_e3>();

  ////lns.new_tensor_space<at3>(); //xi >= xj

  lns.new_tensor_space<at3_e3>();

  ////lns.new_tensor_space<atp>(); //completed_p<F>(xfiber_space_path, xfiber_space_args, xauto_access) >= 0

  lns.new_tensor_space<met_e1>();
  lns.new_tensor_space<met_e2>();
  lns.new_tensor_space<met_e3>();

  ////lns.new_tensor_space<met_ed>(); //xi >= xj
  ////lns.new_tensor_space<met>();    //xi >= xj

  lns.new_tensor_space<st2_e2>();
  lns.new_tensor_space<st2_e3>();

  ////lns.new_tensor_space<st2>();   //xi >= xj

  lns.new_tensor_space<st3_e3>();

  ////lns.new_tensor_space<st3>();   //xi >= xj

  lns.new_tensor_space<st4_e2>();
  lns.new_tensor_space<st4_e3>();

  ////lns.new_tensor_space<st4>();; //xi >= xj
  ////lns.new_tensor_space<stp>();  //completed_p<F>(xfiber_space_path, xfiber_space_args, xauto_access) >= 0

  lns.new_tensor_space<t2_e2>();
  lns.new_tensor_space<t2_e3>();
  lns.new_tensor_space<t2>();
  lns.new_tensor_space<t3_e3>();
  lns.new_tensor_space<t3>();
  lns.new_tensor_space<t4_e2>();
  lns.new_tensor_space<t4_e3>();
  lns.new_tensor_space<t4>();

  ////lns.new_tensor_space<tp>(); //completed_p<F>(xfiber_space_path, xfiber_space_args, xauto_access) >= 0

  //============================================================================

  lns.new_group_space<gl2>();
  lns.new_group_space<gl3>();
  lns.new_group_space<gln>();

  lns.new_jacobian_space<jcb_e13>();
  lns.new_jacobian_space<jcb_e23>();
  lns.new_jacobian_space<jcb_e33>();
  lns.new_jacobian_space<jcb_ed>();
  lns.new_jacobian_space<jcb>();

  //============================================================================

#ifdef DO_FAIL

  // These return poset_path:
  // All of these tests fail with roughly the same error message:

  // For example:
  // terminate called after throwing an instance of 'std::logic_error'
  //   what():  '(xsection_space_schema_path.full() &&
  // contains_path<section_space_schema_poset>(xsection_space_schema_path, xauto_access)) ||
  // xbase_space_path.full() ||
  // (xsection_space_schema_args.contains_arg("base_space_path") &&
  // poset_path(xsection_space_schema_args.value("base_space_path")).full())'
  // in file fiber_bundles_namespace.cc at line 793

  lns.new_section_space_schema<sec_at0>();
  ////lns.new_section_space_schema<sec_at1>();
  ////lns.new_section_space_schema<sec_at2>();
  ////lns.new_section_space_schema<sec_at2_e2>();
  ////lns.new_section_space_schema<sec_at2_e3>();
  ////lns.new_section_space_schema<sec_at3>();
  ////lns.new_section_space_schema<sec_at3_e3>();
  ////lns.new_section_space_schema<sec_atp>();
  ////lns.new_section_space_schema<sec_e1>();
  ////lns.new_section_space_schema<sec_e1_uniform>();
  ////lns.new_section_space_schema<sec_e2>();
  ////lns.new_section_space_schema<sec_e2_uniform>();
  ////lns.new_section_space_schema<sec_e3>();
  ////lns.new_section_space_schema<sec_e3_uniform>();
  ////lns.new_section_space_schema<sec_e4>();
  ////lns.new_section_space_schema<sec_ed>();


  ////lns.new_section_space_schema<sec_met>();
  ////lns.new_section_space_schema<sec_met_e1>();
  ////lns.new_section_space_schema<sec_met_e2>();
  ////lns.new_section_space_schema<sec_met_e3>();
  ////lns.new_section_space_schema<sec_met_ed>();
  ////lns.new_section_space_schema<sec_st2>();

  ////lns.new_section_space_schema<sec_st2_e2>();
  ////lns.new_section_space_schema<sec_st2_e3>();
  ////lns.new_section_space_schema<sec_st3>();
  ////lns.new_section_space_schema<sec_st3_e3>();
  ////lns.new_section_space_schema<sec_st4>();
  ////lns.new_section_space_schema<sec_st4_e2>();
  ////lns.new_section_space_schema<sec_st4_e3>();
  ////lns.new_section_space_schema<sec_stp>();
  ////lns.new_section_space_schema<sec_t2>();
  ////lns.new_section_space_schema<sec_t2_e2>();
  ////lns.new_section_space_schema<sec_t2_e3>();
  ////lns.new_section_space_schema<sec_t3>();
  ////lns.new_section_space_schema<sec_t3_e3>();
  ////lns.new_section_space_schema<sec_t4>();
  ////lns.new_section_space_schema<sec_t4_e2>();
  ////lns.new_section_space_schema<sec_t4_e3>();
  ////lns.new_section_space_schema<sec_tp>();

  //============================================================================

  ////lns.new_scalar_section_space_schema<sec_at0>();

  //============================================================================

  ////lns.new_vector_section_space_schema<sec_at1>();
  ////lns.new_vector_section_space_schema<sec_e1>();
  ////lns.new_vector_section_space_schema<sec_e1_uniform>();
  ////lns.new_vector_section_space_schema<sec_e2>();
  ////lns.new_vector_section_space_schema<sec_e2_uniform>();
  ////lns.new_vector_section_space_schema<sec_e3>();
  ////lns.new_vector_section_space_schema<sec_e3_uniform>();
  ////lns.new_vector_section_space_schema<sec_e4>();
  ////lns.new_vector_section_space_schema<sec_ed>();
  ////lns.new_vector_section_space_schema<sec_vd>();

  //============================================================================

#endif

  int lresult = ltest ? EXIT_SUCCESS : EXIT_FAILURE;

  print_footer("End testing fiber_bundles_namespace instantiations.");


  // Postconditions:

  // Exit:

  return lresult;
}

