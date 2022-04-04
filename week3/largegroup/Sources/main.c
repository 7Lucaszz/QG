#include"sort.c"

int main(){
	show(10000);
	show(50000);
	show(200000);
}


void show(long count){
	int i;
	srand((unsigned)time(0));
	clock_t start;
	clock_t diff; 
	
	printf("\n=============================>> %d�������²��� <<==============================\n", count); 
	int array[count];
	
	array[0] = '\0';				//������Ԫ������Ϊ�� --> �������������ڱ� 
	for(i = 1; i < count; i++){
		array[i] = rand();
	}
	start = clock();
	insertSort(array, count);
	diff = clock() - start;
	printf("����������ʱ: %d ms\n", diff);

     
	for(i = 0; i < count; i++){
		array[i] = rand();                    
	}
	int temp1[count];
	start = clock();
	MergeSort(array, 0, count-1, temp1); 
	diff = clock() - start;
	printf("�鲢������ʱ: %d ms\n", diff);
	
	
	for(i = 0; i < count; i++){
		array[i] = rand();                    
	}
	start = clock();
	QuickSort_Recursion(array, 0, count-1);
	diff = clock() - start;
	printf("��������(�ݹ��)��ʱ: %d ms\n", diff);
	
	
	for(i = 0; i < count; i++){
		array[i] = rand();                    
	}
	start = clock();
	CountSort(array, count, 0);
	diff = clock() - start;
	printf("����������ʱ: %d ms\n", diff);
	
	
	for(i = 0; i < count; i++){
		array[i] = rand();                    
	}
	start = clock();
	RadixCountSort(array, count);
	diff = clock() - start;
	printf("����������ʱ: %d ms\n", diff);
	
	
} 
