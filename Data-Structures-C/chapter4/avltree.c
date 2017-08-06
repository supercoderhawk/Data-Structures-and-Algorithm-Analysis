#include <stdio.h>
#include "avltree.h"

AvlTree MakeEmpty(AvlTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

AvlPosition Find(AvlElementType X, AvlTree T)
{
	return AvlPosition();
}

AvlPosition FindMin(AvlTree T)
{
	return AvlPosition();
}

AvlPosition FindMax(AvlTree T)
{
	return AvlPosition();
}

AvlTree Insert(AvlElementType X, AvlTree T)
{
	if (T == NULL)
	{
		T = (AvlTree)malloc(sizeof(struct AvlNode));
		T->Element = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	}
	else 
	{
		if (X < T->Element)
		{
			T->Left = Insert(X, T->Left);
			if (Height(T->Left) - Height(T->Right) == 2)
			{
				if (X < T->Left->Element)
					T = SingleRotateWithLeft(T);
				else
					T = DoubleRotateWithLeft(T);
			}
		}
		else if (X > T->Element)
		{
			T->Right = Insert(X,T->Right);

		}
	}
	return T;
}

AvlTree Delete(AvlElementType X, AvlTree T)
{
	return AvlTree();
}

AvlElementType Retrieve(AvlPosition P)
{
	return P->Element;
}

int Height(AvlPosition P)
{
	return P == NULL ? -1 : P->Height;
}

AvlPosition SingleRotateWithLeft(AvlPosition K2)
{
	AvlPosition K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	int k2LeftHeight = Height(K2->Left);
	int k2RightHeight = Height(K2->Right);
	K2->Height = k2LeftHeight > k2RightHeight ? k2LeftHeight : k2RightHeight;
	int k1LeftHeight = Height(K1->Left);
	K1->Height = k1LeftHeight > K2->Height ? k1LeftHeight : K2->Height;
	
	return K1;
}

AvlPosition SingleRotateWithRight(AvlPosition K1)
{
	AvlPosition K2 = K1->Right;
	K1->Right = K2->Left;
	K2->Left = K1;

	int k1LeftHeight = Height(K1->Left);
	int k1RightHeight = Height(K1->Right);
	K1->Height = k1LeftHeight > k1RightHeight ? k1LeftHeight : k1RightHeight + 1;
	int k2RightHeight = Height(K2->Right);
	K2->Height = K1->Height > k2RightHeight ? K1->Height : k2RightHeight + 1;

	return K2;
}

AvlPosition DoubleRotateWithLeft(AvlPosition K3)
{
	K3->Left = SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}

AvlPosition DoubleRotateWithRight(AvlPosition K1)
{
	K1->Right = SingleRotateWithLeft(K1->Right);
	return SingleRotateWithRight(K1);
}
