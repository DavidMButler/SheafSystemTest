
// $RCSfile: jcb_e33_x.t.cc,v $ $Revision: 1.10 $ $Date: 2012/03/01 00:40:41 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example jcb_e33_x.t.cc
/// Test driver for class jcb_e33.

#include "jcb_e33.h"

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
  test_jcb_e33_volatile()
  {
    // Preconditions:

    // Body:

    //==========================================================================

    test_volatile_common<jcb_e33_lite>();

    //test_volatile_jcb_facet<jcb_e33_lite>();

    //==========================================================================

    typedef double value_type;
    typedef jcb_e33_row_dofs_type<double> row_dofs_type;
    typedef general_matrix_3x3<double> matrix_type;

    jcb_e33_lite lfiber(0.11, 0.12, 0.13, 0.21, 0.22, 0.23, 0.31, 0.32, 0.33);
    lfiber.put_components(0.111, 0.112, 0.113,
                          0.121, 0.122, 0.123,
                          0.131, 0.132, 0.133);

    row_dofs_type& lrow_dofs(lfiber);

    const jcb_e33_lite lfiber_const;

    const row_dofs_type& lrow_dofs_const(lfiber_const);

    //==========================================================================

    matrix_type lmat;
    lmat[0][0] =  10; lmat[0][1] = -10; lmat[0][2] =   0;
    lmat[1][0] = -10; lmat[1][1] =  20; lmat[1][2] = -10;
    lmat[2][0] =   0; lmat[2][1] =   0; lmat[2][2] =  10;

    cout << "lmat = " << endl;
    cout << lmat << endl;

    //jcb_e33_lite(const matrix_type& xmatrix);

    jcb_e33_lite lfiber2(lmat);
    const jcb_e33_lite lfiber2_const(lmat);

    //jcb_e33_lite& operator=(const matrix_type& xmatrix);

    jcb_e33_lite lfiber2_assign = lmat;

    //operator matrix_type& ();

    matrix_type& lmatrix_type(lfiber2);

    //operator const matrix_type& () const;

    const matrix_type& lmatrix_type_const(lfiber_const);

    //==========================================================================

    //jcb_e33_row_dofs_type<T>* clone(bool xnew_state, bool xauto_access) const

    row_dofs_type* lclone_row_dofs = lrow_dofs.clone(true, true);

    //virtual jcb_e33_lite* clone(bool xnew_state, bool xauto_access) const

    jcb_e33_lite* lclone = lfiber.clone(true, true);

    delete lclone_row_dofs; 
    delete lclone;

   //==========================================================================

    //operator jcb_e33_row_dofs_type<T>& () const

    jcb_e33_row_dofs_type<double>& lrow_dofs3(lmat);

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

  test_jcb_e33_volatile();

  // Write the namespace to standard out.

  //cout << lns << endl;

  // Write the namespace to a file.

  //storage_agent write_agent(filename + ".hdf");
  //write_agent.write_entire(lns);

  // Postconditions:

  // Exit:

  return 0;
}