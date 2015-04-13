#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b){
    return((*(int*)a-*(int*)b));
}

int main(int argc, char * argv[]) {
    int length, count, dna_array_count, fail = 0;
    char ** dna;
    char ** dna_sort;
    int * meature;
    int * meature_sorted;
    int i, j, k;

    if (scanf("%d %d", &length, &count) == -1) {
        return 1;
    }
    dna_array_count = count;

    dna = (char **)malloc(sizeof(char *) * count);
    if (dna == NULL) {
        return 1;
    }

    meature = (int *)malloc(sizeof(int) * count);
    if (meature == NULL) {
        fail = 1;
        goto fail_meature;
    }

    meature_sorted = (int *)malloc(sizeof(int) * count);
    if (meature_sorted == NULL) {
        fail = 1;
        goto fail_meature_sorted;
    }

    for (i = 0; i < count; i ++) {
        dna[i] = (char *)malloc(sizeof(char) * (length + 1));
        if (dna[i] == NULL) {
            break;
        }
        if (scanf("%s", dna[i]) == -1) {
            break;
        }
        dna[i][length] = '\0';
        meature[i] = 0;
    }

    //Something goes wrong when malloc and read dna array, free the array and return.
    if (i != count) {
        dna_array_count = i;
        fail = 1;
        goto fail_dna_array;
    }

    for (i = 0; i < count; i ++) {
        for (j = 0; j < length; j ++) {
            for (k = j + 1; k < length; k ++) {
                if (dna[i][j] > dna[i][k]) {
                    meature[i] ++;
                }
            }
        }
        meature[i] = meature[i] * 1000 + i;
    }

    // Sort and print result
    qsort(meature,  count, sizeof(int), compare);
    for (i = 0; i < count; i ++) {
        printf("%s\n", dna[meature[i] % 1000]);
    }

//Free the dna array and other arraies before return
fail_dna_array:
    for (i = 0; i < dna_array_count; i ++) {
        free(dna[i]);
    }

    free(meature_sorted);
fail_meature_sorted:
    free(meature);
fail_meature:
    free(dna);

    if (fail) {
        return 1;
    }
    return 0;
}
