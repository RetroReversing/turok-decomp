#include "common.h"

typedef struct Node { struct Node *next; } Node;
typedef struct { char pad[0x64]; Node *head; Node *tail; Node *free; } List;
void __unmapVoice(List *list, void *item) {
    Node *prev = 0;
    Node *cur = list->head;
    Node *target = (Node *)((char *)item - 4);
    while (cur != 0) {
        if (cur == target) {
            if (prev != 0) prev->next = cur->next;
            else list->head = cur->next;
            if (cur == list->tail) list->tail = prev;
            cur->next = list->free;
            list->free = cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}
