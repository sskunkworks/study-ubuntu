# CMAKE 최소 버전
cmake_minimum_required(VERSION 3.10)

# 프로젝트 정보
project(
  Test
  VERSION 0.1
  DESCRIPTION "예제 프로젝트"
  LANGUAGES CXX)

add_executable (program main.cc foo.cc)
target_compile_options(program PUBLIC -Wall -Werror)

# includes에 header 파일을 넣을 때 링크 시켜 주기 위함
#target_include_directories(program PUBLIC ${CMAKE_SOURCE_DIR}/inclues)

# program에 shape를 링크
target_link_libraries(program shape)
# 확인할 디렉토리 추가
add_subdirectory(lib)

