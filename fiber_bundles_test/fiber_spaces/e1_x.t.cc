
// $RCSfile: e1_x.t.cc,v $ $Revision: 1.10 $ $Date: 2012/03/01 00:40:41 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example e1_x.t.cc
/// Test driver for class e1.

#include "e1.h"

#include "assert_contract.h"
#include "fiber_bundles_namespace.h"
#include "test_fibers.impl.h"
//#include "storage_agent.h"
//#include "ed_space.h"

#include "std_iomanip.h"
#include "std_iostream.h"

using namespace fiber_bundle;

namespace
{
  template<typename F>
  void
  test_volatile_tp_facet()
  {
    // Preconditions:

    // Body:

    const string& lfiber_name = F::static_class_name();

    print_header("Begin testing " + lfiber_name + " tp facet");

    F lfiber;

    //virtual int p() const;

    int lp = lfiber.p();
    cout << "lp = " << lp << endl;

    //virtual int dd() const;

    int ldd = lfiber.dd();
    cout << "ldd = " << ldd << endl;

    //virtual pod_index_type vector_space_index() const;

    pod_index_type lvector_space_index = lfiber.vector_space_index();
    cout << "lvector_space_index = " << lvector_space_index << endl;

    print_footer("End testing " +lfiber_name+ " tp facet");

    // Postconditions:

    // Exit:

    return;
  }

  template<typename F>
  void
  test_volatile_common()
  {
    // Preconditions:

    // Body:

    const string& lfiber_name = F::static_class_name();

    print_header("Begin testing " + lfiber_name + " common");


     // Default constructor.

    print_subheader("Testing " + lfiber_name + "()");

    F lfiber;


     // Copy constructor.

    print_subheader("Testing " + lfiber_name
                    + "(const "+lfiber_name+"& xother)");

    F lcopy(lfiber);


    // Assignment operator.

    print_subheader("Testing " + lfiber_name
                    + "& = (const "+lfiber_name+"& xother");

    F lassign = lfiber;
   

    print_header("End testing " +lfiber_name+ " common");


    // Destructor.

    print_subheader("Testing ~" +lfiber_name+ "()");

    F* lptr = new F;
    delete lptr;

    print_subheader("Testing bool operator==(",
                     "                  const " +lfiber_name+"& xother) const");

    bool lequalequal = (lcopy == lfiber);

    cout << "lequalequal =" << boolalpha << lequalequal << endl;

    print_subheader("Testing ostream& operator<<(",
                    "          ostream& xos, const "+lfiber_name+"& x0");

    cout << "lfiber = \n" << lfiber << endl;

    //==========================================================================
    // vd facet
    //==========================================================================

    print_subheader("Testing virtual int d() const");

    int ld = lfiber.d();
    cout << "ld = " << ld << endl;


    //F(const row_dofs_type& xrow_dofs);

    typename F::row_dofs_type lrow_dofs;
    F lfiber_2(lrow_dofs);

    //F& operator=(const row_dofs_type& xrow_dofs);

    F lfiber_2_assign = lrow_dofs;

//     //operator row_dofs_type& ();

//     typename F::row_dofs_type& lrow_dofs1 = lfiber;

//     //operator const row_dofs_type& () const;

//     const F lfiber_const;
//     const typename F::row_dofs_type& lrow_dofs3 = lfiber_const;

    //This does basically nothing except call the function in the vd case.

    typename F::dof_type lresult[4];
    lfiber.components(lresult, 4);

    //virtual void put_components(const dof_type xcomps[], int xcomps_dimension);

    //This does basically nothing except call the function in the vd case.
    lfiber.put_components(lresult, 4);

//     //vd_lite& operator=(const value_type& xvalue);

//     typename F::value_type lvalue = 123.0;
//     lfiber = lvalue;

//     //bool operator==(const value_type& xvalue) const;

//     bool leqeq = (lfiber == lvalue);


   //==========================================================================
    // tuple facet
    //==========================================================================

    print_subheader("Testing virtual int factor_ct() const");

    int lfactor_ct = lfiber.factor_ct();
    cout << "lfactor_ct = " << lfactor_ct << endl;


    //==========================================================================
    // abstract_poset_member facet
    //==========================================================================

    print_subheader("Testing virtual const string& class_name() const");

    const string& lclass_name = lfiber.class_name();
    cout << "lclass_name = " << lclass_name << endl;

 
    print_subheader("Testing static const string& static_class_name()");

    const string& lstatic_class_name = F::static_class_name();
    cout << "lstatic_class_name = " << lstatic_class_name << endl;


    print_subheader("Testing virtual " +lfiber_name+ "* clone() const");

    F* lclone = lfiber.clone();
    cout << "lclone = " << lclone << endl;
    delete lclone;

    print_subheader("Testing table_dofs_type table_dofs() const");

    typename F::table_dofs_type ltable_dofs = lfiber.table_dofs();

    //==========================================================================
    // any facet
    //==========================================================================

    print_subheader("Testing virtual bool is_ancestor_of",
                    "                          (const any_lite& xother) const");

    bool lis_ancestor_of = lfiber.is_ancestor_of(lcopy);
    cout << "lis_ancestor_of  = " << boolalpha << lis_ancestor_of  << endl;

 
    print_subheader("Testing bool invariant() const");

    bool linvariant = lfiber.invariant();
    cout << "linvariant = " << boolalpha << linvariant << endl;


    // Postconditions:

    // Exit:

    return;
  }

