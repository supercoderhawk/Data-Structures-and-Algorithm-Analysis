#include <stdio.h>
#include "tree.h"

void PreorderTraversal(Tree T,int tabs)
{
	if (T != NULL)
	{
		for (int i = 0; i < tabs; i++)
			printf("\t");
		printf("%d\n", T->Element);
		PreorderTraversal(T->FirstChild, tabs+1);
		PreorderTraversal(T->NextSibling,tabs);
	}
}
