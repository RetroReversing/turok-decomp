#include "common.h"

struct Node {
    struct Node *next;
    struct Node *prev;
};

void alLink(struct Node *arg0, struct Node **arg1) {
    arg0->next = *arg1;
    arg0->prev = (struct Node *)arg1;
    if (*arg1 != 0) {
        (*arg1)->prev = arg0;
    }
    *arg1 = arg0;
}
