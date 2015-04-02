#include <stdio.h>
int main(int argc, char * argv[]) {
    int height[3];
    int i;
    while(scanf("%d %d %d", &height[0], &height[1], &height[2]) == 3) {
        for (i = 0; i < 3; i ++) {
            if (height[i] <= 168) {
                printf("CRASH %d\n", height[i]);
                break;
            }
        }
        if (i == 3) {
            printf("NO CRASH\n");
        }
    }
    return 0;
}
