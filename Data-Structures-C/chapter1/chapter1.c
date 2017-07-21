#include <stdio.h>

/**
* 冒泡排序函数，从大到小排列
* @param int* arr: 输入数组
* @param int n: 数组长度
**/
void bubbling(int* arr, int n)
{
	int tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j > i; j--)
		{
			if (arr[j] > arr[j - 1])
			{
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("第%d个:%d\n", i, arr[i]);
	}
}

int main(int argc, char** args)
{
	int a[5] = { 10,7,12,4,6 };
	bubbling(a, 5);
}

