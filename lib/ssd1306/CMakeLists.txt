include(/usr/share/pico-sdk/pico_sdk_init.cmake)
pico_sdk_init()
add_library(ssd_1306_lib
    "ssd1306.c"
)

setup_standards(ssd_1306_lib)

target_link_libraries(ssd_1306_lib pico_stdlib hardware_i2c)
