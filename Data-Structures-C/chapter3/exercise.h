#ifndef _EXERCISE_H
#define _EXERCISE_H
#include "list.h"

// �ڶ���
void PrintLots(List L, List P);

// ������
// ������
List ExchangeNodeSingleList(List L, Position P);
// ˫����
List ExchangeNodeDoubleList();

// ������
List Intersection(List l1, List l2);

// ������
List Union(List l1, List l2);

// ����ʽ
typedef struct PolynomialNode *PtrToPolynomialNode;
struct PolynomialNode
{
	int Coefficient;	// ϵ��
	int Exponent;		// ָ��
	PtrToPolynomialNode Next;
};
typedef PtrToPolynomialNode Polynomial;
PtrToPolynomialNode InsertPolynomial(int c, int e, PtrToPolynomialNode p);
Polynomial CreatePolynomial(int c[], int e[], int count);
void PrintPolynomial(Polynomial p);
void DeletePolynomial(Polynomial p);

// ������
Polynomial AddPolynomial(Polynomial p1, Polynomial p2);

// ������
Polynomial MultiplyPolynomial(Polynomial p1, Polynomial p2);
#endif // !EXERCISE_H

