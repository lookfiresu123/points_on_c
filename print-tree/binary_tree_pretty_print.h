#ifndef _H_BINARY_TREE_PRETTY_PRINT
#define _H_BINARY_TREE_PRETTY_PRINT

#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

struct BinaryTree {
  BinaryTree *left, *right;
  int data;
  BinaryTree(int val) : left(NULL), right(NULL), data(val) { }
};


int maxHeight(BinaryTree *p);
string intToString(int val);
void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out);
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out);
void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out);
void printPretty(BinaryTree *root, int level, int indentSpace, ostream& out);

#endif
