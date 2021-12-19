#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>


struct SLLNode {
  void *data;
  struct SLLNode *next;
};

typedef struct SLLNode SLLNode;

void printSLLNode(SLLNode *node, char *(*custom_print)(void*)) {
  if (node->next) {
    printf("%s -> ", custom_print(node->data));
    printSLLNode(node->next, custom_print);
    return;
  }
  printf("%s\n", custom_print(node->data));
}

SLLNode* createSLLNode(void *data) {
  SLLNode *node = malloc(sizeof(*data) + sizeof(SLLNode*));
  node->data = data;
  node->next = NULL;
}

void freeSLLNodeData(SLLNode *node, void (*custom_free)(void*)) {
  if (node->next)
    freeSLLNodeData(node->next, custom_free);
  custom_free(node->data);
  free(node);
}

void freeSLLNode(SLLNode *node) {
  if (node->next)
    freeSLLNode(node->next);
  free(node);
}

#endif