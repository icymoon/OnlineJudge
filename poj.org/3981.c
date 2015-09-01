#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define STR_LEN 1001
int main(int argc, char * argv[]) {
    char str[STR_LEN];
    int len = 0;
    int i;
    memset(str, 0, sizeof(char)*STR_LEN);
    while (gets(str) != NULL) {
        len = strlen(str);
        for (i = 0; i < len - 2; i ++) {
            if (str[i] == 'y' && str[i+1] == 'o' && str[i+2] == 'u') {
                str[i] = 'w';
                str[i+1] = 'e';
                str[i+2] = '\0';
                i += 2;
            }
        }
        for (i = 0; i < len; i ++) {
            if(str[i] != '\0') {
                printf("%c", str[i]);
            }
        }
        printf("\n");
        memset(str, 0, sizeof(char)*STR_LEN);
    }
    return 0;
}
