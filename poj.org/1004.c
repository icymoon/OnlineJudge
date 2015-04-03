#include <stdio.h>

int main(int argc, char * argv[]) {
    float account = 0.00,total = 0.00;
    while (scanf("%f", &account)!=-1) {
        total += account;
    }
    printf("$%.2f\n", total/12);
    return 0;
}
