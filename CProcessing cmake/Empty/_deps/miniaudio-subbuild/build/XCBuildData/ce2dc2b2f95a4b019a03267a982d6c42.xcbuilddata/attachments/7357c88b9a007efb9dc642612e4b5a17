#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp/download-miniaudio-populate.cmake
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp/verify-miniaudio-populate.cmake
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp/extract-miniaudio-populate.cmake
  /opt/homebrew/bin/cmake -E touch /Users/samuel/Documents/GitHub/gam-100-cprocessing-3-adavanta/Empty/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/miniaudio-populate-download
fi

