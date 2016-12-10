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
  if (root == NULL) {
    root = toInsert;
    return root;
  }
  if (toInsert->value > node->value) {
    if (node->right == NULL) {
      node->right = toInsert;
      return node->right;
    }
    return insert(node->right, toInsert);
  }
  if (toInsert->value < node->value) {
    if (node->left == NULL) {
      node->left = toInsert;
      return node->left;
    }
    return insert(node->left, toInsert);
  }

  free(toInsert);
  return NULL;
}

void parseFile(char *name) {
  FILE *input = fopen(name, "r");
  char *numbers = (char *) malloc(sizeof(char) * 200);

  char c;
  fgets(numbers, 200, input);

  char token[2] = " ";
  char *currentNumber;
  currentNumber = strtok(numbers, token);

  while (currentNumber != NULL) {
    int num = atoi(currentNumber);

    treeNode *node = (treeNode*) malloc(sizeof(treeNode));
    node->value = num;
    node->left = NULL;
    node->right = NULL;
    insert(root, node);
    currentNumber = strtok(NULL, token);
  }


}

void printTree(treeNode *node) {
  if (node == NULL) {
    return;
  }
  printf("%d ", node->value);
  printTree(node->left);
  printTree(node->right);
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
