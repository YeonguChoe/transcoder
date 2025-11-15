cmake_minimum_required(VERSION 3.18)
project(transcoder LANGUAGES CUDA CXX)

find_package(CUDAToolkit REQUIRED)

add_executable(transcoder main.cpp decoder.cu)

# 헤더 파일 경로만 지정
target_include_directories(transcoder PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ffnvcodec
    ${CUDAToolkit_INCLUDE_DIRS}
)

# 런타임 라이브러리 링킹 (필수)
target_link_libraries(transcoder
    CUDA::cudart # CUDA 런타임
    CUDA::cuda_driver # CUDA 드라이버
)
