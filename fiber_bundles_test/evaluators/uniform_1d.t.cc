
//
// Copyright (c) 2013 Limit Point Systems, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/// @example evaluators/uniform_1d.t.cc
/// Test case for class uniform_1d

#include "uniform_1d.h"
#include "assert_contract.h"
#include "std_iostream.h"

using namespace std;
using namespace std;
using namespace fiber_bundle;

typedef section_evaluator::dof_type dof_type;

int main(int argc, char* argv[])
{
  cout << "Testing uniform_1d" << endl;

  uniform_1d evaluator;

  dof_type dofs[] = { 1, 5 };

  dof_type m;

  m = evaluator.min(dofs, 2);
  cout << "min = " << m << endl;

  m = evaluator.max(dofs, 2);
  cout << "max = " << m << endl;

  //double local_coords[] = { 1.0 };
  double local_coords[] = { -1.0 };

  evaluator.basis_at_coord(local_coords, 1);

  for(int i=0; i<2; ++i)
    cout << "basis_values[" << i << "] = " << evaluator.basis_values()[i] << endl;

  // Test value_at_coord.

  // Single component version.

  dof_type x_value = evaluator.value_at_coord(dofs, 2, local_coords, 1);

  cout << "x_value = " << x_value << endl;

  // Multiple component version.

  dof_type values[1];

  //cout << "sizeof(values) = " << sizeof(values) << endl;

  evaluator.value_at_coord(dofs, 2, local_coords, 1, values, 1);

  cout << "x_value = " << values[0] << endl;

  // Test coord_at_value.

  dof_type global_coords[] = { 2 };

  evaluator.coord_at_value(dofs, 2, global_coords, 1, local_coords, 1);

  cout << "local_coords[0] = " << local_coords[0] << endl;

  // Test dxi_local.

  //evaluator.dxi_local();

  return 0;
}
