#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct TreeNode {
  /* data */
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
} treeNode;

treeNode *root = NULL; //Holds the head or the start of the binary tree. Think of the first field the person starts in.

//Write a function that finds a node in the tree and removes it along with all it's sub nodes.
int removeNode(treeNode *current, treeNode *toRemove) {
  return 0;
}

//Write a function that finds a node in tree given a value and remove is along with all it's sub nodes.
int removeNodeByValue(treeNode * current, int value) {
  return 0;
}

//Write a function that inserts a node into the tree following rules for a BST. Left = lower values and Right = higher values. Do not insert values that already exist.
treeNode* insert(treeNode *current, treeNode *toInsert) {
  return NULL;
}

//Open a file given the name and read, create and insert nodes from space seperated values.
void parseFile(char *name) {

}

//Given the start of a tree print it out and all it's subnodes by following path in story.
void printTree(treeNode *current) {
}

//Free all nodes in tree.
void freeTree(treeNode *current) {
}

//Tests to see if parsing file and insertion works.
void test1() {
  printf("Tree should hold:8 3 1 6 4 7 10 14 13 \n");
  printf("Your tree holds:");
  printTree(root);
  printf("\n");
}

//Tests to see if duplicates are not inserted and tree is being freed.
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
