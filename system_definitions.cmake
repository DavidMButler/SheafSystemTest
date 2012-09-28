#
# $RCSfile: system_definitions.cmake,v $ $Revision $ $Date $
#
#
# Copyright (c) 2012 Limit Point Systems, Inc.
#
#
# This file is the system level counterpart to the component_definitions file
# found in the top level of any component. Functions and variables
# that need to have system scope should be declared and/or defined here.
#

#
# Establish the list of components in this system
#
set(COMPONENTS sheaves_test fiber_bundles_test geometry_test fields_test CACHE STRING "List of components in this system" FORCE)

# Set backward compatibility so we can link to modules. If not, we can't link to the bindings libs.
set(CMAKE_BACKWARDS_COMPATIBILITY 2.2 CACHE STRING "backward compat so we can link to bindings libs")

#
# Platform definitions
#

# OS is 64 bit Windows, compiler is cl 
if(CMAKE_HOST_SYSTEM_NAME MATCHES "Windows" AND MSVC AND CMAKE_SIZEOF_VOID_P MATCHES "8")
    set(WIN64MSVC ON CACHE BOOL "MS compiler in use.")
# OS is 64 bit Windows, compiler is icl
elseif(CMAKE_HOST_SYSTEM_NAME MATCHES "Windows" AND CMAKE_CXX_COMPILER_ID MATCHES "Intel" AND CMAKE_SIZEOF_VOID_P MATCHES "8")
    set(WIN64INTEL ON CACHE BOOL "Intel compiler in use.")
# OS is 64 bit linux, compiler is g++
elseif(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux" AND CMAKE_COMPILER_IS_GNUCXX AND CMAKE_SIZEOF_VOID_P MATCHES "8")
    set(LINUX64GNU ON CACHE BOOL "GNU compiler in use.")
# OS is 64 bit linux, compiler is icpc
elseif(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux" AND CMAKE_CXX_COMPILER_ID MATCHES "Intel" AND CMAKE_SIZEOF_VOID_P MATCHES "8")
    set(LINUX64INTEL ON CACHE BOOL "Intel compiler in use.")
    message(STATUS "Using Intel compiler")    
else()
    message(FATAL_ERROR "A 64 bit Windows or Linux environment was not detected; exiting")
endif()

set(EXPORTS_FILE ${PROJECT_NAME}-exports.cmake CACHE STRING "System exports file name")

# Windows has a notion of Debug and Release builds. For practical purposes, "Release" is
# equivalent to "not Debug". We'll carry that notion through to linux/gcc as well for now, with
# "Release" equivalent to "!-g"
set(CMAKE_CONFIGURATION_TYPES Debug-contracts Debug-no-contracts Release-contracts Release-no-contracts CACHE
    STRING "Supported configuration types"
    FORCE)

#
# Delete the exports file at the start of each cmake run
#
execute_process(COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/${EXPORTS_FILE})

#
# Set the default build type.
#
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug-contracts" CACHE STRING
      "Choose the type of build, options are: ${CMAKE_CONFIGURATION_TYPES}."      
      FORCE)
endif(NOT CMAKE_BUILD_TYPE)

#
# True if we want geometry to link against VTK
#
set(USE_VTK CACHE BOOL "Set to link geometry against VTK libs.")

#
# $$HACK Toggle intel compiler warnings.
#
set(INTELWARN CACHE BOOL "Toggle Intel compiler warnings")

#   
#  Type of system documentation to build: Dev or User
#
if(NOT LPS_DOC_STATE)
    set(LPS_DOC_STATE Dev CACHE STRING "Type of documentation to build: [Dev|User]")
endif()

#
# Set compiler optimization level.
#

set(OPTIMIZATION_LEVEL "0" CACHE STRING "Compiler optimization level. Valid values for are 0,1,2,3, and \"s\(Linux only\)\". Default is 0. \n Linux values translate to -On. \n\n Windows values are: \n\n 0 = /0d \(no optimization\) \n 1 = /O1 \(Minimize Size\) \n 2 = /O2 \(Maximize Speed\) \n 3 = /GL \(Whole Program Optimization\) \n ")

#
# Add solvers and tools if linux
#
if(LINUX64GNU OR LINUX64INTEL)
    set(COMPONENTS ${COMPONENTS} solvers_test CACHE STRING "List of components in this system" FORCE)
    #set(COMPONENTS ${COMPONENTS} solvers tools CACHE STRING "List of components in this system" FORCE)
endif()

#
# Default linux installation location is /usr/local
# Set a default where the user has write permission ; in this
# case, the top of the components source tree.
# "lib", "include", and "bin" will be appended to this location.
# See "add_install_target" in cmake_modules/LPSCommon.cmake for source.
#
if(LINUX64GNU OR LINUX64INTEL)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR} CACHE STRING "System install location")
elseif(WIN64MSVC OR WIN64INTEL)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR} CACHE STRING "System install location")
endif()

