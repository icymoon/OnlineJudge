#include <stdio.h>

#define RESULT_LENGTH 200
#define POWER_LENGTH 6
int print_result(int * r, int float_flag) {
    int i;
    int first_num_not_zero = -1;
    int last_num_not_zero = RESULT_LENGTH;
    
    if (r == NULL) {
        return 1;
    }

    for (i = 0; i < RESULT_LENGTH; i ++) {
        if (r[i] == 0) {
            continue;
        } else {
            first_num_not_zero = i;
            break;
        }
    }

    if (first_num_not_zero < 0) {
        printf("\n");
        return;
    }

    for (i = RESULT_LENGTH - 1; i >= 0; i --) {
        if (r[i] == 0) {
            continue;
        } else {
            last_num_not_zero = i;
            break;
        }
    }

    if (float_flag == 0) {
        for(i = first_num_not_zero; i < RESULT_LENGTH; i ++) {
            printf("%d", r[i]);
        }
        printf("\n");
        return;
    }

    if (float_flag > RESULT_LENGTH) {
        // Overflow, according to the input range, you can never reach here.
        // DEBUG
        // printf("float_flag = %d\n", float_flag);
        printf("\n");
        return;
    }

    if ((RESULT_LENGTH - float_flag) <= first_num_not_zero) {
        printf(".");
        for (i = 0; i < first_num_not_zero - (RESULT_LENGTH - float_flag); i ++) {
            printf("0");
        }
        for(i = first_num_not_zero; i <= last_num_not_zero; i ++) {
            printf("%d", r[i]);
        }
    } else {
        for (i = first_num_not_zero; i < RESULT_LENGTH - float_flag; i ++) {
            printf("%d", r[i]);
        }
        if (RESULT_LENGTH - float_flag >= last_num_not_zero) {
            printf("\n");
            return;
        }
        printf(".");
        for(i = RESULT_LENGTH - float_flag; i <= last_num_not_zero; i ++) {
            printf("%d", r[i]);
        }
    }
    printf("\n");
}

int main(int argc, char * argv[]) {
    int n, i, j, k, l, m;
    char s[7]; 
    int result[RESULT_LENGTH], temp[POWER_LENGTH][RESULT_LENGTH], s_int[POWER_LENGTH];
    int float_flag = 0;

    for (m = 0; m < POWER_LENGTH; m ++) {
        for (l = 0; l < RESULT_LENGTH; l ++) {
            temp[m][l] = 0;
        }
    }

    while (scanf("%s%d", s, &n)==2) {
        s[POWER_LENGTH] = '\0';

        // Special case, R^0 = 1;
        if (n == 0) {
            printf("1\n");
            continue;
        }

        for (i = 0; i < RESULT_LENGTH; i ++) {
            result[i] = 0;
        }
        float_flag = 0;

        // Init multiplier and float_flag which is set when multiplier is a float
        for (i = 0; i < POWER_LENGTH; i ++) {
            if (s[i] == '.') {
                float_flag = 5 - i;
            }
            s_int[i] = s[i] - '0';
            result[i+RESULT_LENGTH-POWER_LENGTH] = s_int[i];
        }
        // Fix float to integer
        if (float_flag != 0) {
            for(i = 5 - float_flag; i > 0; i --) {
                s_int[i] = s[i-1] - '0';
                result[i+RESULT_LENGTH-POWER_LENGTH] = s_int[i-1];
            }
            s_int[0] = 0;
            result[194] = 0;
            float_flag = float_flag * n;
        }

        // Loop for R^(i+2)
        for (i = 1; i < n; i ++) {
            // Loop for R^(i+1)*R
            for(k = 5; k >=0; k --) {
                for (j = 199; j >= 0 && j + k - 5 >= 0 ; j --) {
                    temp[k][j+k-5] = result[j] * s_int[k];
                }
            }

            for (m = 0; m < RESULT_LENGTH; m ++) {
                result[m] = 0;
            }

            for (m = 0; m < POWER_LENGTH; m ++) {
                for (l = 0; l < RESULT_LENGTH; l ++) {
                    result[l] += temp[m][l];
                }
            }

            for (m = 199; m >= 0; m --) {
                if (result[m] >= 10) {
                    int last = result[m] % 10;
                    int other = result[m] / 10;
                    result[m-1] += other;
                    result[m] = last;
                }
            }

            // Get R^(i+1)*R, then set temp[][] to 0.
            for (m = 0; m < POWER_LENGTH; m ++) {
                for (l = 0; l < RESULT_LENGTH; l ++) {
                    temp[m][l] = 0;
                }
            }
        }
        print_result(result, float_flag);
    }
    return 0;
}
