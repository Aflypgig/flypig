#include <stdio.h>
#include <string.h>

ð������

//��������
void insert_sort(int arr[], int lsize);

//��������
void Swap_ele(int *prev, int *late);
//��������
void PrintfArr(int *arr);
//ϣ������ 
void hill_sort(int arr[], int n);

int main()
{
	int arr[6] = { 3, 6, 1, 2, 9, 7 };
	int n = sizeof arr / sizeof *arr;
	printf("%d\n", n);
	PrintfArr(arr, n);
	printf("\n");
	insert_sort(arr, sizeof arr / sizeof *arr);
	PrintfArr(arr, sizeof arr / sizeof *arr);
	printf("\n");
	hill_sort(arr, n);
	printf("ϣ������:");
	PrintfArr(arr, n);
	return 0;
}

void hill_sort(int arr[], int n)  //ϣ������
{ 
	int i,j,k;
	int delta=n/2;
	for (i = 0; i < delta; i++)
	{
		for (j = i + delta; j < n; j += delta)
		{
			k = j;
			while (k>i&&arr[k] < arr[k - delta])
			{
				Swap_ele(&arr[k], &arr[k - delta]);
				k -= delta;
			}
		}
		delta /= 2;
	}
	insert_sort(arr, n);  //���ò�������������һ�ֵ�����

	
}

//��������
void Swap_ele(int *prev, int *late)
{
	int n;
	n = *prev;
	*prev = *late;
	*late = n;
}

//��������
void insert_sort(int arr[], int lsize)
{
	int i, j;

	for (i = 0; i < lsize; i++)
	{
		
		for (j = i ; j >= 0 && j < lsize - 1; j--)
		{
			int n = arr[j ];
			if (arr[j ] < arr[j-1])
			{
				/*arr[j ] = arr[j-1];
				arr[j] = n;*/
				Swap_ele(&arr[j], &arr[j-1]);
			}
			
		}
	}
}

//��������
void PrintfArr(int arr[],int n)
{
	for (int i = 0; i < n ;i++)
	{
		printf("%d ", arr[i]);
	}
}