#include <stdio.h>

int main(int argc, char * argv[]) {
    int line_num;
    int i, sum;
    int speed_now, time_now, time_last;

    while (scanf("%d", &line_num)!= -1) {
        if (-1 == line_num) {
            break;
        }

        sum = 0;
        time_last = 0;
        for (i = 0; i < line_num; i ++) {
            if (scanf("%d %d", &speed_now, &time_now) == -1) {
                // read input speed & time error.
                return 1;
            }
            sum += speed_now * (time_now - time_last);
            time_last = time_now;
        }
        printf("%d miles\n", sum);
    }
    return 0;
}
