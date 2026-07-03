cmake_minimum_required(VERSION 3.12)
project(tdlib_bridge)

set(NATIVE_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/${OHOS_ARCH})

add_library(tdjson SHARED IMPORTED)
set_target_properties(tdjson PROPERTIES
    IMPORTED_LOCATION ${NATIVE_LIB_DIR}/libtdjson.so
    IMPORTED_NO_SONAME TRUE
)

add_library(tdlib_bridge SHARED napi_init.cpp)

target_include_directories(tdlib_bridge PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(tdlib_bridge PUBLIC
    libhilog_ndk.z.so
    libace_napi.z.so
    tdjson
)
