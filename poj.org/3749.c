#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG_LEN 201
char dst[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char src[26] = "VWXYZABCDEFGHIJKLMNOPQRSTU";

int main(int argc, char * argv[]) {
    char msg[MSG_LEN];
    int i;

    memset(msg, 0, MSG_LEN);
    while (gets(msg) != NULL) {
        if (strlen(msg) == 10 * sizeof(char) && strncmp(msg, "ENDOFINPUT", 10) == 0) {
            break;
        }
        if (strlen(msg) == 3 * sizeof(char) && strncmp(msg, "END", 3) == 0) {
            continue;
        }
        if (strlen(msg) == 5 && strncmp(msg, "START", 5) == 0) {
            memset(msg, 0, MSG_LEN);
            gets(msg);
            for (i = 0; i < strlen(msg); i ++) {
                if (msg[i] >= 'A' && msg[i] <= 'Z') {
                    printf("%c", src[dst[msg[i]-'A']-'A']);
                } else {
                    printf("%c", msg[i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
