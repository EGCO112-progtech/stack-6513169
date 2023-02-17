
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
  NodePtr top;
  int size;
} Stack;

typedef Stack *StackPtr;
void push(StackPtr s, char x) {
  NodePtr new_node = (NodePtr)malloc(sizeof(Node));
  if (new_node) {
    new_node->data = x;
    new_node->nextPtr = s->top;
    s->top = new_node;
    s->size++;
  }
}
char pop(StackPtr s) {

  NodePtr t = s->top;
  if (s->size > 0) {
    char value = t->data;
    s->top = t->nextPtr;
    s->size--;
    free(t);
    return value;
  }
  //printf("Empty Stack\n");
  return 0;
}

void pop_all(StackPtr s) {
  while (s->top != NULL) {
   pop(s);
  }
}
#endif
