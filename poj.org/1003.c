#include <stdio.h>

int main(int argc, char * argv[]) {
    float total = 0.00;
    while (scanf("%f", &length)!=-1) {
        if (length == 0.00) {
            break;
        }
        length_temp = 0.00;
        i = 1;
        while (length_temp < length) {
            i ++;
            length_temp += 1.00/i;
        }
        printf("%d card(s)\n", i - 1);
    }
    return 0;
}
