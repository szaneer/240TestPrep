#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct TreeNode {
  /* data */
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
} treeNode;

treeNode *root = NULL;

int removeNode(treeNode *node, treeNode *toRemove) {
  return 0;
}

int removeNodeByValue(treeNode * node, int value) {
  return 0;
}

treeNode* insert(treeNode *node, treeNode *toInsert) {
  return NULL;
}

void parseFile(char *name) {

}

void printTree(treeNode *node) {
}

void freeTree(treeNode *node) {
}

void test1() {
  printf("Tree should hold:8 3 1 6 4 7 10 14 13 \n");
  printf("Your tree holds:");
  printTree(root);

  printf("\n");
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
