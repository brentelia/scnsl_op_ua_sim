cmake_minimum_required(VERSION 2.8)
project(scnsl_opc_ua CXX)
cmake_policy(SET CMP0054 OLD) 

# Setting extra modules path:
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/scripts)
SET(CMAKE_CXX_FLAGS "-g")
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
#####################

#include directories

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(SYSTEM ${SCNSL_INCLUDE} ${SYSTEMC_INCLUDE} ${SYSTEMC_TLM_INCLUDE})

##############################

#sources
set(OPC_UA_SRCS 
  src/Client-Server/Client_Task_if.cpp
  src/Client-Server/Server_Task_if.cpp
  #src/Node_Type.cpp
)
############################
#static and shared library
add_library(opc_ua_static STATIC ${OPC_UA_SRCS})
add_library(opc_ua_shared SHARED ${OPC_UA_SRCS})
#linking both libraries
target_link_libraries(opc_ua_static ${LIB_SCNSL} ${LIB_SYSTEMC})
target_link_libraries(opc_ua_shared ${LIB_SCNSL} ${LIB_SYSTEMC})

#############################
#install static and shared library
install(TARGETS opc_ua_static opc_ua_shared
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
#install headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
  DESTINATION .
  FILES_MATCHING # install only matched files
  PATTERN "*.hpp" # select header files
)
############################
#test
#add_subdirectory(tests/C-S_test_01/)