  void
  test_e1_volatile()
  {
    // Preconditions:

    // Body:

    test_volatile_common<e1_lite>();

    test_volatile_tp_facet<e1_lite>();


    //==========================================================================
    // vd facet
    //==========================================================================

    e1_lite lfiber;

    //operator row_dofs_type& ();

    e1_lite::row_dofs_type& lrow_dofs1 = lfiber;

    //operator const row_dofs_type& () const;

    const e1_lite lfiber_const;
    const e1_lite::row_dofs_type& lrow_dofs3 = lfiber_const;


    //==========================================================================
    // e1 facet
    //==========================================================================

    //static const tp_lite& static_tp_prototype(int xp);

    const tp_lite& lstatic_tp_prototype0 = e1_lite::static_tp_prototype(0);
    const tp_lite& lstatic_tp_prototype1 = e1_lite::static_tp_prototype(1);

    //virtual const tp_lite& tp_prototype(int xp) const;

    const tp_lite& ltp_prototype0 = lfiber.tp_prototype(0);
    const tp_lite& ltp_prototype1 = lfiber.tp_prototype(1);

    //static const atp_lite& static_atp_prototype(int xp);

    const atp_lite& lstatic_atp_prototype0 = e1_lite::static_atp_prototype(0);
    const atp_lite& lstatic_atp_prototype1 = e1_lite::static_atp_prototype(1);

    //virtual const atp_lite& atp_prototype(int xp) const;

    const atp_lite& latp_prototype0 = lfiber.atp_prototype(0);
    const atp_lite& latp_prototype1 = lfiber.atp_prototype(1);

    //static const stp_lite& static_stp_prototype(int xp);

    const stp_lite& lstatic_stp_prototype0 = e1_lite::static_stp_prototype(0);
    const stp_lite& lstatic_stp_prototype1 = e1_lite::static_stp_prototype(1);

    //virtual const stp_lite& stp_prototype(int xp) const;

    const stp_lite& lstp_prototype0 = lfiber.stp_prototype(0);
    const stp_lite& lstp_prototype1 = lfiber.stp_prototype(1);

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

  test_e1_volatile();

  // Write the namespace to standard out.

  //cout << lns << endl;

  // Write the namespace to a file.

  //storage_agent write_agent(filename + ".hdf");
  //write_agent.write_entire(lns);

  // Postconditions:

  // Exit:

  return 0;
}
