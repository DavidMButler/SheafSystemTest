
//
// $RCSfile: sheaves_common_binding.i,v $ $Revision: 1.21 $ $Date: 2012/03/01 00:41:16 $
//
//
// Copyright (c) 2012 Limit Point Systems, Inc.
//
//
// Common SWIG interface to sheaves cluster
//

//=============================================================================

//$$SCRIBBLE: This file contains only the part of the Swig interface which
//            is to be lists the classes, etc. to be wrapped.
//            We have to break the interface into two parts because
//            of the way Swig handles "%import" versus "%include".
//            If you change this file make sure you also change
//            "sheaves_common_binding_includes.i" as well.

//=============================================================================

// Some standard swig stuff.

%include "std_string.i"

%include "carrays.i"
%array_class(double, doubleArray);
%array_class(int, intArray);

%include "cpointer.i"
%pointer_class(double, doublePtr);
%pointer_class(int, intPtr);

//=============================================================================
// Ignore directives:
//=============================================================================

//$$TODO: Find fixes for all of these "%ignores".

%ignore *::operator=;
%ignore *::operator[];

%ignore scoped_index(primitive_type, index_map*);
%ignore scoped_index(standard_dof_tuple_index, index_map*);
%ignore scoped_index(standard_member_index, index_map*);
%ignore scoped_index(standard_subposet_index, index_map*);
%ignore scoped_index(standard_version_index, index_map*);

%ignore sheaf::scoped_index_internal_pod;
%ignore sheaf::scoped_index::operator~() const;
%ignore sheaf::scoped_index::operator==(scoped_index_internal_pod) const;
%ignore sheaf::scoped_index::operator!=(scoped_index_internal_pod) const;

//$$ISSUE: We are ignoring the following methods because swig is currently having
//         trouble with them.  It thinks that their return types are being
//         multiply defined!

%ignore sheaf::subposet::member_iterator() const;
%ignore sheaf::poset_bounds::descriptor() const;
%ignore sheaf::sum_index_map::id_space();
%ignore sheaf::product_index_map::id_space();
%ignore sheaf::sum_index_map::id_space() const;
%ignore sheaf::product_index_map::id_space() const;

//$$ISSUE: We are ignoring poset::type_id() because it is being confused with
//         poset_type_id() in poset_type.h

%ignore sheaf::poset::type_id() const;

//=============================================================================

//$$ISSUE: index_space::iterator is being confused with index_space_iterator.
//         Rename function to index_space::itr.

%rename (itr) sheaf::index_space::iterator;

//=============================================================================

//$$ISSUE: We are not currently wrapping class "factory" due to what appears
//         to be a bug in g++ version 3.4.6.

//=============================================================================

// Include the list of files to be inserted into the generated code.

%include "sheaves_common_binding_includes.i"

//=============================================================================

//$$HACK: Swig still cannot handle nested classes/structs in c++.
//        So to get "arg_list" with nested struct "arg_type" to
//        build, we do the following: first reproduce the arg_type
//        definition globally (has to be kept in sync with the one
//        in arg_list.h), then use a typedef to make the compiler happy.

struct arg_type
{
  string name;
  primitive_type type() const;
  void put_type(primitive_type xid);
  void put_type(int xid);
  primitive_value value;
  arg_type();
  arg_type(const string& xname);
};

%{
typedef sheaf::arg_list::arg_type arg_type;
%}


//=============================================================================

// The list of classes, etc for which wrappers will be generated.

//$$SCRIBBLE: Note that order is important in the following list.  It must
//            follow the class hierarchies.

//=============================================================================

%include "std_string.h"

%include "sheaf_dll_spec.h"
%include "sheaf.h"
%include "poset_type.h"
%include "pod_types.h"
%include "primitive_attributes.h"
%include "primitive_value.h"
%include "primitive_type.h"
%include "standard_dof_tuple_index.h"
%include "standard_member_index.h"
%include "standard_subposet_index.h"
%include "standard_version_index.h"
%include "dof_tuple_type.h"
%include "client_index.h"
%include "namespace_relative_member_index.h"
%include "namespace_relative_subposet_index.h"

