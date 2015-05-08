#include <stdio.h>
#include <stdlib.h>

#define MAX_HOUR_WISH 8

int main(int argc, char * argv[]) {
    int day_count;
    int hour_school, hour_supclass, i;
    int max_day, max_hour;

    while (scanf("%d", &day_count) != -1) {
        if (0 == day_count) {
            break;
        }
        max_day = -1;
        max_hour = -1;
        for (i = 1; i <= day_count; i ++) {
            if (scanf("%d %d", &hour_school, & hour_supclass) == -1) {
                // Format error
                return 1;
            }
            if (hour_school + hour_supclass > max_hour) {
                max_hour = hour_school + hour_supclass;
                max_day = i;
            }
        }
        printf("%d\n", max_hour <= MAX_HOUR_WISH ? 0 : max_day);
    }
    return 0;
}
