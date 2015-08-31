#include <stdio.h>
#include <stdlib.h>

int a, b, c, d, e, f, g, h;
long long mod(long long p, int q) {
    return (p < 0)? ((q - (-p) % q) % q): (p % q);
}

int init_array(long long * array, int length) {
    int i;
    long long temp;
    array[0] = a;
    array[1] = b;
    array[2] = c;
    for (i = 3; i < length; i ++) {
        if (i % 2 == 0) {
            temp = f * array[i-1] - d * array[i-2] + e * array[i-3];
            array[i] = mod(temp, h);
        } else {
            temp = d * array[i-1] + e * array[i-2] - f * array[i-3];
            array[i] = mod(temp, g);
        }
    }
    return 0;
}

int main(int argc, char * argv[]) {
    int case_count, case_num;
    int i;
    long long * array;

    if (scanf("%d", &case_count) == -1) {
        return 1;
    }

    for (case_num = 0; case_num < case_count; case_num ++) {
        if (scanf("%d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i) == -1) {
            return 1;
        }
        array = (long long *)malloc(sizeof(long long) * (i + 1));
        if (array == NULL) {
            return 1;
        }
        init_array(array, i + 1);
        printf("%d\n", array[i]);
        free(array);
    }
    return 0;
}
