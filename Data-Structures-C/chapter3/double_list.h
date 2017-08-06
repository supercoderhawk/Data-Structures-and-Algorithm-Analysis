#ifndef _DOUBLE_LIST_H
#define _DOUBLE_LIST_H
typedef int DElementType;
struct DNode;
typedef struct DNode *PtrToDNode;
typedef PtrToDNode DoubleList;
typedef PtrToDNode DPosition;

DoubleList MakeEmptyD(DoubleList L);
int IsEmptyD(DoubleList L);
int IsLastD(DPosition P, DoubleList L);
DoubleList CreateListD(DElementType X[], int Count);
DPosition FindD(DElementType X, DoubleList L);
void DeleteD(DElementType X, DoubleList L);
DPosition FindPreviousD(DElementType X, DoubleList L);
void InsertD(DElementType X, DoubleList L, DPosition P);
void DeleteListD(DoubleList L);
DPosition HeaderD(DoubleList L);
DPosition FirstD(DoubleList L);
DPosition AdvanceD(DPosition P);
DElementType RetrieveD(DPosition P);
DPosition ReverseListD(DoubleList L);
void PrintListD(DoubleList L);

struct DNode
{
	DElementType Element;
	DPosition Prev;
	DPosition Next;
};
#endif // !_DOUBLE_LIST_H

