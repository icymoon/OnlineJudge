#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 16
typedef struct name_node_s * p_name_node;
typedef struct name_node_s {
    char name[NAME_LEN];
    p_name_node next;
} name_node;

int main(int argc, char * argv[]) {
    int count, i, done = 0;
    int w, s;
    p_name_node start;
    p_name_node temp;
    p_name_node curr;

    if (scanf("%d", &count) == -1 || count == 0) {
        return 1;
    }

    // Init the names in a circle single list
    start = (p_name_node)malloc(sizeof(name_node));
    if (start == NULL) {
        return -1;
    }
    curr = start;
    if (scanf("%s", curr->name) == -1) {
        goto init_error;
    }

    for (i = 1; i < count; i ++) {
        curr->next = (p_name_node)malloc(sizeof(name_node));
        if (curr->next == NULL) {
            goto init_error;
        }
        curr = curr->next;
        if (scanf("%s", curr->name) == -1) {
            goto init_error;
        }
    }
    curr->next = start;

    scanf("%d,%d", &w, &s);
    curr = start;
    for (i = 1; i < w; i ++) {
        temp = curr;
        curr = curr->next;
    }
    while(count > 0) {
        count --;
        for (i = 1; i < s; i ++) {
            temp = curr;
            curr = curr->next;
        }
        printf("%s\n", curr->name);
        temp->next = curr->next;
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    return 0;

init_error:
    curr = start;
    while(curr != NULL) {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
    return 1;
}
