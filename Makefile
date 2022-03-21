CC = g++
# 컴파일러 옵션
CXXFLAGS = -Wall -O2

# 링커 옵션
LDFLAGS = 

# 소스 파일 디렉토리
SRC_DIR = ./src

# 오브젝트 파일 디렉토리
OBJ_DIR = ./obj

# 생성하고자 하는 실행 파일 이름
TARGET = main

# Make할 소스 파일들
# wildcard로 SRC_DIR에서 *.cpp 파일 목록을 뽑아낸 뒤에 
# notdir로 파일 이름만 뽑아낸다. 
# SRC = foo.cpp bar.cpp fifo_test.cpp
SRC = $(notdir $(wildcard $(SRC_DIR)/*.cpp))

OBJS = foo.o bar.o fifo_test.o

# OBJS 안의 object 파일들 이름 앞에 $(OBJ_DIR)/ 을 붙인다.
OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))
# include 명령어를 통해 .o를 .d로 대체한다.
DPES = $(OBJECTS:.o=.d)

all: main

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp 
	$(CC) $(CXXFLAGS) -c $< -o $@ -MD $(LDFALGS)

$(TARGET) : $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFALGS)

.PHONY : clean all
clean:
	rm -f %(OBJECTS) $(DEPS) $(TARGET)

-include $(DEPS)
