#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

// 清空树
SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

// 寻找与给定值相同的节点
BTPosition Find(BTElementType X, SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (X < T->Element)
		return Find(X, T->Left);
	else if (X > T->Element)
		return Find(X, T->Right);
	else
		return T;
}

// 寻找最小值，递归法
BTPosition FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}

// 寻找最大值，非递归法
BTPosition FindMax(SearchTree T)
{
	if (T != NULL)
		while (T->Right != NULL)
			T = T->Right;

	return T;
}

SearchTree Insert(BTElementType X, SearchTree T)
{
	if (T == NULL)
	{
		T = (PtrToBTNode)malloc(sizeof(struct BTreeNode));
		T->Element = X;
		T->Left = T->Right = NULL;
	}
	else
	{
		if (X < T->Element)
			T->Left = Insert(X, T->Left);
		else if (X > T->Element)
			T->Right = Insert(X, T->Right);
	}
	return T;
}

SearchTree Delete(BTElementType X, SearchTree T)
{
	BTPosition TmpCell;
	if (T == NULL)
	{
		printf("Element not found.");
		return NULL;
	}

	if (X < T->Element)
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Right);
	else
	{
		// 两个子节点
		if (T->Left&&T->Right)
		{
			TmpCell = FindMin(T->Right);
			T->Element = TmpCell->Element;
			T->Right = Delete(T->Element, T->Right);
		}
		// 1个或者没有子节点
		else
		{
			TmpCell = T;
			if (TmpCell->Left == NULL)
				T = T->Right;
			else if (T->Right == NULL)
				T = T->Left;
			free(TmpCell);
		}
	}
	return NULL;
}

BTElementType Retrieve(BTPosition P)
{
	return P->Element;
}

