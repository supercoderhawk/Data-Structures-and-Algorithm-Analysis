#include "exercise.h"
#include <stdio.h>
#include <stdlib.h>

// 第二题，打印给定索引的链表节点，P为待打印索引链表
void PrintLots(List L, List P)
{
	int curIndex = 0, targetIndex = 0;
	Position pL = L, pP = P->Next;
	while (pP != NULL)
	{
		targetIndex = pP->Element;
		while (curIndex < targetIndex)
		{
			pL = pL->Next;
			curIndex++;
		}
		printf("%d", pL->Element);
		pP = pP->Next;
		if (pP != NULL)
		{
			printf("->");
		}
	}
	printf("\n");
}

// 第三题，交换成功返回L，否则返回NULL
List ExchangeNodeSingleList(List L, Position P)
{
	if (P == NULL)
		return NULL;
	Position cur = L->Next;
	while (cur != NULL)
	{
		if (cur->Next == P && cur->Next->Next != NULL)
		{
			cur->Next = P->Next;
			P->Next = P->Next->Next;
			cur->Next->Next = P;
			return L;
		}
		cur = cur->Next;
	}
	return NULL;
}

// 两升序链表交集
List Intersection(List l1, List l2)
{
	if (l1 == NULL || l1->Next == NULL || l2 == NULL || l2->Next == NULL)
		return NULL;
	List header = (List)malloc(sizeof(struct Node));
	header->Next = NULL;
	Position p1 = l1->Next, p2 = l2->Next, tmp = NULL, p = header;
	ElementType e1 = p1->Element, e2 = p2->Element;
	while (p1 != NULL && p2 != NULL)
	{
		e1 = p1 != NULL ? p1->Element : e1;
		e2 = p2 != NULL ? p2->Element : e2;
		if (e1 == e2)
		{
			p = Insert(e1, header, p);
			p1 = p1->Next;
			p2 = p2->Next;
		}
		else if (e1 > e2 && p2 != NULL)
			p2 = p2->Next;
		else if (e1 < e2 && p1 != NULL)
			p1 = p1->Next;
	}
	return header;
}

// 两升序链表并集
List Union(List l1, List l2)
{
	if ((l1 == NULL || l1->Next == NULL) && (l2 == NULL || l2->Next == NULL))
		return NULL;
	List header = (List)malloc(sizeof(struct Node));
	Position p1 = l1->Next, p2 = l2->Next, p = header;
	ElementType e1 = p1->Element, e2 = p2->Element;
	header->Next = NULL;

	while (p1 != NULL || p2 != NULL)
	{
		e1 = p1 != NULL ? p1->Element : e1;
		e2 = p2 != NULL ? p2->Element : e2;
		if (e1 == e2)
		{
			p = Insert(e1, header, p);
			p1 = p1->Next;
			p2 = p2->Next;
		}
		else if (p1 != NULL && (e1 < e2 || p2 == NULL))
		{
			p = Insert(e1, header, p);
			p1 = p1->Next;
		}
		else if (p2 != NULL && (e1 > e2 || p1 == NULL)) {
			p = Insert(e2, header, p);
			p2 = p2->Next;
		}
	}
	return header;
}

PtrToPolynomialNode InsertPolynomial(int c, int e, PtrToPolynomialNode p)
{
	Polynomial node = (Polynomial)malloc(sizeof(struct PolynomialNode));
	node->Coefficient = c;
	node->Exponent = e;
	node->Next = NULL;
	p->Next = node;
	return node;
}

Polynomial CreatePolynomial(int c[], int e[], int count)
{
	Polynomial header = (Polynomial)malloc(sizeof(struct PolynomialNode));
	PtrToPolynomialNode p = header;
	header->Next = NULL;
	for (int i = 0; i < count; i++)
	{
		p = InsertPolynomial(c[i], e[i], p);
	}
	return header;
}

void PrintPolynomial(Polynomial p)
{
	if (p == NULL || p->Next == NULL)
		return;
	PtrToPolynomialNode pP = p->Next;
	while (pP != NULL)
	{
		printf("%dx^%d", pP->Coefficient, pP->Exponent);
		pP = pP->Next;
		if (pP != NULL)
		{
			if(pP->Coefficient>0)
				printf("+");
		}
	}
	printf("\n");
}

void DeletePolynomial(Polynomial p)
{
	if (p == NULL)
		return;
	PtrToPolynomialNode pP = p->Next, tmp;
	while (pP != NULL)
	{
		tmp = pP->Next;
		free(pP);
		pP = tmp;
	}
	free(p);
}

Polynomial AddPolynomial(Polynomial p1, Polynomial p2)
{
	Polynomial pSum = (Polynomial)malloc(sizeof(struct PolynomialNode));
	PtrToPolynomialNode pP1 = p1->Next, pP2 = p2->Next, p = pSum, tmp;
	int e1 = pP1->Exponent, e2 = pP2->Exponent;
	pSum->Next = NULL;

	while (pP1 != NULL || pP2 != NULL)
	{
		if (e1 == e2)
		{
			p = InsertPolynomial(pP1->Coefficient + pP2->Coefficient, e1, p);
			pP1 = pP1->Next;
			pP2 = pP2->Next;
		}
		else if (pP1 != NULL && (e1 > e2 || pP2 == NULL))
		{
			p = InsertPolynomial(pP1->Coefficient, e1, p);
			pP1 = pP1->Next;
		}
		else if (pP2 != NULL && (e1 < e2 || pP1 == NULL))
		{
			p = InsertPolynomial(pP2->Coefficient, e2, p);
			pP2 = pP2->Next;
		}
		if (pP1 != NULL)
			e1 = pP1->Exponent;
		if (pP2 != NULL)
			e2 = pP2->Exponent;
	}
	return pSum;
}
