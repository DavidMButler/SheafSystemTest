
// $RCSfile: cube_with_fault_1.t.cc,v $ $Revision: 1.4 $ $Date: 2012/03/01 00:41:14 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example cube_with_fault_1.t.cc
/// Simple test driver for the tetgen mesh generator.

//  This is a unit cube with a 0.5 by 0.5 square fin/tab/fracture (internal
//  boundary) with normal (1, 0, 0) and centered at (0.5, 0.5. 0.25). 
//  This test demonstrates that tetgen does indeed create tetrahedra
//  with consistent faces across internal boundaries. It can also be
//  used to experiment with allowing or not allowing tetgen to add
//  additional points on either internal or external boundaries. 

#include "fiber_bundles_namespace.h"
#include "geometry.h"
#include "index_space_iterator.h"
#include "sec_at0.h"
#include "sec_at0_space.h"
#include "sec_at1_space.h"
#include "sec_e3.h"
#include "sec_rep_descriptor.h"
#include "section_space_schema_poset.h"
#include "std_cmath.h"
#include "std_fstream.h"
#include "std_sstream.h"
#include "std_string.h"
#include "storage_agent.h"
#include "subposet.h"
#include "subposet_member_iterator.h"
#include "tetgen_generator.h"
#include "unstructured_block.h"
#include "unstructured_block_builder.h"

//#define DIAGNOSTIC_OUTPUT

using namespace geometry;

