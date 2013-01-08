
// $RCSfile: group_x.t.cc,v $ $Revision: 1.10 $ $Date: 2012/03/01 00:40:41 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example group_x.t.cc
/// Test driver for class group.

#include "group.h"

#include "assert_contract.h"
#include "std_iomanip.h"
//#include "test_fibers_x.impl.h"
//#include "fiber_bundles_namespace.h"
//#include "storage_agent.h"

using namespace fiber_bundle;

namespace
{
  void
  test_group_volatile()
  {
    // Preconditions:

    // Body:

    cout << boolalpha;

    //==========================================================================
    // group facet
    //==========================================================================

    //group_lite();

    group_lite lfiber;

    //group_lite(const group_lite& xother);

    group_lite lfiber_copy(lfiber);

    //group_lite& operator=(const group_lite& xother);

    group_lite lfiber_assign = lfiber;

    //virtual ~group_lite();

    group_lite* lfiber_ptr = new group_lite;
    delete lfiber_ptr;

    //==========================================================================
    // abstract_poset_member facet
    //==========================================================================

    //virtual const string& class_name() const;

    const string& lclass_name = lfiber.class_name();
    cout << "lclass_name = " << lclass_name << endl; 

    //static const string& static_class_name();

    const string& lstatic_class_name = lfiber.static_class_name();
    cout << "lstatic_class_name = " << lstatic_class_name << endl; 

    //$$SCRIBBLE: Abstract.
    //virtual group_lite* clone() const;

    //group_lite* lclone = lfiber.clone();
    //cout << "lclone = " << lclone << endl; 
    //delete lclone;

    //==========================================================================
    // any facet
    //==========================================================================

    //virtual bool is_ancestor_of(const any_lite& xother) const;

    bool lis_ancestor_of = lfiber.is_ancestor_of(lfiber_copy);
    cout << "lis_ancestor_of = " << lis_ancestor_of << endl; 

    //bool invariant() const;

    bool linvariant = lfiber.invariant();
    cout << "linvariant = " << linvariant << endl; 

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

  //fiber_bundles_namespace ns(filename);
  //ns.get_read_write_access();

  // Run tests.

  test_group_volatile();

  // Write the namespace to standard out.

  //cout << ns << endl;

  // Write the namespace to a file.

  //storage_agent write_agent(filename + ".hdf" + ".hdf");
  //write_agent.write_entire(ns);

  // Postconditions:

  // Exit:

  return 0;
}