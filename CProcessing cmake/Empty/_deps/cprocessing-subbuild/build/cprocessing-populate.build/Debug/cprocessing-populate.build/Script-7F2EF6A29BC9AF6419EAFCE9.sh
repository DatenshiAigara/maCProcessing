#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/cprocessing-subbuild/cprocessing-populate-prefix/src/cprocessing-populate-stamp/download-cprocessing-populate.cmake
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/cprocessing-subbuild/cprocessing-populate-prefix/src/cprocessing-populate-stamp/verify-cprocessing-populate.cmake
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/cprocessing-subbuild/cprocessing-populate-prefix/src/cprocessing-populate-stamp/extract-cprocessing-populate.cmake
  /opt/homebrew/bin/cmake -E touch /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/cprocessing-subbuild/cprocessing-populate-prefix/src/cprocessing-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/cprocessing-populate-download
fi

