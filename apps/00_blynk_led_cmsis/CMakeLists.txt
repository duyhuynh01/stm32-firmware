# =============================================================================
# Target: 00_blynk_led
# =============================================================================

set(APP_NAME "00_blynk_led_cmsis")

# -----------------------------------------------------------------------------
# Sources
# -----------------------------------------------------------------------------
set(APP_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/freertos_hooks.c
)

# -----------------------------------------------------------------------------
# Include directories
# -----------------------------------------------------------------------------
set(APP_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# -----------------------------------------------------------------------------
# Linker script
# -----------------------------------------------------------------------------
set(LINKER_SCRIPT
    ${CMAKE_CURRENT_SOURCE_DIR}/../../common/linker/stm32f103x8_flash.ld
)

# -----------------------------------------------------------------------------
# Target definition
# -----------------------------------------------------------------------------
add_executable(${APP_NAME})

target_sources(${APP_NAME}
    PRIVATE
        ${APP_SOURCES}
)

target_include_directories(${APP_NAME}
    PRIVATE
        ${APP_INCLUDE_DIRS}
)

# -----------------------------------------------------------------------------
# Link libraries
# -----------------------------------------------------------------------------
target_link_libraries(${APP_NAME}
    PRIVATE
        common_core
        stm32_base_settings
)

# -----------------------------------------------------------------------------
# Linker options
# -----------------------------------------------------------------------------
target_link_options(${APP_NAME}
    PRIVATE
        -T${LINKER_SCRIPT}
        -Wl,-Map=${APP_NAME}.map
)

# -----------------------------------------------------------------------------
# Properties
# -----------------------------------------------------------------------------
set_target_properties(${APP_NAME} PROPERTIES
    LINK_DEPENDS ${LINKER_SCRIPT}
)

# -----------------------------------------------------------------------------
# Post-build: size + hex/bin
# -----------------------------------------------------------------------------
add_custom_command(TARGET ${APP_NAME} POST_BUILD
    COMMAND ${CMAKE_SIZE}    $<TARGET_FILE:${APP_NAME}>
    COMMAND ${CMAKE_OBJCOPY} -O ihex   $<TARGET_FILE:${APP_NAME}> ${APP_NAME}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${APP_NAME}> ${APP_NAME}.bin
    COMMENT "Generating HEX/BIN and printing size"
)