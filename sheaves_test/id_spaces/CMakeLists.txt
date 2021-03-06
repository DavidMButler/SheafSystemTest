#
# Copyright (c) 2013 Limit Point Systems, Inc. 
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

#------------------------------------------------
# Programmer Filename Entry Section
#------------------------------------------------

set(CLUSTER ${CMAKE_CURRENT_BINARY_DIR})

#
# Library sources.
#
set(SRCS
    test_index_spaces.cc
   )

ShfSysTst_collect_sources(sheaves_test "${SRCS}")

#
# Headers that are NOT associated with a .cc file.
#
set(ADDITIONAL_INCS
    test_index_space.impl.h
   )
  
ShfSysTst_collect_includes(sheaves_test "${SRCS}" "${ADDITIONAL_INCS}")

#
# Source for unit test executables.
#
set(UNIT_TEST_SRCS
    array_index_space.t.cc
    array_index_space_interval.t.cc
    constant_index_space_interval.t.cc
    explicit_index_space.t.cc
    forwarding_index_space.t.cc
    hash_index_space.t.cc
    index_space_family.t.cc
    index_space_interval.t.cc
    interval_index_space.t.cc
    mutable_index_space.t.cc
    list_index_space.t.cc
    offset_index_space.t.cc
    primary_index_space.t.cc
    ragged_array_index_space_interval.t.cc
    reserved_primary_index_space.t.cc
    singleton_index_space.t.cc
    singleton_index_space_interval.t.cc
    sum_index_space.t.cc
    product_structure.t.cc
   )

ShfSysTst_collect_unit_test_sources(sheaves_test "${UNIT_TEST_SRCS}")

#
# Source for example executables.
#
set(EXAMPLE_SRCS

   )

ShfSysTst_collect_example_sources(sheaves_test "${EXAMPLE_SRCS}")
