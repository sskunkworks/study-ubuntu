# 정적 라이브러리 shape 를 만든다.
# 아래는 귀찮으니까 한번에 처리
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
  )

# shpae 라이브러리를 생성하기 위해서 .cc 파일들을 통해 생성함.
add_library(shape STATIC ${SRC_FILES})

# 해당 라이브러리 컴파일 시 사용할 헤더파일 경로
target_include_directories(shape PUBLIC ${CMAKE_SOURCE_DIR}/includes)

# 해당 라이브러리를 컴파일 할 옵션
target_compile_options(shape PRIVATE -Wall -Werror)

# pthread 라이브러리를 링크
target_link_libraries(shape PRIVATE pthread)

