#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 11

int main(int argc, char * argv[]) {
    char num1[N], num2[N];
    int len1, len2, i, j;
    int sum = 0;
    scanf("%s %s", num1, num2);
    len1 = strlen(num1);
    len2 = strlen(num2);
    for (i = 0; i < len1; i ++) {
        for (j = 0; j < len2; j ++) {
            sum += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    printf("%d\n", sum);
    return 0;
}
