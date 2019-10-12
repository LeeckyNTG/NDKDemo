cmake_minimum_required(VERSION 3.4.1)


add_library(
        file_utils
        SHARED
        ../c/file_utils.c)


find_library(
        log-lib
        log)


target_link_libraries(
        file_utils
        ${log-lib})