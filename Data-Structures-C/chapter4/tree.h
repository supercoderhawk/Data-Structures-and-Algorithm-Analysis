#ifndef _TREE_H
#define _TREE_H
struct TreeNode;
typedef struct TreeNode *PtrToTreeNode;
typedef PtrToTreeNode Tree;
typedef int TreeElementType;
struct TreeNode
{
	TreeElementType Element;
	PtrToTreeNode FirstChild;
	PtrToTreeNode NextSibling;
};

void PreorderTraversal(Tree T, int tabs);

#endif // !_TREE_H

