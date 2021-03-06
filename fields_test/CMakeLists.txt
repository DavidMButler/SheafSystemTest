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

#
# Announce current status.
#
ShfSysTst_status_message("Processing fields_test component")

#
# Define the clusters for this component.
#
set(clusters fields iterators pushers refiners template_instantiations)

#
# Include functions and definitions common to all components.
# .
include(${SHFSYSTST_CMAKE_MODULE_PATH}/component_functions.cmake)

#
# Include the functions and variable definitions unigue to this component.
#
include(${CMAKE_CURRENT_SOURCE_DIR}/component_definitions.cmake)

#
# Initialize all variables for this component.
#
ShfSysTst_set_component_variables(fields_test)

#
# Add the clusters to the project
#
ShfSysTst_add_clusters("${clusters}")

#
# Set the ipath variable.
#
ShfSysTst_set_component_ipath_variable(fields_test "${clusters}")

#
# Add the library targets
#
ShfSysTst_add_fields_test_library_targets()

#
# Add the unit test targets
#
ShfSysTst_add_component_unit_test_targets(fields_test)

#
# Add the example targets
#
ShfSysTst_add_component_example_targets(fields_test)

#
# Component specific check target
#
ShfSysTst_add_component_check_target(fields_test)

#
# Component specific check target
#
ShfSysTst_add_component_bin_target(fields_test)

#
# Component specific coverage target
#
if(ENABLE_COVERAGE)

    ShfSysTst_status_message("Creating coverage target for fields_test")
    ShfSysTst_add_component_coverage_target(fields_test)

endif()
