
// $Name$
//
// Copyright (c) 2013 Limit Point Systems, Inc. 
//

/// @file
/// Implementation for id space test functions.

#include "test_index_spaces.h"

#include "arg_list.h"
#include "assert_contract.h"
#include "block.h"
#include "hub_index_space_handle.h"
#include "index_space_family.h"
#include "index_space_iterator.h"
#include "mutable_index_space_handle.h"
#include "scoped_index.h"
#include "std_iomanip.h"
#include "std_iostream.h"
#include "std_strstream.h"

// ===========================================================
// INDEX_SPACE FACET
// ===========================================================

sheaf::index_space_handle&
sheaf::
make_id_space(index_space_family& xid_spaces,
	      const string& xname,
	      const string& xstate_class_name,
	      const arg_list& xstate_args)
{
  // Preconditions:

  // Body:

  // Doen't matter if the id space is persistent or not, it is not
  // going to be written to a file.

  pod_index_type lspace_id =
    xid_spaces.new_secondary_state(xname, xstate_class_name,
				   xstate_args, true);

  index_space_handle& result = xid_spaces.get_handle(lspace_id);

  print_out_subheader("Creating new id space");
  cout << "index:        " << result.index() << endl;
  cout << "name:         " << result.name() << endl;
  cout << "space:        " << xstate_class_name << endl;
  cout << endl;

  assertion(check_id_spaces(xid_spaces, lspace_id, 1));
  
  // Postconditions:

  // Exit:

  return result;
}

sheaf::pod_index_type
sheaf::
make_id_space_interval(index_space_family& xid_spaces,
		       const string& xinterval_class_name,
		       const arg_list& xinterval_args,
		       size_type xub)
{
  // Preconditions:

  // Body:

  pod_index_type lbegin =
    xid_spaces.new_secondary_interval(xinterval_class_name,
				      xinterval_args,
				      xub);

  print_out_subheader("Creating new id space interval");
  cout << "begin:        " << lbegin << endl;
  cout << "ub:           " << xub << endl;
  cout << "interval:     " << xinterval_class_name << endl;
  cout << endl;

  assertion(check_id_spaces(xid_spaces, lbegin, xub));
  
  // Postconditions:

  // Exit:

  return lbegin;
}

bool
sheaf::
check_id_spaces(index_space_family& xid_spaces,
		pod_index_type xbegin, size_type xct)
{
  bool result = true;

  for(pod_index_type i = 0; i < xct; i++)
  {
    // Test id space order iteration (i.e., domain order).

    pod_index_type lspace_id = xbegin + i;

    index_space_handle& lid_space = xid_spaces.get_handle(lspace_id);
    index_space_iterator& itr = lid_space.get_iterator();
    pod_index_type lprevious = -1;
    pod_index_type lcurrent;
    while(!itr.is_done())
    {
      lcurrent = itr.pod();
      if(is_valid(lcurrent))
      {
	if(lcurrent <= lprevious)
	{
	  cerr << "ERROR: Id space order not preserved." << endl;
	  cerr << "       space id = " << lspace_id << endl;
	  cerr << "       current  = " << lcurrent << endl;
	  cerr << "       previous = " << lprevious << endl << endl;
	  result = false;
	}

	if(itr.hub_pod() != lid_space.hub_pod(lcurrent))
	{
	  cerr << "ERROR: Hub id in the space is not equal to the iterator." << endl;
	  cerr << "       space id        = " << lspace_id << endl;
	  cerr << "       current         = " << lcurrent << endl;
	  cerr << "       lspace.hub_pod  = " << lid_space.hub_pod(lcurrent) << endl;
	  cerr << "       itr.hub_pod     = " << itr.hub_pod() << endl << endl;
	}
      }
      else
      {
	cerr << "ERROR: Invalid id in id space order." << endl;
	cerr << "       space id = " << lspace_id << endl << endl;
	result = false;
      }

      itr.next();
    }
    lid_space.release_iterator(itr);
    xid_spaces.release_handle(lid_space);
  }
  
  return result;
}

void
sheaf::
print_out_map_extrema(const index_space_handle& xid_space)
{
  print_out_subheader("Extrema for id space, '" + xid_space.name() + "'");

  cout << "ct:    " << xid_space.ct() << endl;
  cout << "begin: " << xid_space.begin() << endl;
  cout << "end:   " << xid_space.end() << endl;
  cout << endl;
}

// ===========================================================
// TOP ID SPACE FACET
// ===========================================================

