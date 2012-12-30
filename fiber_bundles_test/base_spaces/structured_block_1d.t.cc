
// $RCSfile: structured_block_1d.t.cc,v $ $Revision: 1.28 $ $Date: 2012/03/01 00:40:32 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example base_spaces/structured_block_1d.t.cc
/// Test driver for structured_block_1d.cc.

#include "chart_point_1d.h"
#include "fiber_bundles_namespace.h"
#include "poset_path.h"
#include "sec_at0.h"
#include "sec_e1.h"
#include "sec_e1_uniform.h"
#include "std_string.h"
#include "structured_block_1d.h"
#include "storage_agent.h"
#include "test_sections.impl.h"
#include "tern.h"

using namespace fiber_bundle;


int
main(int xargc, char* xargv[])
{

  string filename = filename_from_cmdline(*xargv);

  string size_arg;
  size_type size;
  if (xargc > 1)
  {
    size = atoi(xargv[1]);
    size_arg = xargv[1];
  }
  else
  {
    size = 2;
    size_arg = "2";
  }

  fiber_bundles_namespace lns(filename);

  lns.get_read_write_access();

  // Make a mesh with 2 blocks.

  base_space_poset* lmesh = &lns.new_base_space<structured_block_1d>("1d_structued_mesh");

  structured_block_1d lblock0(lmesh, size, true);
  lblock0.put_name("1D_structured_block0", true, true);

  structured_block_1d lblock1(lmesh, size, true);
  lblock1.put_name("1D_structured_block1", true, true);

  // Join the last edge of the first block and 
  // the first edge of the second block.

  lmesh->get_read_write_access();

  scoped_index ljoin_ids[2];
  ljoin_ids[0] = lblock0.zone_id(size - 1);
  ljoin_ids[1] = lblock1.zone_id(0);
  
  base_space_member ljoin(lmesh, ljoin_ids, 2, tern::TRUE, false);
  
  poset_path lbase_path = lblock0.path();

  cout << *lmesh << endl;

  // Test the refinement map.

  cout << endl << "##### Refinement map test ###############" << endl << endl;

  const scoped_index& lindex0 = lblock0.index();
  chart_point_1d lpt;

  chart_point_1d lref_pt;

  for(double lcoord= -1.0; lcoord <= 1.0; lcoord += 0.1)
  {
    lpt.put(lindex0, lcoord);
    lblock0.refine_point_pa(lpt, lref_pt);
    cout << "point: " << lpt << "\trefined point: " << lref_pt;
    lblock0.unrefine_point_pa(lref_pt, lpt);
    cout << "\tunrefined point: " << lpt << endl;
  }

  cout << endl << "##### End refinement map test ###############" << endl << endl;


  // Make uniform (coordinate) section.

  sec_e1_uniform::host_type& luniform_space =
    new_host_space<sec_e1_uniform>(lns, "coordinates_section_space", lbase_path);

  sec_e1_uniform lcoords(&luniform_space, 0.0, 1.0, true);
  lcoords.put_name("coordinates", true, true);

  cout << luniform_space << endl;

  // Make non-uniform (property) section.

  sec_at0::host_type& lprop_space =
    new_host_space<sec_at0>(lns, "property_section_space", lbase_path);

  sec_at0 lprop(&lprop_space);
  lprop.get_read_write_access();
  lprop.put_name("property", true, false);

  sec_at0::fiber_type::volatile_type lfiber = 2.0;
  lprop = lfiber;

  cout << lprop_space << endl << endl;

  //============================================================================
  // Miscellaneous coverage tests.
  //============================================================================

  const unary_index_space& lid_space = lblock0.id_space();

  ragged_array<unary_index>* lneighbor_list = lid_space.neighbor_list();

  cout << "lid_space = " << lid_space << endl;

  //============================================================================


  // Clean-up.

  lblock0.release_access();
  lblock0.detach_from_state();
  lblock1.detach_from_state();
  ljoin.detach_from_state();
  lcoords.detach_from_state();
  lprop.release_access();
  lprop.detach_from_state();

  // Output namespace.

  cout << lns << endl;

  storage_agent sa(filename + ".hdf", sheaf_file::READ_WRITE, true, false);
  sa.write_entire(lns);

  return 0;
}
