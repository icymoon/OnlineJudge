#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {
    int col_num, i, j, len;
    char msg[1024];

    while (scanf("%d", &col_num)!= -1) {
        if (col_num <= 0) {
            break;
        }
        if (scanf("%s", msg) == -1) {
            return 1;
        }
        len = (int)strlen(msg);
        for (i = 0; i < col_num; i ++) {
            for(j = 0; j < len/col_num; j++) {
                printf("%c", (j % 2 == 0) ? (msg[i + col_num * j]): (msg[col_num - 1 - i + col_num * j]));
            }           
        }
        printf("\n");
    }
    return 0;
}
