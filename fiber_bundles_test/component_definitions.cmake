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

#------------------------------------------------------------------------------
# FUNCTION DEFINITION SECTION
#------------------------------------------------------------------------------

#
# Create the library targets for this component.
#
function(ShfSysTst_add_fiber_bundles_test_library_targets)

   #message("Entering fiber_bundles_test/component_definitions.cmake:add_library_targets")

   # Preconditions:

   dbc_require_or(SHFSYSTST_WINDOWS SHFSYSTST_LINUX)

   # Body

   if(SHFSYSTST_WINDOWS)
      
      # Create the DLL.

      add_library(${FIBER_BUNDLES_TEST_DYNAMIC_LIB} SHARED ${FIBER_BUNDLES_TEST_SRCS})
      target_include_directories(${FIBER_BUNDLES_TEST_DYNAMIC_LIB}
         PUBLIC ${FIBER_BUNDLES_TEST_IPATH} ${CMAKE_BINARY_DIR}/include)
      target_link_libraries(${FIBER_BUNDLES_TEST_DYNAMIC_LIB}
         PUBLIC ${SHEAVES_TEST_IMPORT_LIB} ${FIBER_BUNDLES_IMPORT_LIB})
      set_target_properties(${FIBER_BUNDLES_TEST_DYNAMIC_LIB} PROPERTIES FOLDER "Library Targets")

      # Override cmake's placing of "${FIBER_BUNDLES_TEST_DYNAMIC_LIB}_EXPORTS into the preproc symbol table.

      set_target_properties(${FIBER_BUNDLES_TEST_DYNAMIC_LIB} PROPERTIES DEFINE_SYMBOL "SHEAF_DLL_EXPORTS")

   elseif(SHFSYSTST_LINUX)
      
      # Static library

      add_library(${FIBER_BUNDLES_TEST_STATIC_LIB} STATIC ${FIBER_BUNDLES_TEST_SRCS})
      add_dependencies(${FIBER_BUNDLES_TEST_STATIC_LIB} ${SHEAVES_TEST_STATIC_LIB} ${FIBER_BUNDLES_STATIC_LIB})
      target_include_directories(${FIBER_BUNDLES_TEST_STATIC_LIB} PUBLIC ${FIBER_BUNDLES_TEST_IPATH})
      target_link_libraries(${FIBER_BUNDLES_TEST_STATIC_LIB} ${SHEAVES_TEST_STATIC_LIB} ${FIBER_BUNDLES_STATIC_LIB})
      set_target_properties(${FIBER_BUNDLES_TEST_STATIC_LIB} PROPERTIES OUTPUT_NAME fiber_bundles_test )

      # Shared library      

      add_library(${FIBER_BUNDLES_TEST_SHARED_LIB} SHARED ${FIBER_BUNDLES_TEST_SRCS})
      add_dependencies(${FIBER_BUNDLES_TEST_SHARED_LIB} ${SHEAVES_TEST_SHARED_LIB} ${FIBER_BUNDLES_SHARED_LIB})
      target_include_directories(${FIBER_BUNDLES_TEST_SHARED_LIB} PUBLIC ${FIBER_BUNDLES_TEST_IPATH})
      target_link_libraries(${FIBER_BUNDLES_TEST_SHARED_LIB} ${SHEAVES_TEST_SHARED_LIB} ${FIBER_BUNDLES_SHARED_LIB})
      set_target_properties(${FIBER_BUNDLES_TEST_SHARED_LIB} PROPERTIES OUTPUT_NAME fiber_bundles_test)
      set_target_properties(${FIBER_BUNDLES_TEST_SHARED_LIB} PROPERTIES LINKER_LANGUAGE CXX)
      set_target_properties(${FIBER_BUNDLES_TEST_SHARED_LIB} PROPERTIES VERSION ${LIB_VERSION}) 
      
      # Override cmake's placing of "${COMPONENT_LIB}_EXPORTS into the preproc symbol table.
      # CMake apparently detects the presence of cdecl_dllspec in the source and places
      # -D<LIBRARY>_EXPORTS into the preproc symbol table no matter the platform.

      set_target_properties(${FIBER_BUNDLES_TEST_SHARED_LIB} PROPERTIES DEFINE_SYMBOL "")
      
      # Library alias definitions

      add_custom_target(fiber_bundles_test-static-lib)
      add_dependencies(fiber_bundles_test-static-lib ${FIBER_BUNDLES_TEST_STATIC_LIB})

      add_custom_target(fiber_bundles_test-shared-lib)
      add_dependencies(fiber_bundles_test-shared-lib ${FIBER_BUNDLES_TEST_SHARED_LIB})
      
   endif()

   #message("Leaving fiber_bundles_test/component_definitions.cmake:add_library_targets")

endfunction(ShfSysTst_add_fiber_bundles_test_library_targets)

# 
#  Append file types to CMake's default clean list.
#
function(ShfSysTst_add_clean_files)
   
   #Define the file types to be included in the clean operation.
   
   file(GLOB_RECURSE HDF_FILES ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/*.hdf)
   file(GLOB_RECURSE CSV_FILES ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/*.csv)
   
   if(ENABLE_COVERAGE)  

      # Clean up the mess left by the Intel coverage tool

      file(GLOB_RECURSE DYN_FILES ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/*.dyn)
      file(GLOB_RECURSE DPI_FILES ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/*.dpi)
      file(GLOB_RECURSE SPI_FILES ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/*.spi)

   endif()                

   # Append them to the list

   set(LCLEAN_FILES ${HDF_FILES} ${CSV_FILES})
   set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${LCLEAN_FILES}")

endfunction(ShfSysTst_add_clean_files) 
