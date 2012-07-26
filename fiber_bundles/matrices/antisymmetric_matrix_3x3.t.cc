
// $RCSfile: antisymmetric_matrix_3x3.t.cc,v $ $Revision: 1.6 $ $Date: 2012/03/01 00:40:52 $

//
// Copyright (c) 2012 Limit Point Systems, Inc.
//

/// @example antisymmetric_matrix_3x3.t.cc
/// Test driver for class antisymmetric_matrix_3x3.

#include "assert_contract.h"
#include "antisymmetric_matrix_3x3.h"
#include "general_matrix_1x3.h"
#include "general_matrix_2x3.h"
#include "general_matrix_3x1.h"
#include "general_matrix_3x2.h"
#include "general_matrix_3x3.h"
#include "symmetric_matrix_3x3.h"
#include "std_iostream.h"

using namespace fiber_bundle;

///
void test_antisymmetric_matrix_3x3()
{
  cout << "============================================================" << '\n'
       << "  test_antisymmetric_matrix_3x3:" << '\n'
       << "============================================================"
       << endl;

  antisymmetric_matrix_3x3<double> m;
  m[0][1] = 2;   m[0][2] = 3;
                 m[1][2] = 4; 

  cout << "m = " << endl;
  cout << m << endl;

  // Trace:

  double ltrace = m.trace();
  cout << "trace =  " << ltrace << endl;

  // Determinant:
  // Note that the determinant of all n=odd antisymmetric
  // matrices is zero.

  double det = m.determinant();
  cout << "determinant = " << det << endl;
  cout << endl;

//   // Inverse:

//   antisymmetric_matrix_3x3<double> im = m.inverse();
//   cout << "m.inverse():" << endl;
//   cout << im << endl;

  // Transpose:

  antisymmetric_matrix_3x3<double> tm = m.transpose();
  cout << "tm = m.transpose():" << endl;
  cout << tm << endl;

  // Adjoint:

  general_matrix_3x3<double> am = m.adjoint();
  cout << "am = m.adjoint():" << endl;
  cout << am << endl;

  // Multiply by a scalar.

//   general_matrix_3x3<double> am2 = am.multiply(1.0/det);
//   cout << "am2 = am.multiply(1.0/determinant):" << endl; 
//   cout << am2 << endl;

  general_matrix_3x3<double> am2 = am.multiply(2.0);
  cout << "am2 = am.multiply(2.0):" << endl; 
  cout << am2 << endl;

  // Diagonalize.

  // Not implemented for antisymmetric matrices (eigenvalues are pure complex).

  // Identity:

  // Not defined for antisymmetric matrices (all diagonal elements are 0).

  // Conversion to a general matrix.

  general_matrix_3x3<double> gm3x3 = m;
  cout << "general_matrix_3x3<double> gm3x3 = m:" << endl;
  cout << gm3x3 << endl;

  // Matrix multiply.

  cout << "mx.multiply(tm):" << endl;
  general_matrix_3x3<double> mm = m.multiply(tm);
  cout << mm << endl;

  general_matrix_3x2<double> m3x2;
  m3x2[0][0] =  1; m3x2[0][1] = 2;
  m3x2[1][0] =  3; m3x2[1][1] = 4;
  m3x2[2][0] =  5; m3x2[2][1] = 6;

  cout << "m3x2 = " << endl;
  cout << m3x2 << endl;

  cout << "m.multiply(m3x2):" << endl;
  general_matrix_3x2<double> mm3x2 = m.multiply(m3x2);
  cout << mm3x2 << endl;

  general_matrix_3x1<double> m3x1;
  m3x1[0][0] =  1;
  m3x1[1][0] =  3;
  m3x1[2][0] =  5;

  cout << "m3x1 = " << endl;
  cout << m3x1 << endl;

  cout << "m.multiply(m3x1):" << endl;
  general_matrix_3x1<double> mm3x1 = m.multiply(m3x1);
  cout << mm3x1 << endl;

  general_matrix_2x3<double> m2x3;
  m2x3[0][0] = 1; m2x3[0][1] = 2; m2x3[0][2] = 3;
  m2x3[1][0] = 4; m2x3[1][1] = 5; m2x3[1][2] = 6;

  cout << "m2x3 = " << endl;
  cout << m2x3 << endl;

  cout << "m2X3.multiply(m):" << endl;
  general_matrix_2x3<double> mm2x3 = m2x3.multiply(m);
  cout << mm2x3 << endl;

  general_matrix_1x3<double> m1x3;
  m1x3[0][0] = 1; m1x3[0][1] = 2; m1x3[0][2] = 3;

  cout << "m1x3 = " << endl;
  cout << m1x3 << endl;

  cout << "m1x3.multiply(m):" << endl;
  general_matrix_1x3<double> mm1x3 = m1x3.multiply(m);
  cout << mm1x3 << endl;


  //============================================================================

  // Extract row.

  general_matrix_1x3<double> row_1 = m.row(1);
  cout << "general_matrix_1x3<double> row_1 = m.row(1):" << endl;
  cout << row_1 << endl;

  // Extract column.

  general_matrix_3x1<double> col_1 = m.column(1);
  cout << "general_matrix_3x1<double> col_1 = m.column(1):" << endl;
  cout << col_1 << endl;
}

///
int main()
{
  test_antisymmetric_matrix_3x3();

  return 0;
}

