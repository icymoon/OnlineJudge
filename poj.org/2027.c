#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    int case_count, case_num;
    int x, y;

    if (scanf("%d", &case_count) == -1 || case_count == 0) {
        return 1;
    }

    for (case_num = 0; case_num < case_count; case_num ++) {
        if (scanf("%d %d", &x, &y) == -1) {
            break;
        }
        printf("%s\n", x < y ? "NO BRAINS" : "MMM BRAINS");
    }
    return 0;
}
