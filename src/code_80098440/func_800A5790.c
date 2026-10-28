#include "common.h"

typedef struct Node {struct Node *next;} Node;
void func_800A5790(Node *head,Node *target) {
 register Node *link=head;
 register Node *node=link->next;
 while(node) {
  if(node==target) {link->next=target->next;break;}
  link=node;
  node=link->next;
 }
}
