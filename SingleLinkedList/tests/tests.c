#include <MyDataStructures/SingleLinkedList.h>

#include <string.h>

typedef struct {
  int x;
  char c;
  char *s;
} custom_type;

void free_test_3(void *custom) {
  custom_type *data = custom;  
  free(data->s);
  free(data);
}

void test_create_free() {
  printf("Starting Creation Tests:\n");

  SLLNode *test1_node = createSLLNode(NULL);
  if (test1_node->data) {
    printf("\tTest 1 out of 4 (Create Node with NULL content) failed!\n");
    exit(1);
  }
  printf("\tTest 1 out of 4 (Create Node with NULL content) passed!\n");
  
  if (test1_node->next) {
    printf("\tTest 2 out of 4 (Created Node has no next) failed!\n");
    exit(1);
  }
  printf("\tTest 2 out of 4 (Created Node has no next) passed!\n");
  
  int *test3_data = malloc(sizeof(int));
  *test3_data = 5;
  SLLNode *test3_node = createSLLNode((void*)test3_data);
  int test3_res = *(int*)test3_node->data;
  if (*test3_data != test3_res) {
    printf("\tTest 3 out of 4 (Create Node with int content) failed!\n");
    exit(1);
  }
  printf("\tTest 3 out of 4 (Create Node with int content) passed!\n");

  custom_type *test4_data = malloc(sizeof(custom_type));
  test4_data->x = 7;
  test4_data->c = 'z';
  test4_data->s = malloc(12);
  strcpy(test4_data->s, "test_string");
  SLLNode *test4_node = createSLLNode((void*)test4_data);
  custom_type test4_res = *(custom_type*)test4_node->data;
  if (test4_data->x != test4_res.x || test4_data->c != test4_res.c || strcmp(test4_data->s, test4_res.s) != 0) {
    printf("\tTest 4 out of 4 (Create Node with custom struct content) failed!\n");
    exit(1);
  }
  printf("\tTest 4 out of 4 (Create Node with custom struct content) passed!\n");


  printf("Starting Freeing Tests:\n");

  printf("\tStart Test 1 out of 3 (Free only Node)\n");
  freeSLLNode(test1_node);

  printf("\tStart Test 2 out of 3 (Free Node and regular type)\n");
  freeSLLNodeData(test3_node, free);

  printf("\tStart Test 3 out of 3 (Free Node and custom type)\n");
  freeSLLNodeData(test4_node, free_test_3);
}

void test_append() {
  printf("Start appending tests.\n");
  int i = 5, j = 6, k = 7, l = 8;
  SLLNode *test_node1 = createSLLNode(&i);
  createAppendSLLNode(test_node1, &j);
  if (!test_node1->next || *(int*)test_node1->next->data != j) {
    printf("\tTest 1 out of 3 (Create+Append to single node) failed!\n");
    exit(1);
  }
  printf("\tTest 1 out of 3 (Create+Append to single node) passed!\n");

  SLLNode *test2_node = createSLLNode(&k);
  appendSLLNode(test_node1, test2_node);
  if (!test_node1->next->next || *(int*)test_node1->next->next->data != k) {
    printf("\tFailed Test 2 out of 3 (Append to list) failed!\n");
    exit(1);
  }
  printf("\tTest 2 out of 3 (Append to list) passed!\n");

  createAppendSLLNode(test_node1, &l);
  if (!test_node1->next->next->next || *(int*)test_node1->next->next->next->data != l) {
    printf("\tTest 3 out of 3 (Create+Append to list) failed!\n");
    exit(1);
  }
  printf("\tTest 3 out of 3 (Create+Append to list) passed!\n");
}

void test_helpers() {
  printf("Start helper tests.\n");

  int i=1,j=2,k=3;
  SLLNode *node = createSLLNode(&i);
  createAppendSLLNode(node, &j);
  createAppendSLLNode(node, &k);

  if (lengthSLL(node) != 3) {
    printf("\tTest 1 out of 4 (Length) failed!\n");
    exit(1);
  }
  printf("\tTest 1 out of 4 (Length) passed!\n");

  if (*(int*)atSLL(node, 1)->data != j) {
    printf("\tTest 2 out of 4 (At) failed!\n");
    exit(1);
  }
  printf("\tTest 2 out of 4 (At) passed!\n");

  if (!containsSLL(node, &k)) {
    printf("\tTest 3 out of 4 (Contains) failed!\n");
    exit(1);
  }

  int x = 7;
  if (containsSLL(node, &x)) {
    printf("\tTest 3 out of 4 (Contains) failed!\n");
    exit(1);
  }
  printf("\tTest 3 out of 4 (Contains) passed!\n");

  if (findSLL(node, &i) == NULL) {
    printf("\tTest 4 out of 4 (Find) failed!\n");
    exit(1);
  }
  if (findSLL(node, &k) == NULL) {
    printf("\tTest 4 out of 4 (Find) failed!\n");
    exit(1);
  }
  if (findSLL(node, &x) != NULL) {
    printf("\tTest 4 out of 4 (Find) failed!\n");
    exit(1);  
  }
  printf("\tTest 4 out of 4 (Find) passed!\n");
}

int main() {
  test_create_free();
  printf("\n");
  test_append();
  printf("\n");
  test_helpers();
  printf("\n");
  printf("All tests passed!\n");
  return 0;
}