namespace
{

//$$SCRIBBLE: Except for the following two functions, several test cases
//            have the same code.  It might make sense to put them into
//            a common class or stand alone functions file.

//==============================================================================

void
get_connectivities(vector<mesh_generator::pod_type>& xconns)
{
  const size_type lnode_id_ct = 174; // 58*3
  const pod_index_type lnode_ids[174] =
  {
    10,  0,  7,
    10,  7,  6,
    10,  6,  5,
    10,  5,  9,
    10,  9,  8,
    10,  8,  1,
    10,  1,  0,
    11,  1,  8,
    11,  8,  9,
    11,  9,  5,
    11,  5,  4,
    11,  4,  3,
    11,  3,  2,
    11,  2,  1,
    20, 12, 13,
    20, 13, 14,
    20, 14, 15,
    20, 15, 16,
    20, 16, 17,
    20, 17, 18,
    20, 18, 19,
    20, 19, 12,
    22, 21,  0,
    22,  0,  1,
    22,  1,  2,
    22,  2, 23,
    22, 12, 21,
    22, 13, 12,
    22, 14, 13,
    22, 23, 14,
    26,  6, 27,
    26,  5,  6,
    26,  4,  5,
    26, 25,  4,
    26, 27, 18,
    26, 18, 17,
    26, 17, 16,
    26, 16, 25,
    28,  7,  0,
    28,  0, 21,
    28, 21, 12,
    28, 12, 19,
    28,  6,  7,
    28, 27,  6,
    28, 18, 27,
    28, 19, 18,
    24,  2,  3,
    24, 23,  2,
    24, 14, 23,
    24, 15, 14,
    24,  3,  4,
    24,  4, 25,
    24, 25, 16,
    24, 16, 15,
    31,  8,  9,
    31,  9, 30,
    31, 30, 29,
    31, 29,  8
  };

  xconns.assign(lnode_ids, lnode_ids+lnode_id_ct);
}

void
get_coordinates(vector<e3_lite>& xcoords)
{
  static const int lcoords_ct = 32;
  static const e3_lite lcoords_array[32] =
  {
    e3_lite(0.0,   0.0,   0.0 ),
    e3_lite(0.5,   0.0,   0.0 ),
    e3_lite(1.0,   0.0,   0.0 ),
    e3_lite(1.0,   0.5,   0.0 ),
    e3_lite(1.0,   1.0,   0.0 ),
    e3_lite(0.5,   1.0,   0.0 ),
    e3_lite(0.0,   1.0,   0.0 ),
    e3_lite(0.0,   0.5,   0.0 ),
    e3_lite(0.5,   0.25,  0.0 ),
    e3_lite(0.5,   0.75,  0.0 ),
    e3_lite(0.25,  0.5,   0.0 ),
    e3_lite(0.75,  0.5,   0.0 ),
    e3_lite(0.0,   0.0,   1.0 ),
    e3_lite(0.5,   0.0,   1.0 ),
    e3_lite(1.0,   0.0,   1.0 ),
    e3_lite(1.0,   0.5,   1.0 ),
    e3_lite(1.0,   1.0,   1.0 ),
    e3_lite(0.5,   1.0,   1.0 ),
    e3_lite(0.0,   1.0,   1.0 ),
    e3_lite(0.0,   0.5,   1.0 ),
    e3_lite(0.5,   0.5,   1.0 ),
    e3_lite(0.0,   0.0,   0.5 ),
    e3_lite(0.5,   0.0,   0.5 ),
    e3_lite(1.0,   0.0,   0.5 ),
    e3_lite(1.0,   0.5,   0.5 ),
    e3_lite(1.0,   1.0,   0.5 ),
    e3_lite(0.5,   1.0,   0.5 ),
    e3_lite(0.0,   1.0,   0.5 ),
    e3_lite(0.0,   0.5,   0.5 ),
    e3_lite(0.5,   0.25,  0.5 ),
    e3_lite(0.5,   0.75,  0.5 ),
    e3_lite(0.5,   0.5,   0.25)
  };

  xcoords.assign(lcoords_array, lcoords_array+lcoords_ct);
}

//==============================================================================
//==============================================================================

// Making these paths global so they are all in one place and
// not scattered around.

static const poset_path lrep_path = tetgen_generator::rep_path();

static const string lproto_poset_name =
  unstructured_block::prototypes_poset_name();

static const poset_path ltetra_proto_path =
  tetgen_generator::tetra_proto_path();
            
static const poset_path ltriangle_proto_path(lproto_poset_name,
                                             "triangle_complex");

static const poset_path lsurface_base_space_path("surface_base_space",
                                                 "surface_triangles_block");

static const poset_path lsurface_coordinates_path("surface_coordinates_space",
                                                  "surface_coordinates");

//==============================================================================

// Create a file for viewing with paraview or other vtk viewer.
// The file created is a "legacy" vtk file as opposed to the newer
// xml based file formats.

// If parameter xis_tetra is true, we assume that tetrahedrons are being
// passed in xconns; otherwise we assume triangles.

void
create_vtk_file(const vector<e3_lite>& xcoords,
                const vector<mesh_generator::pod_type>& xconns,
                const string& xfilename,
                bool xis_tetra = true)
{
  // Preconditions:

  require(xis_tetra ? (xcoords.size() >= 4) : (xcoords.size() >= 3));
  require(xis_tetra ? (xconns.size() >= 4) : (xconns.size() >= 3));
  require(xis_tetra ? (xconns.size()%4 == 0) : (xconns.size()%3 == 0));
  require(!xfilename.empty());

  // Body:

  ofstream lofs(xfilename.c_str());
  if(!lofs.is_open())
  {
    cerr << "Warning: Could not open file " << xfilename << endl;
  }
  else
  {
    //==========================================================================

    lofs << "# vtk DataFile Version 2.0" << endl;
    lofs << "Unstructured Grid Example" << endl;
    lofs << "ASCII" << endl;
    lofs << endl;
    lofs << "DATASET UNSTRUCTURED_GRID" << endl;

    //==========================================================================

    size_type lnum_pts = xcoords.size();

    lofs << "POINTS " << lnum_pts << " double" << endl;

    e3_lite lfiber;
    for(size_type i=0; i<lnum_pts; ++i)
    {
      lfiber = xcoords[i];
      lofs << setw(12) << lfiber[0]
           << setw(12) << lfiber[1]
           << setw(12) << lfiber[2] << endl;
    }

    //==========================================================================

    int lnodes_per_element = xis_tetra ? 4 : 3;
    int lvtk_cell_type =  xis_tetra ? 10 : 5;

    size_type lnum_cells = xconns.size()/lnodes_per_element;

    lofs << "CELLS " << lnum_cells << " "
         << lnum_cells*(lnodes_per_element+1) << endl;

    for(size_type i=0, j=0; i<lnum_cells; ++i)
    {
      lofs << lnodes_per_element;
      for(size_type k = 0; k<lnodes_per_element; ++k)
      {
        lofs << setw(8) << xconns[j++];
      }
      lofs << endl;
    }

    lofs << "CELL_TYPES " << lnum_cells << endl;
    for(size_type i=0; i<lnum_cells; ++i)
    {
      lofs << lvtk_cell_type << endl;
    }

    //==========================================================================

    lofs.close();
  }

  // Postconditions:

  // Exit:

}

// This function is only used for debugging.  It just prints
// the members ot the cells (not d_cells) subposet.

void
print_cells_subposet(const base_space_poset& xbase_space)
{
  // Preconditions:

  require(xbase_space.state_is_read_accessible());

  // Body:

  // Print the "cells" subposet.

  cout << endl;
  cout << "Cells subposet members:" << endl;
  cout << endl;

  base_space_member lmbr;
  const subposet& lcells_sp = xbase_space.cells();
  subposet_member_iterator* litr = lcells_sp.member_iterator();
  while(!litr->is_done())
  {
    lmbr.attach_to_state(&xbase_space, litr->index());
    cout << setw(8) << litr->index().internal_pod()
         << "  :  " << lmbr.name() << endl;
    litr->next();
  }

  cout << endl;

  lmbr.detach_from_state();

  delete litr;

  // Postconditions:

  // Exit:

  return;
}

base_space_poset*
create_base_space(fiber_bundles_namespace& xns)
{
  // Preconditions:

  require(xns.state_is_read_write_accessible());

  // Body:

  // Create a base space.

  const string& lbase_name = lsurface_base_space_path.poset_name();
  const string& lmbr_name  = lsurface_base_space_path.member_name();

  base_space_poset* lbase_space =
    &xns.new_base_space<unstructured_block>(lbase_name, "", "", 3, true);

  lbase_space->get_read_write_access();

  // Create the surface connectivities.

  vector<mesh_generator::pod_type> lconns;
  get_connectivities(lconns);

  //unstructured_block_builder::put_name_mode(true);

  unstructured_block lblock(lbase_space,
                            ltriangle_proto_path,
                            &lconns[0],
                            lconns.size(),
                            true);

  lblock.put_name(lmbr_name, true, false);

  // Give members names.

  tetgen_generator::make_names(*lbase_space, 2, "face");
  tetgen_generator::make_names(*lbase_space, 1, "edge");
  tetgen_generator::make_names(*lbase_space, 0, "vertex");

  lblock.detach_from_state();

  // Postconditions:

  ensure(lbase_space->is_attached());

  // Exit:

  return lbase_space;
}

sec_at1_space*
create_coordinates_section(fiber_bundles_namespace& xns,
                           const poset_path& xbase_path)
{
  // Preconditions:

  require(xns.state_is_read_write_accessible());

  // Body:

  // Create the coordinates section space.

  const string& lspace_name = lsurface_coordinates_path.poset_name();
  const string& lmbr_name   = lsurface_coordinates_path.member_name();

  sec_at1_space* lcoords_space = 
    &(xns.new_section_space<sec_e3>(lspace_name, xbase_path, lrep_path, true));

  lcoords_space->get_read_write_access();

  // Create a coordinates section.

  base_space_member lbase_mbr(&xns, xbase_path);

  sec_e3 lcoords_mbr(lcoords_space, lbase_mbr);

  lcoords_mbr.put_name(lmbr_name, true, false);

  // Add the coordinates to the coordinates section.

  vector<e3_lite> lcoords;
  get_coordinates(lcoords);
 
  index_space_iterator* ldisc_itr =
    lcoords_mbr.schema().discretization_id_space().iterator(true);

  size_type i = 0;
  while(!ldisc_itr->is_done())
  {
    lcoords_mbr.put_fiber(ldisc_itr->id(), lcoords[i++]);
    ldisc_itr->next();
  }

  delete ldisc_itr;

  lbase_mbr.detach_from_state();
  lcoords_mbr.detach_from_state();

  // Postconditions:

  ensure(lcoords_space->is_attached());

  // Exit:

  return lcoords_space;
}

void
create_surface_in_name_space(fiber_bundles_namespace& xns)
{
  // Preconditions:

  require(xns.state_is_read_write_accessible());

  // Body:

  // Create a base space.

  base_space_poset* lbase_space = create_base_space(xns);

  // Create the coordinates section space.

  sec_at1_space* lcoords_space =
    create_coordinates_section(xns, lsurface_base_space_path);

#ifdef DIAGNOSTIC_OUTPUT
  print_cells_subposet(*lbase_space);
  cout << *lbase_space << endl;
  cout << *lcoords_space << endl;
#endif

  // Postconditions:

  // Exit:

  return;
}

void
run_tetgen(fiber_bundles_namespace& xns,
           const string& xtetgen_switches,
           const string& xfilename)
{
  // Preconditions:

  require(xns.state_is_read_write_accessible());

  // Body:

  // Instantiate a tetgen mesh generator.

  tetgen_generator lgenerator(xns,
                              lsurface_base_space_path,
                              lsurface_coordinates_path,
                              xtetgen_switches);

  // Invoke the generator's generate function.

  lgenerator.generate();


#ifdef DIAGNOSTIC_OUTPUT

  // Create vtk files for input in ParaView, etc.

  // ParaView does not like files with more than 1 ".".
  // So, it will not read "xyz.t.vtk".  Replace "." with "_".

  string lrootname = xfilename;
  int lpos = lrootname.find(".");
  while(lpos != string::npos) 
  {
      lrootname.replace(lpos, 1, "_" );
      lpos = lrootname.find(".", lpos+1);
  } 

  // First create a file from the orininal (input) surface triangles.

  create_vtk_file(lgenerator.tri_coordinates(),
                  lgenerator.tri_connectivities(),
                  lrootname + "_in.vtk",
                  false);

  // Create a second file from the tetgen generated tetrahedrons.

  create_vtk_file(lgenerator.tet_coordinates(),
                  lgenerator.tet_connectivities(),
                  lrootname + "_out.vtk",
                  true);
#endif

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

  const string lfilename = filename_from_cmdline(xargv[0]);

  string ltetgen_switches = "pYV"; // 'Y' preserves the original boundaries.
                                   // 'V' makes tetgen verbose.
  if(xargc >= 2)
  {
    ltetgen_switches = xargv[1];
  }

  fiber_bundles_namespace lns(lfilename);
  lns.get_read_write_access();

  create_surface_in_name_space(lns);

  run_tetgen(lns, ltetgen_switches, lfilename);

  cout << lns << endl;

  storage_agent sa(lfilename + ".hdf");
  sa.write_entire(lns);

  // Postconditions:

  // Exit:

  return 0;
}