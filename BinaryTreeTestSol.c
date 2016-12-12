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

void removeNode(treeNode *current, treeNode *toRemove) {
  if (current == NULL) {
	  return;
  }
  if (current == toRemove) {
	  if (current->left != NULL) {
		  removeNode(current->left, current->left);
	  }
	  if (current->right != NULL) {
		  removeNode(current->right, current->right);
	  }
	  free(current);
	  current = NULL;
  }
  if (current->value > toRemove->value) {
	  removeNode(current->left, toRemove);
  }
  if (current->value < toRemove->value) {
	  removeNode(current->right, toRemove);
  }
}

void removeNodeByValue(treeNode *current, int value) {
  if (current == NULL) {
	  return;
  }
  
  if (current->value == value) {
	  if (current->left != NULL) {
		  removeNodeByValue(current->left, current->left->value);
		  current->left = NULL;
	  }
	  if (current->right != NULL) {
		  removeNodeByValue(current->right, current->right->value);
		  current->right = NULL;
	  }
	  free(current);
	  current = NULL;
	  return;
  }
  if (current->value > value) {
	if (current->left != NULL) {
	  if (current->left->value == value) {
		removeNodeByValue(current->left, value);
		current->left = NULL;
	  } else {
	    removeNodeByValue(current->left, value);
	  }
	}
  }
  if (current->value < value) {
	if (current->left != NULL) {
	  if (current->right->value == value) {
		removeNodeByValue(current->right, value);
		current->right = NULL;
	  } else {
	    removeNodeByValue(current->right, value);
	  }
	}
  }
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
  freeTree(root);
  printf("Your free treee function seems to work but I wouldn't know lol, please try running this test with valgrind!\n");
}

void test2() {
	printf("Tree should hold:10 5 4 3 1 8 20 14 13 \n");
	printf("Your tree holds:");
	printTree(root);
	printf("\n");
	freeTree(root);
	printf("Your free treee function seems to work but I wouldn't know lol, please try running this test with valgrind!\n");
}

void test3() {
	printf("Tree should hold:10 5 4 3 1 2 8 7 6 20 14 13 15 90 200\n");
	printf("Your tree holds:");
	printTree(root);
	printf("\n");
	removeNodeByValue(root, 8);
	removeNodeByValue(root, 4);
	printf("After removing values tree should hold:10 5 20 14 13 15 90 200\n");
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
		parseFile("1.txt");
        test1();
		parseFile("2.txt");
		test2();
		parseFile("3.txt");
		test3();
        break;
      case '1':
        parseFile("1.txt");
        test1();
        break;
      case '2':
		parseFile("2.txt");
		test2();
		break;
      default:
		parseFile("3.txt");
		test3();
        break;

    }
  } else {
    printf("Wrong amount of arguements. Remember to put in only test number as arguement!\n");
  }
}
