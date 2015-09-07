#include <stdio.h>
#include <stdlib.h>

#define MAX_SCORE 1000
#define MIN_SCORE 0
int main(int argc, char * argv[]) {
    int yyyy, mm, dd, hour, min, sec;
    int amflag = 0; // 1 means am, 0 means pm
    int case_count;

    if (scanf("%d", &case_count) == -1) {
        return -1;
    }

    while (case_count > 0) {
        case_count --;
        if (scanf("%d/%d/%d-%d:%d:%d", &yyyy, &mm, &dd, &hour, &min, &sec) == -1) {
            return -1;
        }
        if (hour >= 12) {
            amflag = 0;
            hour %= 12;
        } else {
            amflag = 1;
        }
        if (hour == 0) {
            hour = 12;
        }
        printf("%02d/%02d/%04d-%02d:%02d:%02d%s\n", mm, dd, yyyy, hour, min, sec, amflag?"am":"pm");
    }
    return 0;
}