%include "any.h"
%include       "cover_set_adapter.h"
%include             "explicit_cover_set_adapter.h"
%include                   "list_cover_set_adapter.h"
%include             "implicit_cover_set_adapter.h"
%include       "data_converter.h"
%include       "data_type_map.h"
%include             "file_data_type_map.h"
%include             "poset_data_type_map.h"
%include       "depth_first_iterator.h"
%include             "filtered_depth_first_iterator.h"
%include                   "biorder_iterator.h"
%include                   "linkorder_iterator.h"
%include                   "postorder_iterator.h"
%include                   "preorder_iterator.h"
%include                   "triorder_iterator.h"
%include       "depth_first_itr.h"
%include             "filtered_depth_first_itr.h"
%include                   "biorder_itr.h"
%include                   "linkorder_itr.h"
%include                   "postorder_itr.h"
%include                   "preorder_itr.h"
%include                   "triorder_itr.h"
%include       "error_message.h"
%include       "filtered_depth_first_member_iterator.h"
%include             "block_decomposition_iterator.h"
%include             "postorder_member_iterator.h"
%include             "preorder_member_iterator.h"
%include       "implicit_entry_map.h"
%include       "implicit_entry_map_iterator.h"
%include       "implicit_index_map_interval.h"
%include             "array_implicit_index_map_interval.h"
%include       "implicit_index_space_interval.h"
%include       "index_equivalence_class.h"
%include       "index_equivalence_iterator.h"
%include       "index_map.h"
%include             "array_implicit_index_map.h"
%include             "primitives_index_map.h"
%include             "offset_index_map.h"
%include             "mutable_index_map.h"
%include                   "array_index_map.h"
%include                   "hash_index_map.h"
%include                   "interval_index_map.h"
%include                   "sum_index_map.h"
%include                         "gluable_sum_index_map.h"
%include                         "glued_sum_index_map.h"
%include		   "product_index_map.h"
%include       "index_map_iterator.h"
%include             "array_index_map_iterator.h"
%include             "array_implicit_index_map_iterator.h"
%include             "binary_product_index_map_iterator.h"
%include             "gluable_sum_index_map_iterator.h"
%include             "interval_index_map_iterator.h"
%include             "offset_index_map_iterator.h"
%include             "stl_index_map_iterator.h"
%include             "sum_index_map_local_iterator.h"
%include             "ternary_product_index_map_iterator.h"
%include       "index_space.h"
%include             "simple_index_space.h"
%include             "sum_index_space.h"
%include             "product_index_space.h"
%include                   "explicit_product_index_space.h"
%include                   "implicit_product_index_space.h"
%include       "index_space_family.h"
%include       "index_space_iterator.h"
%include       "name_map.h"
%include       "name_multimap.h"
%include       "poset_bounds.h"
%include       "poset_bounds_descriptor.h"
%include       "poset_crg_state.h"
%include       "poset_dof_iterator.h"
%include       "poset_dof_map.h"
%include             "array_poset_dof_map.h"
%include             "namespace_poset_dof_map.h"
%include             "primitives_poset_dof_map.h"
%include       "poset_joiner.h"
%include       "poset_powerset_state.h"
%include       "poset_scaffold.h"
%include       "poset_table_state.h"
%include       "poset_traverser.h"
%include             "poset_dft.h"
%include                   "poset_orderer.h"
%include                   "poset_slicer.h"
%include       "rc_any.h"
%include             "ragged_array.h"
%include       "read_write_monitor.h"
%include             "poset_state.h"
%include       "read_write_monitor_handle.h"
%include             "poset_component.h"
%include                   "abstract_poset_member.h"
%include                         "partial_poset_member.h"
%include                               "poset_member.h"
%include                         "total_poset_member.h"
%include                               "namespace_poset_member.h"
%include                               "poset_member_iterator.h"
%include                                     "cover_set_iterator.h"
//%include                                     "filtered_iterator.h"
%include                                     "subposet_member_iterator.h"
%include                               "schema_poset_member.h"
%include                   "subposet.h"
%include             "poset_state_handle.h"
%include                   "namespace_poset.h"
%include                         "sheaves_namespace.h"
%include                   "namespace_poset_schema.h"
%include                   "poset.h"
%include                         "refinable_poset.h"
%include                   "primitives_poset.h"
%include                   "primitives_poset_schema.h"
%include       "record.h"
%include             "variable_length_record.h"
%include                   "attributes_record.h"
%include                         "dof_tuple_class_names_record.h"
%include                         "dof_tuple_col_bounds_record.h"
%include                         "dof_tuple_domain_offsets_record.h"
%include                         "dof_tuple_schema_ids_record.h"
%include                         "dof_tuple_schema_versions_record.h"
%include                         "dof_tuple_types_record.h"
%include                         "id_space_names_record.h"
%include                         "member_names_record.h"
%include                         "poset_general_record.h"
%include                         "subposet_names_record.h"
%include                         "table_dof_tuple_record.h"
%include                   "member_record.h"
%include       "record_queue.h"
%include       "record_set.h"
%include             "attributes_record_set.h"
%include             "dof_tuple_record_set.h"
%include             "member_record_set.h"
%include       "schema_descriptor.h"
%include       "sheaf_file.h"
%include       "storage_agent.h"
%include "arg_list.h"
%include "auto_block.h"
%include       "block.h"
%include             "binary_index_block.h"
%include             "id_block.h"
%include             "wsv_block.h"
%include "dof_descriptor_array.h"
%include "dof_map_factory.h"
//%include "factory.h"
%include "index_iterator.h"
%include "int_set.h"
%include "list_cover_set.h"
%include "plot.h"
%include "pool.h"
%include "poset_handle_factory.h"
%include "poset_path.h"
%include "ptr_linked_pool.h"
%include "rc_ptr.h"
%include "record_index.h"
%include "record_map.h"
%include "runnable.h"
%include "scoped_index.h"
%include "stop_watch.h"
%include "subposet_state.h"
%include "tern.h"
%include "thread.h"
%include "thread_condition_variable.h"
%include "thread_mutex.h"
%include "zn_to_bool.h"

