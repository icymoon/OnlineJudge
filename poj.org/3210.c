#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    int coin_count;
    
    while (scanf("%d", &coin_count) != -1) {
    	if (0 == coin_count) {
    		break;
    	}
		if (coin_count % 2 == 0) {
			printf("No Solution!\n");
		} else {
			printf("%d\n", coin_count - 1);
		}
    }
    return 0;
}
