#include <stdio.h>

int main(int argc, char * argv[]) {
    int city_cnt, i, m, kill_cnt, pos, ignore_cnt = 0;
    int num[150];
    int flag;
    while (scanf("%d", &city_cnt) == 1) {
        if (city_cnt <= 0) {
            break;
        }
        m = 1;
        flag = 0;
        while (m < 10 * city_cnt) {
            m ++;
            num[1] = 0;
            for (i = 1; i < city_cnt; i ++) {
                num[i] = 1;
            }
            kill_cnt = 1;
            pos = 1;
            ignore_cnt = 0;
            while (kill_cnt < city_cnt) {
                if (pos >= city_cnt) {
                    pos = pos % city_cnt;
                }

                if (num[pos] == 0) {
                    pos ++;
                    continue;
                } else {
                    if (ignore_cnt == (m - 1)) {
                        num[pos] = 0;
                        kill_cnt ++;
                        if (pos == 1) {
                            if (kill_cnt == city_cnt) {
                                flag = 1;
                                printf("%d\n", m);
                                break;
                            } else if (kill_cnt < city_cnt) {
                                flag = 2;
                                break;
                            }
                        }
                        pos ++;
                        ignore_cnt = 0;
                    } else {
                        ignore_cnt ++;
                        pos ++;
                        continue;
                    }
                }
            }
            if (flag == 1) {
                break;
            }
        }
    }
    return 0;
}
