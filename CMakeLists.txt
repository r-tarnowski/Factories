cmake_minimum_required(VERSION 3.0.2)
project(Factories)

set(CMAKE_BUILD_TYPE Release)

set(SRC_DIR src)
set(LIB_DIR lib)
set(BIN_DIR bin)
set(INCLUDE_DIR include)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

set(TARGET_FACTORY_METHOD factory_method)
set(TARGET_FACTORY factory)
set(TARGET_INTERNAL_FACTORY internal_factory)

include_directories(${INCLUDE_DIR} "/export/devel/platform/boost/$ENV{BOOST_VERSION}/boost/include")

link_directories( ${LIB_DIR} )
#set(APP_LINK_LIBS ${TARGET_LIB} dcpsisocpp2 ddskernel dl pthread)

set(CMAKE_CXX_FLAGS "-fPIC -O3 -Wall -Wno-unused-function -std=c++20")

set(SOURCES_FACTORY_METHOD ${SRC_DIR}/FactoryMethod.cpp)
set(SOURCES_FACTORY ${SRC_DIR}/Factory.cpp)
set(SOURCES_INTERNAL_FACTORY ${SRC_DIR}/InternalFactory.cpp)

#add_library(${TARGET_LIB} STATIC ${SOURCES_LIB})

add_executable(${TARGET_FACTORY_METHOD} ${SOURCES_FACTORY_METHOD})
add_executable(${TARGET_FACTORY} ${SOURCES_FACTORY})
add_executable(${TARGET_INTERNAL_FACTORY} ${SOURCES_INTERNAL_FACTORY})



#target_link_libraries(${TARGET_SUB} ${APP_LINK_LIBS})

#add_dependencies( ${TARGET_SUB} ${TARGET_LIB} )
