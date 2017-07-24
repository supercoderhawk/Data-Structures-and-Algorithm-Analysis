#include <stdio.h>

int max3(int a, int b, int c)
{
	int max = a > b ? a : b;
	return max > c ? max : c;
}

int MaxSubsequenceSumN3(const int A[], int N)
{
	int currSum, maxSum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			currSum = 0;
			for (int k = i; k <= j; k++)
			{
				currSum += A[k];
			}
			if (currSum > maxSum)
			{
				maxSum = currSum;
			}
		}
	}
	return maxSum;
}

int MaxSubsequenceSumN2(const int A[], int N)
{
	int currSum, maxSum=0;
	for (int i = 0; i < N; i++)
	{
		currSum = 0;
		for (int j = i; j < N; j++)
		{
			currSum += A[j];
			if (currSum > maxSum)
			{
				maxSum = currSum;
			}
		}
	}
	return maxSum;
}

int MaxSubsequenceSumNLogN(const int A[], int N)
{

}

int main(int argc, char** argv)
{
	int A[8] = {4,-3,5,-2,-1,2,6,-2};
	int maxN3 = MaxSubsequenceSumN3(A, 8);
	printf("%d\n", maxN3);
}