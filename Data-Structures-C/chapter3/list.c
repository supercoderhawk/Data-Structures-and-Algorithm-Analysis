#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// �������ÿ�
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

// �ж������Ƿ�Ϊ��
int IsEmpty(List L)
{
	return L->Next == NULL;
}

// �ж�λ���Ƿ�Ϊ����β��
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

// ʹ�����鴴������
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

// �ҵ�����ֵ�������е�һ�γ��ֵ�λ�ã��������򷵻�NULL
Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;
	
	return P;

}

// �ҵ���ǰ�ڵ��ǰ��ڵ�
Position FindPrevious(ElementType X, List L)
{
	Position P;

	P = L;
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;

	return P;
}

// ɾ������ֵ�������е�һ�γ���λ�õĽڵ�
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

// �����½ڵ�
void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
	
}

// ɾ������
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

// ����ͷָ��
Position Header(List L)
{
	return L;
}

// ���ص�һ���ڵ��ָ��
Position First(List L)
{
	
	return L==NULL?NULL:L->Next;
}

// ������һ�ڵ�
Position Advance(Position P)
{
	return P->Next;
}

// ���ؽڵ�ֵ
ElementType Retrieve(Position P)
{
	return P->Element;
}

// ��ת����
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