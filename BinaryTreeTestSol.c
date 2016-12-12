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

int removeNode(treeNode *current, treeNode *toRemove) {
  return 0;
}

int removeNodeByValue(treeNode *current, int value) {
  return 0;
}

treeNode* insert(treeNode *current, treeNode *toInsert) {
  if (root == NULL) {
    root = toInsert;
    return root;
  }
  if (toInsert->value > current->value) {
    if (current->right == NULL) {
      current->right = toInsert;
      return current->right;
    }
    return insert(current->right, toInsert);
  }
  if (toInsert->value < current->value) {
    if (current->left == NULL) {
      current->left = toInsert;
      return current->left;
    }
    return insert(current->left, toInsert);
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

void printTree(treeNode *current) {
  if (current == NULL) {
    return;
  }
  
  printf("%d ", current->value);
  printTree(current->left);
  printTree(current->right);
}

void freeTree(treeNode *current) {
  if (current == NULL) {
    return;
  }
  freeTree(current->right);
  freeTree(current->left);
  free(current);
}

void test1() {
  printf("Tree should hold:8 3 1 6 4 7 10 14 13 \n");
  printf("Your tree holds:");
  printTree(root);
  printf("\n");
}

void test2() {
	printf("Tree should hold:10 5 4 3 1 8 20 14 13 \n");
	printf("Your tree holds:");
	printTree(root);
	printf("\n");
	freeTree(root);
	printf("Your free treee function seems to work but I wouldn't know lol, please try running this test with valgrind!\n");
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
		parseFile("2.txt");
		test2();
		break;
      default:
        break;

    }
  } else {
    printf("Wrong amount of arguements. Remember to put in only test number as arguement!\n");
  }
}
