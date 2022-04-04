#include "../Headers/sort.h" 
#include"stdio.h"
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
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
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
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
 *  @description : 归并排序(递归法)
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
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
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end){
   	int pivot;
   	
	if(begin < end)
	{
			pivot = Partition(a, begin, end); 
			QuickSort_Recursion(a, begin, pivot-1);		    //对上子表递归排序 
			QuickSort_Recursion(a, pivot+1, end);		    //对下子表递归排序 
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a, int size){
	
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
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
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
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
		//注意：这里在存储上要在原始数组数值上减去min才不会出现越界问题
		b[a[i] - min]++;
	}
	//根据统计结果，重新对元素进行回收
	for (i = 0; i < range; i++){
		while (b[i]--){
			//注意：要将i的值加上min才能还原到原始数据
			a[j++] = i + min;
		}
	}
	//释放临时数组
	free(b);
	b = NULL;
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size){
	
}






