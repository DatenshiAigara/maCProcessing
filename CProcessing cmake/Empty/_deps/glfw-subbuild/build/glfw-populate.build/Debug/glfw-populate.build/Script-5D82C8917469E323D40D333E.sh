#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/download-glfw-populate.cmake
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/verify-glfw-populate.cmake
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/extract-glfw-populate.cmake
  /opt/homebrew/bin/cmake -E touch /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/glfw-populate-download
fi

