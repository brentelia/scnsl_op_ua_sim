
cmake_minimum_required(VERSION 2.8)
project(scnsl_opc_ua)

cmake_policy(SET CMP0054 OLD) 


#############################################
# Inclusions.
#############################################

# Setting extra modules path:
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/scripts)

##############################
#sources
set(
    OPC_UA_SRCS 
    src/Node_Type.cpp
    src/Client-Server/Client_Task_if.cpp
    src/Client-Server/Server_Task_if.cpp
    src/Node_Type.cpp

)
##########
# FIND SYSC AND SCNSL
##########
find_path(SCNSL_INCLUDE scnsl.hh
  PATHS $ENV{SCNSL_HOME}/include)
find_library(LIB_SCNSL scnsl
  PATHS $ENV{SCNSL_HOME}/lib)
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
#####################
#headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/scnsl_opc-ua)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/scnsl_opc-ua/Client-Server)
include_directories(SYSTEM ${SCNSL_INCLUDE} ${SYSTEMC_INCLUDE} ${SYSTEMC_TLM_INCLUDE})

find_package(EdalabTargets) #edalab scripts for installation

edalab_add_library(opc_ua SHARED STATIC ${OPC_UA_SRCS})

target_link_libraries(
  opc_ua
  )
edalab_install_headers(TOOLS ${CMAKE_CURRENT_SOURCE_DIR}/include)
edalab_install_headers(TOOLS ${CMAKE_CURRENT_SOURCE_DIR}/include/scnsl_opc-ua)
edalab_install_headers(TOOLS ${CMAKE_CURRENT_SOURCE_DIR}/include/scnsl_opc-ua/Client-Server)
  
edalab_install_targets(TOOLS opc_ua)
