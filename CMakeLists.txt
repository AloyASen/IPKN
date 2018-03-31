cmake_minimum_required(VERSION 3.5)
project (blockchain)

set(PROGRAM_NAME ${PROJECT-NAME})
set(CXX "clang++")

# The version number shown by the parser software that matters.
set (PARSE_VERSION_MAJOR "0" CACHE STRING "the Current successful release version")
set (PARSE_VERSION_MINOR "001" CACHE STRING "development beta changes inducted")
set (PARSE_VERSION_PATCH "0" CACHE STRING "Patch distribution release number ")

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -W -Werror -pedantic -g")
set(CMAKE_CXX_FLAGS "-O3 -Wall -W  -std=c++11")


add_subdirectory(src)

#the versioning of the release tools that the system is to provide 
set(CPACK_PACKAGE_VERSION_MAJOR ${PARSE_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PARSE_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PARSE_VERSION_PATCH})
set(LIB_VERSION_STRING ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH})
set_target_properties(${PROGRAM_NAME} PROPERTIES VERSION ${LIB_VERSION_STRING})
set (CPACK_RESOURCE_FILE_LICENSE  
     "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_CONTACT "Support on IPKN <adysenlab@gmail.com>")


set(CPACK_GENERATOR "DEB")
include (CPack)