#include <stdio.h>
#include <stdlib.h>

#define MAX_SCORE 1000
#define MIN_SCORE 0
int main(int argc, char * argv[]) {
    int score_count, score, score_avg, i; 
    int score_sum = 0, score_max = MIN_SCORE, score_min = MAX_SCORE;

    while (scanf("%d", &score_count) != -1) {
        if (score_count == 0) {
            break;
        }
    	if (score_count <= 2) {
    	    printf("Error score count = %d\n", score_count);
    	    return -1;
    	}
    	for (i = 0; i < score_count; i ++) {
    	    scanf("%d", &score);
    	    score_sum += score;
    	    if (score > score_max) {
    	        score_max = score;
    	    }
    	    if (score < score_min) {
    	        score_min = score;
    	    }
    	}
    	score_avg = (score_sum - score_max - score_min) / (score_count - 2);
    	printf("%d\n", score_avg);
    	score_sum = 0;
    	score_max = MIN_SCORE;
    	score_min = MAX_SCORE;
    }
    return 0;
}
