#include "func.h"

int main(int argc, char *argv[])
{
    //ͨ�������в���ָ���ı�·�������ļ��ж�ȡ�ı�����ʾ�ڱ༭���С����������в���ʱ����ʾ"Hello, World!"��������ʾ�ļ����ݡ�
    char *f1 = argv[1];         // ./Level3 file.txt
    FILE *fp1 = fopen(f1, "r+"); 

    if (fp1 == NULL)
    {
        printf("error opening the file");
        return -1;
    }   

    enableRawMode(fp1);

    fclose(fp1); // �ر��ļ�ָ��
    return 0;
}