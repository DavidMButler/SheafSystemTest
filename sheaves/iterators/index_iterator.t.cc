// $RCSfile: index_iterator.t.cc,v $ $Revision: 1.11 $ $Date: 2012/03/01 00:41:26 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example iterators/index_iterator.t.cc
/// Unit test driver for class index_iterator.

#include "index_iterator.h"
#include "assert_contract.h"
#include "std_iomanip.h"
#include "zn_to_bool.h"

///
int
main(int argc, char* argv[])
{
  // Use alpha formt for bools.

  cout << boolalpha;

  // Make a bitvector

  zn_to_bool lbits(8);
  lbits.put(0, true);
  lbits.put(4, true);


  // Test ctor and iteration with initial bit true:

  cout << endl << "Iterating over bit vector:"  << endl << lbits << endl << endl;
  cout << "Should visit bits 0 and 4" << endl << endl;

  index_iterator itr(&lbits);
  while(!itr.is_done())
  {
    cout << setw(8) << itr.index()
    << " is_last: " << itr.is_last()
    << endl;

    itr.next();
  }

  // Test reset():

  cout << endl << "Reset and do it again:" << endl << endl;

  itr.reset();
  while(!itr.is_done())
  {
    cout << setw(8) << itr.index()
    << " is_last: " << itr.is_last()
    << endl;

    itr.next();
  }


  // Test reset(zn_to_bool* xhost)

  // Test reset(zn_to_bool* xhost) and iteration with initial bit false:

  zn_to_bool lnot_bits(lbits);
  lnot_bits.b_not_sa();

  cout << endl << "Iterating over bit vector:"  << endl << lnot_bits << endl << endl;
  ;
  cout << "Should visit bits 1, 2, 3, 5, 6, and 7" << endl << endl;

  itr.reset(&lnot_bits);
  while(!itr.is_done())
  {
    cout << setw(8) << itr.index()
    << " is_last: " << itr.is_last()
    << endl;

    itr.next();
  }

  // Test iteration with last bit true.

  size_t lub = lbits.capacity();
  lbits.force(lub - 1, true);

  cout << endl << "Iterating over bit vector:"  << endl << lbits << endl << endl;
  cout << "Should visit bits 0, 4, and 31" << endl << endl;

  itr.reset(&lbits);
  while(!itr.is_done())
  {
    cout << setw(8) << itr.index()
    << " is_last: " << itr.is_last()
    << endl;

    itr.next();
  }


  // Restore bool format to default.

  cout << noboolalpha;

  // Exit:

  return(0);
}

