# 定义可执行文件变量
executbale := LinkList
# 定义源文件列表变量
sources := main.c LinkList.c
# 使用变量的引用替换，定义object文件列表
objects := $(sources:.c=.o)
# 定义编译命令变量
CC := gcc

# 终极目标规则，生成LinkList可执行文件
$(executbale): $(objects)
#  使用自动化变量改造我们的编译命令
	$(CC) -o $@ $^

# 子规则1, main.o的生成规则
main.o: main.c
	$(CC) -o $@  -c $<

# 子规则2，LinkList.o的生成规则
complicated.o: LinkList.c
	$(CC) -o $@  -c $<