#
# Establish the version number for this build.
# This is only relevant for releases. 1.1.1 is chosen here
# simply as a stub.
#
set(LIB_VERSION 1.1.1 CACHE STRING "Library version number for release purposes")
mark_as_advanced(LIB_VERSION)

#
# Set the cmake module path.
#
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules CACHE STRING "Location of Cmake modules")

#
# Targets with global scope are declared and optionally defined in 
# target_declarations.cmake; otherwise defined at first use.
#
include(${CMAKE_MODULE_PATH}/target_declarations.cmake)

#
# Prerequisite discovery
#
include(${CMAKE_MODULE_PATH}/find_prerequisites.cmake)

#
# Utility function to add a component to a system.
#
function(add_components)

    foreach(comp ${COMPONENTS})
        clear_component_variables(${comp})
        add_subdirectory(${comp})
    endforeach()

endfunction(add_components)

#
# Clear cached variables at the start of each cmake run.
#
function(clear_component_variables comp)

    string(TOUPPER ${comp} COMP)

    # clear the srcs vars so consecutive cmake runs don't
    # list the same sources n times.
    unset(${COMP}_SRCS CACHE)
    
    # clear the unit tests var so consecutive cmake runs don't
    # list the same sources n times.
    unset(${COMP}_UNIT_TEST_SRCS CACHE)

    # clear the example binaries var so consecutive cmake runs don't
    # list the same sources n times.
    unset(${COMP}_EXAMPLE_SRCS CACHE)
    
    # clear the unit tests var so consecutive cmake runs don't
    # list the same unit tests n times.
    unset(${COMP}_UNIT_TESTS CACHE)
    
    # clear the unit tests var so consecutive cmake runs don't
    # list the same includes n times.
    unset(${COMP}_INCS CACHE)
    
    # clear the ipath var so consecutive cmake runs don't
    # list the same include paths n times.
    unset(${COMP}_IPATH CACHE)

endfunction(clear_component_variables)

#
# Set compiler optimization level.
#
function(set_optimization_level)

    if(LINUX64GNU OR LINUX64INTEL)
        if(${OPTIMIZATION_LEVEL} STREQUAL 0)
            set(OPTIMIZATION "-O" PARENT_SCOPE)
        elseif(${OPTIMIZATION_LEVEL} STREQUAL 1)
            set(OPTIMIZATION "-O1" PARENT_SCOPE)
        elseif(${OPTIMIZATION_LEVEL} EQUAL 2)
            set(OPTIMIZATION "-O2" PARENT_SCOPE)
        elseif(${OPTIMIZATION_LEVEL} STREQUAL 3)
            set(OPTIMIZATION "-O3" PARENT_SCOPE)
        elseif(${OPTIMIZATION_LEVEL} STREQUAL s)
            set(OPTIMIZATION "-Os" PARENT_SCOPE)
        else()
            break()
        endif()   # anything else, exit.
    elseif(WIN64MSVC OR WIN64INTEL)
        if(${OPTIMIZATION_LEVEL} STREQUAL 0)
            set(OPTIMIZATION "/Od" PARENT_SCOPE)    
        elseif(${OPTIMIZATION_LEVEL} STREQUAL 1)
            set(OPTIMIZATION "/O1" PARENT_SCOPE)
        elseif(${OPTIMIZATION_LEVEL} EQUAL 2)
            set(OPTIMIZATION "/O2" PARENT_SCOPE)
        elseif(${OPTIMIZATION_LEVEL} STREQUAL 3)
            set(OPTIMIZATION "/GL" PARENT_SCOPE)    
        endif()
    endif()    

endfunction(set_optimization_level)

# 
#  Make emacs tags
#
function(add_tags_target)

    if(LINUX64GNU OR LINUX64INTEL)
        add_custom_target(tags
            COMMAND find ${CMAKE_CURRENT_SOURCE_DIR} -name build -prune -o -name "*.cc" -print -o -name "*.h" -print -o -name "*.t.cc" -print | etags --c++ --members -
        )
    endif()

endfunction(add_tags_target) 
