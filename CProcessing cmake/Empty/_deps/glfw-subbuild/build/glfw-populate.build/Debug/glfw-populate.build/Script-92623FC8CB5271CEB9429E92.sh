#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/glfw-subbuild
  /opt/homebrew/bin/cmake -E make_directory /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/glfw-subbuild/CMakeFiles/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME
  /opt/homebrew/bin/cmake -E touch /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/glfw-subbuild/CMakeFiles/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/glfw-populate-complete
  /opt/homebrew/bin/cmake -E touch /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/glfw-populate-done
fi

