
#include "assert_contract.h"
#include "fiber_bundles_namespace.h"
#include "storage_agent.h"
#include "test_case_3d.h"

using namespace tool;

int main(int argc, char* argv[])
{
  // First, make sure the environment variables have been set.

  //sheaf_constants::check_lps_script_has_run();

  size_type i_size = 5;
  size_type j_size = 5;
  size_type k_size = 5;

  if(argc == 4)
  {
    i_size = static_cast<size_type>(atoi(argv[1]));
    j_size = static_cast<size_type>(atoi(argv[2]));
    k_size = static_cast<size_type>(atoi(argv[3]));
  }

  string filename = "test_case_3d.t.hdf";

  cout << "Generating test file \"" << filename << "\"" << endl;

  fiber_bundles_namespace lns("test_case_3d.t");
  lns.get_read_write_access();

  test_case_3d tc(lns, i_size, j_size, k_size);

  storage_agent sa(filename);
  sa.write_entire(lns);

  cout << "Test file \"" << filename << "\" write complete." << endl;

  return 0;
}

