#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	int n, s = 0, i = 1;
    while (scanf("%d", &n) == 1) {
    	while (s < n || (s - n) % 2 == 1 ) {
    		s += i;
    		i ++;
    	}
    	printf("%d\n", i - 1);
	}
    return 0;
}
