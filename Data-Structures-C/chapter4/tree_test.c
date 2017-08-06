#include <stdlib.h>
#include "tree_test.h"

Tree CreateTreeDemo()
{
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->Element = 1;
	T->NextSibling = NULL;
	PtrToTreeNode n1 = (Tree)malloc(sizeof(struct TreeNode));
	PtrToTreeNode n2 = (Tree)malloc(sizeof(struct TreeNode));
	PtrToTreeNode n3 = (Tree)malloc(sizeof(struct TreeNode));
	PtrToTreeNode n4 = (Tree)malloc(sizeof(struct TreeNode));
	PtrToTreeNode n5 = (Tree)malloc(sizeof(struct TreeNode));
	T->FirstChild = n1;
	n1->Element = 11;
	n1->FirstChild = n3;
	n1->NextSibling = n2;
	n2->Element = 12;
	n2->FirstChild = n5;
	n2->NextSibling = NULL;
	n3->Element = 13;
	n3->FirstChild = NULL;
	n3->NextSibling = n4;
	n4->Element = 14;
	n4->FirstChild = n4->NextSibling = NULL;
	n5->Element = 15;
	n5->FirstChild = n5->NextSibling = NULL;
	return T;
}
