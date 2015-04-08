#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(int argc, char * argv[]) {
    double x, y, distance, r;
    double s = 0;
    int test_cnt, i, year;
    if (scanf("%d", &test_cnt) == -1) {
        return 1;
    }
    
    for (i = 1; i <= test_cnt; i ++) {
        if (scanf("%lf %lf", &x, &y) == -1) {
            //Get input error
            break;
        }

        if (y <= 0) {
            y = y * (-1);
        }
        // Get distance to (0,0)
        distance = sqrt( x * x + y * y);
        s = distance * distance * PI / 2;
        year = 0;
        while (s > 0) {
            s -= 50;
            year ++;
        }
        printf("Property %d: This property will begin eroding in year %d.\n", i, year);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
