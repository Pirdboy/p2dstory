# Makefile的写法，在多模块和单个模块上有区别，如何统一是个问题
# Makefile需要的内容
# 源文件所在
# 要生成的目标
# 编译器指定
# 编译选项
# 编译目标，如果是子目录，则make -c 
# 清除目标

# 注意静态模式，编译选项，伪目标，include

# 初步
# 编译选项包括： 编译期选项 -c，链接期选项 -o，两步一定要分开写
#	编译器还包括include， 链接器主要是库文件，库文件路径记得先加上$(LDPATH)
# $(subst ee,EE,you a ee)  # $(subst from,to,text)
# $(patsubst %.o,%.c,$(APP_FILES))
# $(wildcard)
# patsubst更简单的写法是$(APP_FILES:patt1=patt2), $(CFILES:%.cc=%.o)
# 要注意的坑是，库文件要写到可执行程序的后面
# 将all和clean写到伪目标里去.PHONY
# all作为默认目标
# %@ 表示正在被处理的那个target（多个目标时，会一个一个取出然后处理），$<表示依赖集中的第一个（主要用于静态模式，在静态模式下表示一个一个取出并使用静态模式）
# %^表示依赖集全部
# 目标集可以指定多个，然后会对每一个单独用依赖关系处理

# 中级
# -MM与.d文件（依赖集描述文件）
# -g与Core Dump

CXX		:= g++
CFLAGS := -std=c++14 -Wall -Wextra -Wno-unused-parameter -D ASIO_STANDALONE
SRC1 := $(wildcard gateway/*.cpp)
SRC2 := $(wildcard test/*.cpp)
SRC3 := $(wildcard comm/*.cpp)
SRC4 := $(wildcard proto/*.cc)
OBJ1 := $(SRC1:.cpp=.o)
OBJ2 := $(SRC2:.cpp=.o)
OBJ3 := $(SRC3:.cpp=.o)
OBJ4 := $(SRC4:.cc=.o)


INCLUDE	:= -I/Users/pird/include -I./comm -I./proto `pkg-config --cflags protobuf`
LIB		:= `pkg-config --libs protobuf`
APP_CFLAGS = $(CFLAGS) $(INCLUDE)

.PHONY: all clean

all: build/gateway_server build/test_client

%.o: %.cc
	$(CXX) -c $(APP_CFLAGS) $< -o $@

%.o: %.cpp
	$(CXX) -c $(APP_CFLAGS) $< -o $@

build/gateway_server: $(OBJ1) $(OBJ3) $(OBJ4)
	mkdir -p build
	$(CXX) -o $@ $^ $(LIB)

build/test_client: $(OBJ2) $(OBJ3) $(OBJ4)
	mkdir -p build
	$(CXX) -o $@ $^ $(LIB)

clean:
	rm -rf build $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)
