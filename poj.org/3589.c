#include <stdio.h>
#include <stdlib.h>
#define N 4

int main(int argc, char * argv[]) {
    int count, i, j, k;
    char guess[N+1], answer[N+1];
    int A, B;

    if (scanf("%d", &count) == -1 || 0 == count) {
        return 1;
    }

    for (i = 0; i < count; i ++) {
        A = 0;
        B = 0;
        scanf("%s %s", guess, answer);
        for (j = 0; j < N; j ++) {
            if (guess[j] == answer[j]) {
                A++;
                continue;
            } else {
                for (k = 0; k < N; k ++) {
                    if (guess[j] == answer[k] && j != k) {
                        B++;
                    }
                }
            }
        }
        printf("%dA%dB\n", A, B);
    }
    return 0;
}
