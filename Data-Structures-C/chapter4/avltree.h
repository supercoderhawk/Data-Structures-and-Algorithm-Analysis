#ifndef _AVLTREE_H
#define _AVLTREE_H
struct AvlNode;
typedef int AvlElementType;
typedef struct AvlNode *AvlPosition;
typedef AvlPosition AvlTree;

AvlTree MakeEmpty(AvlTree T);
AvlPosition Find(AvlElementType X, AvlTree T);
AvlPosition FindMin(AvlTree T);
AvlPosition FindMax(AvlTree T);
AvlTree Insert(AvlElementType X, AvlTree T);
AvlTree Delete(AvlElementType X, AvlTree T);
AvlElementType Retrieve(AvlPosition P);
static int Height(AvlPosition P);
static AvlPosition SingleRotateWithLeft(AvlPosition K2);
static AvlPosition SingleRotateWithRight(AvlPosition K1);
static AvlPosition DoubleRotateWithLeft(AvlPosition K3);
static AvlPosition DoubleRotateWithRight(AvlPosition K1);
struct AvlNode
{
	AvlElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};
#endif // !_AVLTREE_H