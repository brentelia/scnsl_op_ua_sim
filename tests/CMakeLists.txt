#############################################
# General CMake skeleton.
#############################################
#
# @author Francesco Stefanni
#

#
# HOWTO
#
# To configure these CMakeLists to your project,
# just check the vars in this files, and adapt the .deps.txt file.
#
# Sections in this file:
# - General.
# - Inclusions.
# - Svn.
# - Install.
# - CPack.
# - Doxygen.
#

#############################################
# General stuff.
#############################################

cmake_minimum_required(VERSION 2.8)
project(scnsl_test CXX)

cmake_policy(SET CMP0054 OLD) 
cmake_policy(SET CMP0045 OLD)

# Setting the default build type:
SET(CMAKE_BUILD_TYPE Debug CACHE STRING
  "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)

SET(CMAKE_INSTALL_PREFIX ~/scnsl_${CMAKE_SYSTEM_PROCESSOR}/ CACHE PATH "Default install directory." FORCE)

# As default, create shared libs.
SET(BUILD_SHARED_LIBS ON CACHE BOOL "Chooses the type of libs." FORCE)

# Adding a target doc.
get_target_property(DOC_TARGET doc TYPE)
if(NOT DOC_TARGET)
  add_custom_target(doc)
endif(NOT DOC_TARGET)


#############################################
# Inclusions.
#############################################

# Setting extra modules path:
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/scripts)

# Including general support:
include(${PROJECT_SOURCE_DIR}/scripts/CMakeLists.support.txt)

# Including common definitions and settings.
include(${PROJECT_SOURCE_DIR}/scripts/CMakeLists.defs.txt)


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

#############################################
# Revision.
#############################################

find_package(Revision)
find_revision(${PROJECT_SOURCE_DIR} SOURCES_REVISION)
if(NOT SOURCES_REVISION)
  SET(SOURCES_REVISION 0)
endif(NOT SOURCES_REVISION)

#message("REVISION NUMBER: ${SOURCES_REVISION}")

#############################################
# Install.
#############################################


include(CMakeLists.install)


#############################################
# Targets.
#############################################

# Including targets and dependencies.
include(${PROJECT_SOURCE_DIR}/CMakeLists.deps.txt)