void
sheaf::
delete_id(index_space_family& xid_spaces, pod_index_type xid)
{
  // Print the operation.

  strstream lstr;
  lstr << "delete_id(" << xid << ")";

  print_out_action(lstr.str());

  // Delete the id.

  xid_spaces.delete_id(xid);
}

// ===========================================================
// MUTABLE_INDEX_MAP FACET
// ===========================================================

void
sheaf::
insert(mutable_index_space_handle& xid_space,
       pod_index_type xid,
       pod_index_type xhub_id)
{
  // Print the operation.

  strstream lstr;
  lstr << "insert_entry(" << xid << ", " << xhub_id << ")";

  print_out_action(lstr.str());

  // Insert the entry.

  xid_space.insert(xid, xhub_id);
}

void
sheaf::
push_back(mutable_index_space_handle& xid_space,
	  pod_index_type xhub_id)
{
  // Print the operation.

  strstream lstr;
  lstr << "push_back(" << xhub_id << ")";

  print_out_action(lstr.str());

  // Push back the range id.

  xid_space.push_back(xhub_id);
}
  
void
sheaf::
remove(mutable_index_space_handle& xid_space,
       pod_index_type xid,
       bool xupdate_extrema)
{
  // Print the operation.

  strstream lstr;
  lstr << "remove(" << xid << ", "
       << (xupdate_extrema ? "true" : "false") << ")";

  print_out_action(lstr.str());

  // Remove the id.

  xid_space.remove(xid, xupdate_extrema);
}

void
sheaf::
remove_hub(mutable_index_space_handle& xid_space,
	   pod_index_type xhub_id,
	   bool xupdate_extrema)
{
  // Print the operation.

  strstream lstr;
  lstr << "remove_hub(" << xhub_id << ", "
       << (xupdate_extrema ? "true" : "false") << ")";

  print_out_action(lstr.str());

  // Remove the id.

  xid_space.remove_hub(xhub_id, xupdate_extrema);
}

void
sheaf::
update_extrema(mutable_index_space_handle& xid_space)
{
  // Print the operation.

  print_out_action("update_extrema()");

  // Update the extrema.

  xid_space.update_extrema();
}

void
sheaf::
gather(mutable_index_space_handle& xid_space)
{
  // Print the operation.

  print_out_action("gather()");

  // Gather the map.

  xid_space.gather();
}

void
sheaf::
clear(mutable_index_space_handle& xid_space)
{
  // Print the operation.

  print_out_action("clear()");

  // Clear the map.

  xid_space.clear();
}

// ===========================================================
// ITERATOR FACET
// ===========================================================

void
sheaf::
test_iterator(const index_space_handle& xid_space)
{
  // Preconditions:

  // Body:

  index_space_iterator& itr = xid_space.get_iterator();
  test_iterator(itr);
  xid_space.release_iterator(itr);

  // Postconditions:

  // Exit:

  return;
}

void
sheaf::
test_iterator(index_space_iterator& xitr)
{
  // Preconditions:

  // Body:

  string lname;

  if(xitr.name().empty())
  {
    strstream lstr;
    lstr << xitr.index();
    lstr >> lname;
  }
  else
  {
    lname = xitr.name();
  }

  print_out_subheader("Iterating over id space: '" + lname + "'");

  while(!xitr.is_done())
  {
    cout << "id: " << setw(14) << left << xitr.pod();
    cout << "hub id: " << xitr.hub_pod();
    cout << endl;
    xitr.next();
  }
  cout << endl;

  // Postconditions:

  // Exit:

  return;
}

// ===========================================================
// Convenience functions
// ===========================================================

void
sheaf::
print_out_header(const string& xtext)
{
  // Preconditions:

  // Body:

  static const string nl("\n");
  static const string s = "=======================================";
  static const string sep = s + s;

  cout << nl << sep << nl << xtext << nl << sep << nl;
  cout << endl;

  // Postconditions:

  // Exit:  

  return;
}

void
sheaf::
print_out_subheader(const string& xtext)
{
  // Preconditions:

  // Body:

  static const string nl("\n");

  cout << nl << "======== " << xtext << " ========" << nl;
  cout << endl;

  // Postconditions:

  // Exit:

  return;
}

void
sheaf::
print_out_action(const string& xtext)
{
  // Preconditons:

  // Body:

  cout << ">>>>>>>> " << xtext << endl;

  // Postconditions:

  // Exit:

  return;
}

