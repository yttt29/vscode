#include "func.h"

int main(int argc, char *argv[])
{
    //通过命令行参数指定文本路径，从文件中读取文本并显示在编辑器中。当无命令行参数时，显示"Hello, World!"，否则显示文件内容。
    char *f1 = argv[1];         // ./Level3 file.txt
    FILE *fp1 = fopen(f1, "r+"); 

    if (fp1 == NULL)
    {
        printf("error opening the file");
        return -1;
    }   

    enableRawMode(fp1);

    fclose(fp1); // 关闭文件指针
    return 0;
}