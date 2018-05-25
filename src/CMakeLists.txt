
############################################################
# Create a library
############################################################



            # =================================================
            ## Create a sublibrary - Memory Manager 
            # ==================================================
            #add_library(hello_library SHARED 
            #    Hello.cpp
            #)
            #add_library(hello::library ALIAS hello_library)


            # ------------------------------------------


            add_library(mem_library SHARED 
                MMan.cc
            )
            add_library(memory::library ALIAS mem_library)

target_include_directories(mem_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

#    ############################################################
#    # Access boost libraries
#    ############################################################
#    set(Boost_INCLUDE_DIR "/opt/lib/include" CACHE PATH " Boost header file directory ")
#    set(Boost_LIBRARY_DIR "/opt/lib/lib" CACHE PATH " boost libraries directory ")
#    # find a boost install with the libraries filesystem and system
#    find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)
#
#    # check if boost was found
#    if(Boost_FOUND)
#        message ("boost found")
#    else()
#        message (FATAL_ERROR "Cannot find Boost")
#    endif()
#
#    # Add an executable
#    # add_executable(imported_targets main.cpp)
#
#    # link against the boost libraries
#    #target_link_libraries( imported_targets PRIVATE  Boost::filesystem)
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
        memory::library
)