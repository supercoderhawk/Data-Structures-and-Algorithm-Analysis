#ifndef _BTREE_H
#define _BTREE_H
struct BTreeNode;
typedef int BTElementType;
typedef struct BTreeNode *PtrToBTNode;
typedef PtrToBTNode BTree;
typedef struct BTreeNode *BTPosition;
typedef struct BTreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
BTPosition Find(BTElementType X, SearchTree T);
BTPosition FindMin(SearchTree T);
BTPosition FindMax(SearchTree T);
SearchTree Insert(BTElementType X, SearchTree T);
SearchTree Delete(BTElementType X, SearchTree T);
BTElementType Retrieve(BTPosition P);

struct BTreeNode
{
	BTElementType Element;
	BTree Left;
	BTree Right;
};

#endif // !_BTREE_H

