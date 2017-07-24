#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// 将链表置空
List MakeEmpty(List L)
{
	Position P = L, TmpCell;
	while (P->Next != NULL)
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
	return L;
}

// 判断链表是否为空
int IsEmpty(List L)
{
	return L->Next == NULL;
}

// 判断位置是否为链表尾部
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

// 使用数组创建链表
List CreateList(ElementType X[], int Count)
{
	List header = (List)malloc(sizeof(struct Node));
	header->Next = NULL;
	PtrToNode node;
	Position p = header;

	for (int i = 0; i < Count; i++)
	{
		node = (PtrToNode)malloc(sizeof(struct Node));
		node->Element = X[i];
		node->Next = NULL;
		p->Next = node;
		p = p->Next;
	}
	return header;
}

// 找到给定值在链表中第一次出现的位置，不存在则返回NULL
Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;
	
	return P;

}

// 找到当前节点的前面节点
Position FindPrevious(ElementType X, List L)
{
	Position P;

	P = L;
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;

	return P;
}

// 删除给定值在链表中第一次出现位置的节点
void Delete(ElementType X, List L)
{
	Position P, TmpCell;
	P = L->Next;
	P = FindPrevious(X, L);
	
	if (!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

// 插入新节点
void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
	
}

// 删除链表
void DeleteList(List L)
{
	Position P=L->Next;
	L->Next = NULL;

	while (P!=NULL)
	{
		free(P);
		P = P->Next;
	}
}

// 返回头指针
Position Header(List L)
{
	return L;
}

// 返回第一个节点的指针
Position First(List L)
{
	
	return L==NULL?NULL:L->Next;
}

// 返回下一节点
Position Advance(Position P)
{
	return P->Next;
}

// 返回节点值
ElementType Retrieve(Position P)
{
	return P->Element;
}

// 倒转链表
Position ReverseList(List L)
{
	List reverse = (List)malloc(sizeof(struct Node));
	Position p,tmp;
	p = L->Next;
	reverse->Next = NULL;

	while (p != NULL)
	{
		tmp = malloc(sizeof(struct Node));
		tmp->Element = p->Element;
		tmp->Next = reverse->Next != NULL ? reverse->Next : NULL;
		reverse->Next = tmp;
		p = p->Next;
	}
	return reverse;
}