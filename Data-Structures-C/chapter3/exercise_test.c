#include <stdio.h>
#include "list.h"
#include "exercise.h"
#include "exercise_test.h"

void testPrintLots()
{
	ElementType a[6] = { 1,2,3,4,5,6 };
	ElementType p[3] = { 1,3,5 };

	List la = CreateList(a, 6);
	List lp = CreateList(p, 3);

	PrintLots(la, lp);

	DeleteList(la);
	DeleteList(lp);
}

void testExchangeNodeSingleList()
{
	ElementType a[6] = { 1,2,3,4,5,6 };
	List l = CreateList(a, 6);
	Position p = l->Next->Next;

	PrintList(ExchangeNodeSingleList(l, p));

	DeleteList(l);
}

void testIntersection()
{
	ElementType a[6] = { 1,2,3,4,5,6 };
	ElementType b[3] = { 3,5,7 };
	List l1 = CreateList(a, 6);
	List l2 = CreateList(b, 3);

	PrintList(Intersection(l1, l2));

	DeleteList(l1);
	DeleteList(l2);
}

void testUnion()
{
	ElementType a[6] = { 1,2,3,4,5,6 };
	ElementType b[3] = { 3,5,7 };
	List l1 = CreateList(a, 6);
	List l2 = CreateList(b, 3);

	PrintList(Union(l1, l2));

	DeleteList(l1);
	DeleteList(l2);

	ElementType a1[6] = { 1,2,3,4,5,6 };
	ElementType b1[3] = { 7 };
	List l11 = CreateList(a1, 6);
	List l22 = CreateList(b1, 1);

	PrintList(Union(l11, l22));

	DeleteList(l11);
	DeleteList(l22);
}

void testAddPolynomial()
{
	int c11[3] = {10,10,50};
	int e11[3] = { 7,4,1 };
	int c12[4] = { 5,4,3,2 };
	int e12[4] = { 4,3,2,1 };
	Polynomial p1 = CreatePolynomial(c11, e11, 3);
	Polynomial p2 = CreatePolynomial(c12, e12, 4);
	PrintPolynomial(AddPolynomial(p1, p2));
	DeletePolynomial(p1);
	DeletePolynomial(p2);
}
