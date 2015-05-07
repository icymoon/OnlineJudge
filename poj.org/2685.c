#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_LEN 9

int print_num(int num) {
    int num_result[4];
    char mcxi[5] = "mcxi\0";
    int i, mulp;
    for (i = 0; i < 4; i ++) {
        mulp = pow(10, 3 - i);
        num_result[i] = num / mulp;
        num -= (num / mulp) * mulp;
    }
    for (i = 0; i < 4; i ++) {
        if (num_result[i] > 1) {
            printf("%d", num_result[i]);
        }
        if (num_result[i] > 0) {
            printf("%c", mcxi[i]);
        }
    }
    printf("\n");
}

int get_num(char * str_num, int len) {
    int i;
    int multipler, num = 0, num_temp = -1;
    if (len < 0 || len > (NUM_LEN - 1)) {
        return -1;
    }
    for (i = 0; i < len; i ++) {
        if (str_num[i] >= '2' && str_num[i] <= '9') {
            num_temp = str_num[i] - '0';
        } else {
            switch (str_num[i]) {
                case 'm':
                    multipler = 1000;
                    break;
                case 'c':
                    multipler = 100;
                    break;
                case 'x':
                    multipler = 10;
                    break;
                case 'i':
                    multipler = 1;
                    break;
                default:
                    multipler = 0;
                    break;
            }

            if (multipler == 0) {
                return -1;
            }
            if (num_temp < 0) {
                num_temp = 1;
            }
            num += multipler * num_temp;
            num_temp = -1;
        }
    }
    return num;
}

int main(int argc, char * argv[]) {
    int count;
    char str_num1[NUM_LEN], str_num2[NUM_LEN];
    int len1, len2;
    int num1, num2;
    
    if (scanf("%d", &count) == -1 || count == 0) {
        return 1;
    }

    while (count > 0) {
        count --;
        if (scanf("%s %s", str_num1, str_num2) == -1) {
            continue;
        }
        num1 = get_num(str_num1, strlen(str_num1));
        num2 = get_num(str_num2, strlen(str_num2));
        if (num1 < 0 || num2 < 0) {
            continue;
        }
        print_num(num1+num2);
    }
    return 0;
}
