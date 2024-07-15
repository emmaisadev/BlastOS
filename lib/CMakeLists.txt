include(/usr/share/pico-sdk/pico_sdk_init.cmake)
pico_sdk_init()
add_library(gryphen_lib
    "display.c"
)

setup_standards(gryphen_lib)

target_include_directories(gryphen_lib PUBLIC "include")
target_link_libraries(gryphen_lib ssd_1306_lib hardware_i2c)
