#!/bin/bash

APP=00_blynk_led_cmsis
APP_DIR=apps
BUILD_TYPE=DEBUG
TOOLCHAIN_FILE=cmake/gnu-tools-for-stm32.cmake
BUILD_DIR=build

PROJECT_ROOT=$(pwd)
BUILD_PATH=${PROJECT_ROOT}/${BUILD_DIR}

rm -rf "${BUILD_PATH}"
mkdir -p "${BUILD_PATH}"
cd "${BUILD_PATH}"

cmake \
  -DCMAKE_TOOLCHAIN_FILE=${PROJECT_ROOT}/${TOOLCHAIN_FILE} \
  -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
  -DCMSIS_Dcore=Cortex-M3 \
  "${PROJECT_ROOT}" \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cmake --build . --target ${APP}

sudo openocd -f interface/stlink.cfg -f target/stm32f1x.cfg \
-c "program ${BUILD_PATH}/$APP_DIR/${APP}/${APP}.elf verify reset exit"