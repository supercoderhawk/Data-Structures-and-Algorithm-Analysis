#ifndef _EXERCISE_H
#define _EXERCISE_H
#include "list.h"

// 第二题
void PrintLots(List L, List P);

// 第三题
// 单链表
List ExchangeNodeSingleList(List L, Position P);
// 双链表
List ExchangeNodeDoubleList();

// 第四题
List Intersection(List l1, List l2);

// 第五题
List Union(List l1, List l2);

// 多项式
typedef struct PolynomialNode *PtrToPolynomialNode;
struct PolynomialNode
{
	int Coefficient;	// 系数
	int Exponent;		// 指数
	PtrToPolynomialNode Next;
};
typedef PtrToPolynomialNode Polynomial;
PtrToPolynomialNode InsertPolynomial(int c, int e, PtrToPolynomialNode p);
Polynomial CreatePolynomial(int c[], int e[], int count);
void PrintPolynomial(Polynomial p);
void DeletePolynomial(Polynomial p);

// 第六题
Polynomial AddPolynomial(Polynomial p1, Polynomial p2);

// 第七题
Polynomial MultiplyPolynomial(Polynomial p1, Polynomial p2);
#endif // !EXERCISE_H