%include "deep_size.h"

//=============================================================================

//$$ISSUE: Use %template directive to instantiate a ragged_array<scoped_index > type. 
%template(ragged_array_pmi) sheaf::ragged_array<sheaf::scoped_index >;

%template(block_double) sheaf::block<double>; 
%template(wsv_block_double) sheaf::wsv_block<double>; 

%template(index_space_family_itr) sheaf::implicit_entry_map_iterator<sheaf::index_space, sheaf::implicit_index_space_interval>;

//=============================================================================
// Swig warning messages to suppress.
//=============================================================================
#pragma SWIG nowarn=125 //  Use of the include path to find the input file is deprecated and will not work with ccache.
#pragma SWIG nowarn=302 // Identifier 'name' redefined (ignored).
#pragma SWIG nowarn=312 // Nested classes not currently supported (ignored).
#pragma SWIG nowarn=314 // 'identifier' is a lang keyword.
#pragma SWIG nowarn=315 // Nothing known about 'identifier'.
#pragma SWIG nowarn=317 // Specialization of non-template 'name'.
#pragma SWIG nowarn=325 // Nested class not currently supported.
#pragma SWIG nowarn=361 // operator! ignored.
#pragma SWIG nowarn=383 // operator++ ignored.
#pragma SWIG nowarn=384 // operator-- ignored.
#pragma SWIG nowarn=389 // perator[] ignored.
#pragma SWIG nowarn=401 // Nothing known about class 'name'. Ignored.
#pragma SWIG nowarn=451 // Setting const char * variable may leak memory.
#pragma SWIG nowarn=503 // Can't wrap 'identifier' unless renamed to a valid
                        //   identifier.
#pragma SWIG nowarn=509 // Overloaded declaration is shadowed by declaration
//                           at file:line.
#pragma SWIG nowarn=516 // Overloaded method declaration ignored. Method
                        //   declaration at file:line used.
#pragma SWIG nowarn=822 // Covariant return types not supported in Java. Proxy
                        //   method will return basetype (Java).

//=============================================================================

