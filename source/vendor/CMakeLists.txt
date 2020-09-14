include(FetchContent)

FetchContent_Declare(
  doctest
  GIT_REPOSITORY  https://github.com/onqtam/doctest.git
  GIT_TAG         2.3.7
)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

FetchContent_MakeAvailable(doctest googletest)
