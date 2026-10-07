#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/cprocessing-subbuild
  /opt/homebrew/bin/cmake -Dcfgdir=/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME -P /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/cprocessing-subbuild/cprocessing-populate-prefix/tmp/cprocessing-populate-mkdirs.cmake
  /opt/homebrew/bin/cmake -E touch /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/cprocessing-subbuild/cprocessing-populate-prefix/src/cprocessing-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/cprocessing-populate-mkdir
fi

