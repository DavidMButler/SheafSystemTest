// $RCSfile: rc.t.cc,v $ $Revision: 1.16 $ $Date: 2012/03/01 00:41:35 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example support/rc.t.cc
/// class RC_ANY & RC_PTR tester

#include "assert_contract.h"

#include "rc_any.h"
#include "rc_ptr.impl.h"
#include "std_iostream.h"

using namespace sheaf;

class rc_test : public rc_any
  {}
;

void print_rc(rc_test *rc)
{
  cout << "object    = " << rc << endl;
  if(rc)
  {
    cout << "ref_ct = " << rc->ref_ct() << endl;
    cout << "shared    = " << rc->is_shared() << endl;
  }
}

int main()
{
  cout << "---------------------------------" << endl;
  cout << "Constructing shareable rc_any"  << endl << endl;
  rc_test *rc = new rc_test();
  cout << "RESULT" << endl;
  print_rc(rc);
  cout << "---------------------------------" << endl;
  cout << "Constructing first rc_ptr" << endl << endl;
  cout << "RESULT" << endl;
  rc_ptr<rc_test> *ptr1 = new rc_ptr<rc_test>(rc);
  print_rc(rc);
  cout << "---------------------------------" << endl;
  cout << "Constructing second rc_ptr" << endl << endl;
  cout << "RESULT" << endl;
  rc_ptr<rc_test> *ptr2 = new rc_ptr<rc_test>(rc);
  print_rc(rc);
  cout << "---------------------------------" << endl;
  cout << "Destroying first rc_ptr" << endl << endl;
  cout << "RESULT" << endl;
  delete ptr1;
  print_rc(rc);
  cout << "---------------------------------" << endl;
  cout << "Destroying second rc_ptr" << endl << endl;
  cout << "RESULT" << endl;
  delete ptr2;
  cout << "---------------------------------" << endl;

  return 0;
}



