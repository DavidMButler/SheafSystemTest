// $RCSfile: tolerance_comparison.t.cc,v $ $Revision: 1.2 $ $Date: 2012/07/04 16:42:28 $

// $Name: HEAD $
//
// Copyright (c) 2008 Limit Point Systems, Inc. 
//

/// @file
/// Test driver for functions in tolerance_comparison.h

#include "tolerance_comparison.h"
#include "assert_contract.h"
#include "std_iostream.h"

using namespace sheaf;  // Workaround for MSVC++ bug

int main(int argc, char** argv[])
{
  
  cout << boolalpha;
  
  // Test float comparision.

  float lf0 = 0.0f;
  float lf1 = 1.0f;
  float lf2 = 1.0e+32;
  float lf3 = 1.0e-32;

  float lftol = 1.0e-06;
  
  // Test absolute comparison with 0.0f.

  cout << "0.0 == 0.0 default tolerance= " << a_eql_0(lf0) << endl;
  cout << "1.0 == 0.0 default tolerance = " << a_eql_0(lf1) << endl;

  cout << "0.0 == 0.0 specified tolerance= " << a_eql_0(lf0, lftol) << endl;
  cout << "1.0 == 0.0 specified tolerance= " << a_eql_0(lf1, lftol) << endl;
  
  // Test absolute comparison with 1.0f.

  cout << "0.0 == 1.0 default tolerance= " << a_eql_1(lf0) << endl;
  cout << "1.0 == 1.0 default tolerance = " << a_eql_1(lf1) << endl;

  cout << "0.0 == 1.0 specified tolerance= " << a_eql_1(lf0, lftol) << endl;
  cout << "1.0 == 1.0 specified tolerance= " << a_eql_1(lf1, lftol) << endl;
  
  // Test relative comparison of pair.

  cout << "lf2 == lf2 default tolerance= " << r_eql(lf2, lf2) << endl;
  cout << "lf2 == lf3 default tolerance = " << r_eql(lf2, lf3) << endl;

  cout << "lf2 == lf2 specified tolerance= " << r_eql(lf2, lf2, lftol) << endl;
  cout << "lf2 == lf3 specified tolerance= " << r_eql(lf2, lf3, lftol) << endl;
  
  // Test combined comparison of pair.

  cout << "lf2 == lf2 default tolerance= " << c_eql(lf2, lf2) << endl;
  cout << "lf2 == lf3 default tolerance = " << c_eql(lf2, lf3) << endl;

  cout << "lf2 == lf2 specified tolerance= " << c_eql(lf2, lf2, lftol) << endl;
  cout << "lf2 == lf3 specified tolerance= " << c_eql(lf2, lf3, lftol) << endl;

  
  // Test double comparision.

  double ld0 = 0.0;
  double ld1 = 1.0;
  double ld2 = 1.0e+64;
  double ld3 = 1.0e-64;

  double ldtol = 1.0e-12;
  
  // Test absolute comparison with 0.0.

  cout << "0.0 == 0.0 default tolerance= " << a_eql_0(ld0) << endl;
  cout << "1.0 == 0.0 default tolerance = " << a_eql_0(ld1) << endl;

  cout << "0.0 == 0.0 specified tolerance= " << a_eql_0(ld0, ldtol) << endl;
  cout << "1.0 == 0.0 specified tolerance= " << a_eql_0(ld1, ldtol) << endl;
  
  // Test absolute comparison with 1.0.

  cout << "0.0 == 1.0 default tolerance= " << a_eql_1(ld0) << endl;
  cout << "1.0 == 1.0 default tolerance = " << a_eql_1(ld1) << endl;

  cout << "0.0 == 1.0 specified tolerance= " << a_eql_1(ld0, ldtol) << endl;
  cout << "1.0 == 1.0 specified tolerance= " << a_eql_1(ld1, ldtol) << endl;
  
  // Test relative comparison of pair.

  cout << "ld2 == ld2 default tolerance= " << r_eql(ld2, ld2) << endl;
  cout << "ld2 == ld3 default tolerance = " << r_eql(ld2, ld3) << endl;

  cout << "ld2 == ld2 specified tolerance= " << r_eql(ld2, ld2, ldtol) << endl;
  cout << "ld2 == ld3 specified tolerance= " << r_eql(ld2, ld3, ldtol) << endl;
  
  // Test combined comparison of pair.

  cout << "ld2 == ld2 default tolerance= " << c_eql(ld2, ld2) << endl;
  cout << "ld2 == ld3 default tolerance = " << c_eql(ld2, ld3) << endl;

  cout << "ld2 == ld2 specified tolerance= " << c_eql(ld2, ld2, ldtol) << endl;
  cout << "ld2 == ld3 specified tolerance= " << c_eql(ld2, ld3, ldtol) << endl;

  return 0;
}
