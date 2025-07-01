#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 1024   // 每行最大长度


/* row structure */
typedef struct erow{
    int row_idx;                
    int row_size;               
    char *row_contents;         
} erow;

int ReadRow(FILE *fp);

/* readrow wrong version : malloc 
int ReadRow(FILE *fp)
{
    int line_num = 0;           // row index
    int line_len = 0;           // row length
    char buf[LINE_MAX] = {0};   // row buffer

    erow *row = (erow *)malloc(1);  // store every line of file

    while(fgets(buf, LINE_MAX, fp)){
        row = (erow *)realloc(row, ++line_num);

        line_len = strlen(buf);

        if ('\n' == buf[line_len - 1]) {    // kick '\n'
			buf[line_len - 1] = '\0';
			line_len--;
			if (0 == line_len) {    // empty line
				continue;
			}
		}

        row[line_num - 1].row_idx = line_num;   
        row[line_num - 1].row_size = line_len;  
        row[line_num - 1].row_contents = buf;
        printf("row %d : %s %d\n", row[line_num - 1].row_idx, row[line_num - 1].row_contents, row[line_num - 1].row_size);  
    }

    if (0 == feof) {
		// 未读到文件末尾
		printf("fgets error\n");	
		return -1;
	}
	fclose(fp);

    return 1;
}*/
int ReadRow(FILE *fp)
{
    int line_num = 0;           // row index
    int line_len = 0;           // row length
    char buf[LINE_MAX] = {0};   // row buffer
    erow row[4];                // store every line of file

    while(fgets(buf, LINE_MAX, fp)){        // read by lines
        line_num++;
        line_len = strlen(buf);

        if ('\n' == buf[line_len - 1]) {    // kick '\n'
			buf[line_len - 1] = '\0';
			line_len--;
			if (0 == line_len) {            // empty line
				continue;
			}
		}

        row[line_num - 1].row_idx = line_num;   
        row[line_num - 1].row_size = line_len;  
        row[line_num - 1].row_contents = buf;
        printf("%s\n",row[line_num - 1].row_contents);  
    }

    if (0 == feof) {
		// 未读到文件末尾
		printf("fgets error\n");	
		return -1;
	}
	fclose(fp);

    return 1;
}
