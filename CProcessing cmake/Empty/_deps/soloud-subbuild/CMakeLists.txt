# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 4.4.4)

# Reject any attempt to use a toolchain file. We must not use one because
# we could be downloading it here. If the CMAKE_TOOLCHAIN_FILE environment
# variable is set, the cache variable will have been initialized from it.
unset(CMAKE_TOOLCHAIN_FILE CACHE)
unset(ENV{CMAKE_TOOLCHAIN_FILE})

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(soloud-populate NONE)



include(ExternalProject)
ExternalProject_Add(soloud-populate
                     "UPDATE_DISCONNECTED" "False" "DOWNLOAD_EXTRACT_TIMESTAMP" "FALSE" "EXTERNALPROJECT_INTERNAL_ARGUMENT_SEPARATOR" "URL" "https://github.com/jarikomppa/soloud/archive/e82fd32c1f62183922f08c14c814a02b58db1873.tar.gz" "URL_HASH" "SHA256=863c5a2501ac935fb88bb357b1375e50d75876dd1f37806f4045143f46dbf3f1" "SOURCE_SUBDIR" "cprocessing-builds-this-itself"
                    SOURCE_DIR          "/Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/soloud-src"
                    BINARY_DIR          "/Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/soloud-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


