#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

/*
 *   Initializations
 */

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


/*
 *   Creation and Freeing
 */

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


/*
 *    Helpers (length, at, contains, find)
 */

int lengthSLL(SLLNode *node) {
  if (!node)
    return 0;
  return 1 + lengthSLL(node->next);
}

SLLNode *atSLL(SLLNode *node, int index) {
  if (!index)
    return node;
  return atSLL(node->next, index-1);
}

SLLNode *findSLL(SLLNode *node, void *val) {
  if (!node)
    return NULL;
  if (node->data == val)
    return node;
  return findSLL(node->next, val);
}

int containsSLL(SLLNode *node, void *val) {
  if (findSLL(node, val) == NULL)
    return 0;
  return 1;
}

/*
 *    Appending
 */

void createAppendSLLNode(SLLNode *node, void *data) {
  appendSLLNode(node, createSLLNode(data));
}

void appendSLLNode(SLLNode *node, SLLNode *node2) {
  while (node->next)
    node = node->next;

  node->next = node2;
}


/*
 *    Deleting (with value, with node, with index)
 */




 /*
  *    Swapping
  */
#endif