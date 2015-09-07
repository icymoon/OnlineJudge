#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 16
#define MAX_CHILDREN_NUM 64 

int main(int argc, char * argv[]) {
    int count, i, alive;
    int w, s;
    char names[MAX_CHILDREN_NUM][NAME_LEN];

    if (scanf("%d", &count) == -1 || count == 0) {
        return 1;
    }

    for (i = 0; i < count; i ++) {
        if (scanf("%s", names[i]) == -1) {
            return -1;
        }
    }
    scanf("%d,%d", &w, &s);

    alive = count;
    w -= 2;
    while(alive > 0) {
        i = 0;
        while (i < s) {
            w ++;
            w %= count;
            if (names[w][0] != '\0') {
                i ++;
            }
        }
        printf("%s\n", names[w]);
        names[w][0] = '\0';
        alive --;
    }
    return 0;
}
