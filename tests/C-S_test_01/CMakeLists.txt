cmake_minimum_required(VERSION 2.8)
project(scnsl_opc_ua_tests)
cmake_policy(SET CMP0054 OLD) 

# Setting extra modules path:
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/scripts)

##########
# FIND SYSC AND SCNSL
# SYSC 2.3.1 IS REQUIRED
# SCNSL 2.0.1 IS REQUIRED 
find_path(SCNSL_INCLUDE scnsl.hh
  PATHS $ENV{SCNSL_HOME}/include
)
find_library(LIB_SCNSL scnsl
  PATHS $ENV{SCNSL_HOME}/lib
)
mark_as_advanced(SCNSL_INCLUDE LIB_SCNSL)

find_library(LIB_DL dl)
mark_as_advanced(LIB_DL)

find_library(LIB_PTHREAD pthread)
mark_as_advanced(LIB_PTHREAD)

find_package(SystemC)
find_systemc(LIB_SYSTEMC SYSTEMC_INCLUDE) # from FINDSYSTEMC script
find_systemc_tlm(SYSTEMC_TLM_INCLUDE)
mark_as_advanced(LIB_SYSTEMC SYSTEMC_INCLUDE SYSTEMC_TLM_INCLUDE)

find_path(OPC_UA_INCLUDE scnsl_opc-ua.hpp PATHS /usr/local/Opc_ua/include)
find_library(OPC_UA opc_ua_static PATHS /usr/local/Opc_ua/lib)
mark_as_advanced(OPC_UA_INCLUDE OPC_UA)


#####################
#include directories

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(SYSTEM ${OPC_UA_INCLUDE} ${SCNSL_INCLUDE} ${SYSTEMC_INCLUDE} ${SYSTEMC_TLM_INCLUDE})

##############################
#sources

set( CS1_SRCS
  src/main.cpp
  src/ServerTaskImpl.cpp
  src/ClientTaskImpl.cpp
)

add_executable(cs_test_1 ${CS1_SRCS})
target_link_libraries(cs_test_1 ${OPC_UA} ${LIB_SCNSL} ${LIB_SYSTEMC} ${LIB_DL})
