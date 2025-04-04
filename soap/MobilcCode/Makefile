# 编译器
CC = gcc

# 库路径
LIB_PATH = /home/yuanjl/soap/gsoap-2.8/_install/include/
LIB_INS_PATH = /home/yuanjl/soap/gsoap-2.8/_install/lib/

# 编译选项
CFLAGS = -Wall -g -I$(LIB_PATH)

# 链接选项
LDFLAGS = -L $(LIB_INS_PATH) -lgsoap

# 目标可执行文件
TARGET = a.out

# 源文件
SRCS = main.c soapC.c soapClient.c

# 对象文件
OBJS = $(SRCS:.c=.o)

# 默认目标
all: $(TARGET)

# 链接对象文件生成可执行文件
$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# 编译源文件生成对象文件
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


# 清理生成的文件
clean:
	@rm -f $(OBJS) $(TARGET) *.o
