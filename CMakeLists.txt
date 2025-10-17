cmake_minimum_required(VERSION 3.16)
project(HMS C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Build main only (it includes other .c files)
add_executable(hms src/main.c)

# Windows console dependencies
if (WIN32)
  target_compile_definitions(hms PRIVATE HMS_WINDOWS=1)
  target_link_libraries(hms PRIVATE user32 kernel32)
endif()
