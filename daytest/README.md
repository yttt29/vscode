# 种子班日测

完成了 Level 0-2 的内容

## 代码结构

### main.c：

读取终端输入的文件路径，传入 enableRawMode()

### Level1.c：

enableRawMode()中：

1. 切换 raw mode
2. ReadRow() 按行显示读取的文件
3. 实时响应键盘按键，包括：方向键移动光标、backspace清屏、回车换行、其他按键显示 ASCII 码（Page Up/Down、Home、End 没做出来）

### Level3.c：

1. 定义行结构 erow 
2. ReadRow() 按行显示读取的文件

## 历程

Level0-2 还好，查找资料学会了ANSI转义序列的处理等

Level3 做任务1“行查看器的实现”的时候出现问题：

定义了数组 erow[] 用于按行存放读取到的内容，但在使用 malloc 的时候一直报错

后来删除了 malloc 部分，想实现固定行数的读取，但是读取显示出来后仍然报错，显示 free 函数的问题。没有显式的 malloc 却报 free 的错，查了很久没搞明白

离开了 AI 感觉不会写代码了