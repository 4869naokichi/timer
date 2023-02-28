add_library(timer SHARED)
target_sources(timer PRIVATE timer.cpp)
target_include_directories(timer PUBLIC ${PROJECT_SOURCE_DIR}/include)