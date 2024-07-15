cmake_minimum_required(VERSION 3.13)

macro(setup_standards target_name)
    target_compile_options(${target_name}
        PRIVATE -Wall
        PRIVATE -Wextra
        PRIVATE -pedantic
    )
    set_property(TARGET ${target_name} PROPERTY C_STANDARD 11)
    set_property(TARGET ${target_name} PROPERTY CXX_STANDARD 17)
endmacro()


include(/usr/share/pico-sdk/pico_sdk_init.cmake)

project(gryphen LANGUAGES C CXX)


pico_sdk_init()

add_subdirectory(lib)
add_subdirectory(lib/ssd1306)

add_executable(gryphen
    main.c
)

setup_standards(gryphen)

target_link_libraries(gryphen gryphen_lib ssd_1306_lib pico_stdlib hardware_i2c)

pico_add_extra_outputs(gryphen)
