cmake_minimum_required(VERSION 3.13)


include(/usr/share/pico-sdk/pico_sdk_init.cmake)

project(gryphen LANGUAGES C CXX)


pico_sdk_init()

add_compile_options(-Wall
    -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
    -Wno-unused-function # we have some for the docs that aren't called
    )
if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wno-maybe-uninitialized)
endif()

add_subdirectory(lib)
add_subdirectory(lib/ssd1306)

add_executable(gryphen
    main.c
)

set_property(TARGET gryphen PROPERTY C_STANDARD 11)
set_property(TARGET gryphen PROPERTY CXX_STANDARD 17)
target_link_libraries(gryphen gryphen_lib ssd_1306_lib pico_stdlib hardware_i2c)

pico_add_extra_outputs(gryphen)
