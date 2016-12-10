# 240TestPrep
Get dat practice in

Hi everyone! If you're here you're probably trying to get ready for the CS240 final. Before we go any further though I'd like to share a few tips!
- Take a deep breath and relax and know that you can do it!
- Stop trying to memorize every little bit of syntax and start trying to understand concepts. Syntax is useless if you don't know
  how to use it!
- Don't try to make your code needlessly complex, no need to spend time implementing mergesort when your data set consists of 2 values.

##Background info
So what is a binary tree? Imagine that you are playing a game and you start in an empty field. From this field you see that there is only two paths out, 
one to your left and the other to your right. Although they both lead to totally new areas you've never been to before. You decide to take the right path 
and arrive in another field but this time there is a massive number 5 in the middle of it. From the field you currently see that there are another two paths 
you can choose from to continue. You continue the right path always ending up in a new field with a large number in it. You eventually reach 
a field that does not contain any paths to new fields. You then decide you want to search through every field by going to previous nodes until there is a left path you can go down and then search all right paths leading from that one and repeat until you've gone though every field there is.

Your story sucks, what does any of this mean?
Great question!
Think of the follwing things in the story as the following:
- First field - Root node of a tree
- Left and right paths - Pointers to left and right child nodes of a node in the tree
- Field without any paths - Leaf node
- Exploring all fields - Recursive traversal of all nodes

##Alright now let's get down to business!

In this repository there are the following files:
- BinaryTreeTest.c - Holds the functions you need to implement along with test cases
- x.txt files - Holds values to be loaded into Binary Tree

Your task is to implement the following functions within the c file.
- removeNode - Removes a node from the binary

##Testing
- Test case can be run with the command ./ProgramName Test#
- For example: ./BinaryTreeTest 1
- Using 0 will run all test cases
