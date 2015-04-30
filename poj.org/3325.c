#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b){
    return((*(int*)a-*(int*)b));
}

int main(int argc, char * argv[]) {
    int score_count, sum, i;
    int scores[100];
    
    while (scanf("%d", &score_count) != -1) {
    	if (0 == score_count) {
    		break;
    	}
    	for (i = 0; i < score_count; i ++) {
    		scanf("%d", &scores[i]); //Maybe we should deal with read failure here.
    	}
		qsort(scores, score_count, sizeof(int), compare);
		sum = 0;
		for (i = 1; i < (score_count - 1); i ++) {
			sum += scores[i];
		}
		printf("%d\n", sum / (score_count - 2));
    }
    return 0;
}
