# 这是一个makefile文件

TARGET = hello	# = 延迟赋值 后面的赋值会影响他的值
CC := g++		# := 立即赋值  后面的赋值不会影响他的值
CC ?= g++		# 前面没有定义就定义，前面有定义不再定义
CC += -g		# 拼接 CC = g++ -g
 
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)	#变量的替换引用，把hello.c的.c替换成.o

debug:
	@echo "hello world"
	@echo $(SRC)
	@echo $(OBJ)

$(TARGET): $(SRC)          
	@$(CC) -o $@ $^

compile: $(TARGET)

clean:
	@rm hello -r

.PHONY: clean compile