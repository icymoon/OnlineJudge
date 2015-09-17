#include <stdlib.h>
#include <stdio.h>

#define WIDTH 8

int main(int argc, char * argv[]) {
    int n, m, c;
    while(scanf("%d %d %d", &n, &m, &c) != -1) {
        if (n == 0 && m == 0 && c == 0) {
            break;
        }
        if (n < WIDTH || m < WIDTH || (n == WIDTH && m == WIDTH && c == 0)) {
            printf("0\n");
            continue;
        }
        printf("%d\n", ((n - 7) * (m - 7) + c) / 2);
    }
    return 0;
}
