#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    int case_count;
    int outlet_count, power_num, i, power_num_per_outlet;

    if (scanf("%d", &case_count) == -1 || case_count == 0) {
        return 1;
    }
    while (case_count > 0) {
        case_count --;
        power_num = 0;
        if (scanf("%d", &outlet_count) == -1) {
            continue;
        }
        if(outlet_count == 0) {
            printf("0\n");
            continue;
        } else {
            for (i = 0; i < outlet_count; i ++) {
                scanf("%d", &power_num_per_outlet);
                power_num += power_num_per_outlet;
            }
        }
        printf("%d\n", power_num - outlet_count + 1);
    }
    return 0;
}
