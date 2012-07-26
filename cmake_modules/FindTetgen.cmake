#
# $RCSfile: FindTetgen.cmake,v $ $Revision: 1.6 $ $Date: 2012/07/05 19:18:14 $
#
#
# Copyright (c) 2012 Limit Point Systems, Inc.
#
#

# Look for Tetgen.
# This modules defines the following variables:
#
# TETGEN_FOUND
# TETGEN_LIB
# TETGEN_LIB_DIR
# TETGEN_INC_DIR
#

#
# Initialize the found variable
#
set(TETGEN_FOUND 0)

#
# Find the tetgen lib
#
if(WIN64MSVC OR WIN64INTEL)
	find_library(TETGEN_LIB NAMES tetgen HINTS $ENV{USERPROFILE}/LPS/prerequisites/tetgen/lib)
	find_path(TETGEN_LIB_DIR tetgen.lib
          HINTS $ENV{USERPROFILE}/LPS/prerequisites/tetgen/lib)
          
	# And the include path
	find_path(TETGEN_INC_DIR tetgen.h
          HINTS $ENV{USERPROFILE}/LPS/prerequisites/tetgen/include)
else()
	find_library(TETGEN_LIB NAMES tetgen HINTS $ENV{HOME}/LPS/prerequisites/tetgen/lib  /usr/local/tetgen/lib)
	find_path(TETGEN_LIB_DIR libtetgen.so
          HINTS $ENV{HOME}/LPS/prerequisites/tetgen/lib /usr/local/tetgen/lib)
          
	# And the include path
	find_path(TETGEN_INC_DIR tetgen.h
          HINTS $ENV{HOME}/LPS/prerequisites/tetgen/include /usr/local/tetgen/include)
endif()

IF(EXISTS ${TETGEN_LIB})
    set(TETGEN_FOUND 1)
endif()



          