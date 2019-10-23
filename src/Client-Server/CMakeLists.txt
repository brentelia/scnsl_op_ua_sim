#############################################
# General stuff.
#############################################

cmake_minimum_required(VERSION 2.8)
project(CS_test_01)

cmake_policy(SET CMP0054 OLD) 
cmake_policy(SET CMP0045 OLD)

# Setting the default build type:
SET(CMAKE_BUILD_TYPE Debug CACHE STRING
  "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)

# As default, create shared libs.
SET(BUILD_SHARED_LIBS ON CACHE BOOL "Chooses the type of libs." FORCE)

#############################################
# SCNSL.
#############################################

find_path(SCNSL_INCLUDE scnsl.hh
  PATHS $ENV{SCNSL_HOME}/include)
find_library(LIB_SCNSL scnsl
  PATHS $ENV{SCNSL_HOME}/lib)
mark_as_advanced(SCNSL_INCLUDE LIB_SCNSL)

#############################################
# Other support libs:
#############################################

find_library(LIB_DL dl)
mark_as_advanced(LIB_DL)

find_library(LIB_PTHREAD pthread)
mark_as_advanced(LIB_PTHREAD)


#############################################
# SystemC.
#############################################

find_package(SystemC)
find_systemc(LIB_SYSTEMC SYSTEMC_INCLUDE)
find_systemc_tlm(SYSTEMC_TLM_INCLUDE)

mark_as_advanced(LIB_SYSTEMC SYSTEMC_INCLUDE SYSTEMC_TLM_INCLUDE)