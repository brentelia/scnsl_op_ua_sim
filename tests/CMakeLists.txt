
cmake_minimum_required(VERSION 2.8)
project(scnsl_opc_ua_tests)

cmake_policy(SET CMP0054 OLD) 



##############################
#sources

set(
  CS1
  C-S_test_01/src/ClientTaskImpl.cpp
  C-S_test_01/src/main.cpp
  C-S_test_01/src/ServerTaskImlp.cpp
  )

  # Setting extra modules path:
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/scripts)

##########
# FIND SYSC AND SCNSL
##########
find_path(SCNSL_INCLUDE scnsl.hh
  PATHS $ENV{SCNSL_HOME}/include)
find_library(LIB_SCNSL scnsl  PATHS $ENV{SCNSL_HOME}/lib)
mark_as_advanced(SCNSL_INCLUDE LIB_SCNSL)

find_library(LIB_DL dl)
mark_as_advanced(LIB_DL)

find_library(LIB_PTHREAD pthread)
mark_as_advanced(LIB_PTHREAD)

find_package(SystemC)
find_systemc(LIB_SYSTEMC SYSTEMC_INCLUDE) # from FINDSYSTEMC script
find_systemc_tlm(SYSTEMC_TLM_INCLUDE)
mark_as_advanced(LIB_SYSTEMC SYSTEMC_INCLUDE SYSTEMC_TLM_INCLUDE)

find_path(OPC_UA_INCLUDE scnsl_opc-ua.hpp
  PATHS /usr/local/scnsl_opc_ua/include)

find_library(OPC_UA opc_ua PATHS /usr/local/scnsl_opc_ua/lib)
  
mark_as_advanced(OPC_UA_INCLUDE OPC_UA)

#############################################
# Inclusions.
#############################################

include_directories(SYSTEM ${SCNSL_INCLUDE} ${SYSTEMC_INCLUDE} ${SYSTEMC_TLM_INCLUDE} ${OPC_UA_INCLUDE})
include_directories(C-S_test_01/include)
add_executable(CS1 ${CS1})
target_link_libraries(CS1 ${LIB_SCNSL} ${LIB_SYSTEMC} ${LIB_DL} ${OPC_UA})

SET(EXE_TARGETS
  CS1
  )

SET(TEST_TARGETS
  ${EXE_TARGETS}
  )

install(TARGETS ${EXE_TARGETS}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)