add_library(gryphen_lib
    "display.c"
)
target_include_directories(gryphen_lib PUBLIC "include")
set_property(TARGET gryphen_lib PROPERTY C_STANDARD 11)
