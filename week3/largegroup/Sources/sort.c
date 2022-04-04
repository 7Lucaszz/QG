#include "../Headers/sort.h" 
#include"stdio.h"
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n){
	int i, j;
	for(i = 2; i <= n; i++){
		if(a[i] < a[i-1]){
			a[0] = a[i];
			for(j = i - 1; a[j] > a[0]; j--)
				a[j+1] = a[j];
			a[j+1] = a[0];
		}
	} 
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int i = begin, j = mid+1;
	int k = 0;
	
	while(i <= mid && j <= end)
	{
		if(a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	while(i <= mid)
		temp[k++] = a[i++];
		
	while(j <= end)
		temp[k++] = a[j++];
		
	for(i = 0; i < k; i++)
		a[begin+i] = temp[i];
} 


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����(�ݹ鷨)
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp){
	if(begin < end)
	{
		int mid = (begin + end) / 2;
		MergeSort(a, begin, mid, temp);
		MergeSort(a, mid+1, end, temp);
		MergeArray(a, begin, mid, end,temp);
	}
} 


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end){
   	int pivot;
   	
	if(begin < end)
	{
			pivot = Partition(a, begin, end); 
			QuickSort_Recursion(a, begin, pivot-1);		    //�����ӱ�ݹ����� 
			QuickSort_Recursion(a, pivot+1, end);		    //�����ӱ�ݹ����� 
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a, int size){
	
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end){
	int pivotkey;
	int temp;

	pivotkey = a[begin]; 
	while(begin < end) 
	{ 
		while(begin < end && a[end] >= pivotkey)
			end--;
		temp = a[begin];
		a[begin] = a[end];
		a[end] = temp;
		
		while(begin < end && a[begin] <= pivotkey)
			begin++;
		temp = a[begin];
		a[begin] = a[end];
		a[end] = temp;
	}
	return begin; 
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max){
	max = a[0];
	int min = a[0];
	long i = 0;
	long j = 0;

	for (i = 0; i < size; i++){
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	
	long range = max - min + 1;
	
	int *b = (int *)malloc(range * sizeof(int));
	
	for (i = 0; i < range; i++)
		b[i] = 0;
	
	
	for (i = 0; i < size; i++){
		//ע�⣺�����ڴ洢��Ҫ��ԭʼ������ֵ�ϼ�ȥmin�Ų������Խ������
		b[a[i] - min]++;
	}
	//����ͳ�ƽ�������¶�Ԫ�ؽ��л���
	for (i = 0; i < range; i++){
		while (b[i]--){
			//ע�⣺Ҫ��i��ֵ����min���ܻ�ԭ��ԭʼ����
			a[j++] = i + min;
		}
	}
	//�ͷ���ʱ����
	free(b);
	b = NULL;
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size){
	
}






