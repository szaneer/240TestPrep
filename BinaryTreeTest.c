#include "stdlib.h"
#include "stdio.h"

typedef struct TreeNode {
  /* data */
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
} treeNode;

treeNode *root = NULL;

int removeNode(treeNode *node) {
  return 0;
}

int removeNodeByValue(int value) {
  return 0;
}

treeNode* insert(int value) {
  return NULL;
}

void parseFile(char *name) {

}

char* printTree() {
  return NULL;
}

void freeTree() {

}

void test1() {
  char *treeResult = printTree();

  printf("Tree should hold:8 3 1 6 4 7 10 14 13 \n");

  if (treeResult != NULL && !strcmp("8 3 1 6 4 7 10 14 13 ", treeResult)) {
    printf("Your tree holds:8 3 1 6 4 7 10 14 13 \n");
    printf("Passed test case 1!\n");
    return;
  }

  printf("Your tree holds:%s\n", treeResult);
  printf("Failed test case 1 :(\n");
}

/*

*/
int main(int argc, char* argv[]) {
  if (argc == 2) {
    switch (*argv[1]) {
      case '0':
      case '1':
        parseFile("1.txt");
        test1();
        break;
      case '2':
      default:
        break;

    }
  } else {
    printf("Wrong amount of arguements. Remember to put in only test number as arguement!\n");
  }
}
