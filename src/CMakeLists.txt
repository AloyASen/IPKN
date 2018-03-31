
############################################################
# Create a library
############################################################
add_library(hello_library SHARED 
    Hello.cpp
)
add_library(hello::library ALIAS hello_library)

target_include_directories(hello_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

############################################################
# Create a Doxygen documentation
############################################################


if (CMAKE_BUILD_TYPE MATCHES "^[Rr]elease")
    # first we can indicate the documentation build as an option and set it to ON by default
    option(BUILD_DOC "Build documentation" ON)

    # check if Doxygen is installed
    find_package(Doxygen
                REQUIRED dot
                OPTIONAL_COMPONENTS mscgen dia)
    if (DOXYGEN_FOUND)
        # set input and output files
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/../docs/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
        
        # request to configure the file
        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
        message("Doxygen will build HTML sources when generated")

        # note the option ALL which allows to build the docs together with the application
        add_custom_target( doc ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
    else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
    endif (DOXYGEN_FOUND)
endif()

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(hello_binary
    main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( hello_binary
    PRIVATE 
        hello::library
)