#include <stdio.h>
#include <math.h>

#define LINE_LENGTH 256

int result_array[10000000];
int get_number_from_char(char input_char) {
    if (input_char < 'Q') {
        return (input_char - 'A')/3 + 2;
    } else if (input_char < 'Z') {
        return (input_char - 'Q')/3 + 7;
    }
    return 0;
}

int print_result() {
    int i;
    int noresult_flag = 1;
    for (i = 0; i < 10000000; i ++) {
        if (result_array[i] > 1) {
            noresult_flag = 0;
            printf("%03d-%04d %d\n", i/10000, i%10000, result_array[i]);
        }
    }
    if (noresult_flag) {
        printf("No duplicates.\n");
    }
}

int main(int argc, char * argv[]) {
    int line_count, i, j, num_count = 0;
    int new;
    char s[LINE_LENGTH];

    if (scanf("%d", &line_count) != 1) {
        return 1;
    }

    while (line_count --) {
        new = 0;
        num_count = 7;
        for (i = 0; i < LINE_LENGTH; i ++) {
            s[i] = '\0';
        }
        if (scanf("%s", s) != 1) {
            break;
        }
        for (j = 0; j < LINE_LENGTH && s[j] != '\0'; j ++) {
            if (s[j] == '-') {
                continue;
            }
            if (s[j] >= 'A' && s[j] <= 'Y') {
                num_count --;
                new += get_number_from_char(s[j]) * (int)(pow(10, num_count));
            } else if (s[j] >= '0' && s[j] <= '9') {
                num_count --;
                new += (s[j] - '0') * (int)(pow(10, num_count));
            }
        }
        result_array[new] ++;
    }
    print_result();
    return 0;
}
