#ifndef _LIST_H
#define _LIST_H
typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
List CreateList(ElementType X[], int Count);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
Position Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
Position ReverseList(List L);
void PrintList(List L);

struct Node
{
	ElementType Element;
	Position Next;
};

#endif // !_LIST_H
