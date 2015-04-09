#include <stdio.h>

int main(int argc, char * argv[]) {
    int p, e, i, d, day_cnt, p_cnt, result;
    int p_len = 23, e_len = 28, i_len = 33;
    int case_count = 0;
    while (scanf("%d %d %d %d", &p, &e, &i, &d) != -1) {
        if (p == -1 && e == -1 && i == -1 && d == -1) {
            break;
        }
        case_count ++;

        // special case, p = e = i;
        if (p == e && e == i) {
            printf("Case %d: the next triple peak occurs in %d days.\n", case_count, p_len * e_len * i_len - d - p);
            continue;
        }

        day_cnt = 0;
        if (p >= p_len) {
            p %= p_len;
        }
        if (e >= e_len) {
            e %= e_len;
        }
        if (i >= i_len) {
            i %= i_len;
        }

        p_cnt = p;

        while (1) {
            p_cnt += p_len;
            day_cnt ++;
            if ((p_cnt - e) % e_len == 0 && (p_cnt - i) % i_len == 0 && day_cnt * p_len + p - d > 0) {
                break;
            }
        }
        result = day_cnt * p_len + p - d;
        if (result > p_len * e_len * i_len) {
            result %= p_len * e_len * i_len;
        }
        printf("Case %d: the next triple peak occurs in %d days.\n", case_count, result);
    }
    
    return 0;
}
