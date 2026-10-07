#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/soloud-subbuild
  /opt/homebrew/bin/cmake -E make_directory /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/soloud-subbuild/CMakeFiles/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME
  /opt/homebrew/bin/cmake -E touch /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/soloud-subbuild/CMakeFiles/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/soloud-populate-complete
  /opt/homebrew/bin/cmake -E touch /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/soloud-subbuild/soloud-populate-prefix/src/soloud-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/soloud-populate-done
fi

