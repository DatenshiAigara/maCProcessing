#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/soloud-subbuild/soloud-populate-prefix/src/soloud-populate-stamp/download-soloud-populate.cmake
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/soloud-subbuild/soloud-populate-prefix/src/soloud-populate-stamp/verify-soloud-populate.cmake
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/soloud-subbuild/soloud-populate-prefix/src/soloud-populate-stamp/extract-soloud-populate.cmake
  /opt/homebrew/bin/cmake -E touch /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/soloud-subbuild/soloud-populate-prefix/src/soloud-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/soloud-populate-download
fi

