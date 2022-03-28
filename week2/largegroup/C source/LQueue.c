#include "D:\QG\week2\largegroup\LQueue.h" 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
		printf("���г�ʼ���ɹ���");
	return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
if (IsEmptyLQueue(Q))
		return; 
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
	printf("�������ٳɹ���");
	
	
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front==NULL&&Q->length==0){
		printf("�ö���Ϊ�ա�");
		return TRUE;
		//TODO
	}
	else
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	Node* p;
	if(Q->front == Q->rear)
		return FALSE;
	p = Q->front->next;
	
	if(type == 1){ 
		printf("��ͷԪ��Ϊintֵ: %d\n", *((int*)(p->data)) );
	}
	if(type==2){
		printf("��ͷԪ��Ϊfloatֵ��%f\n", *((float*)(p->data)));
	}
	if(type == 3){
		printf("��ͷԪ��Ϊ�ַ���: %s\n", p->data);
	}

	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	int length;
		Node *p = (Node *)malloc(sizeof(Node));
		p = Q->front;
		for (length = 0; p != Q->rear; length++)
			p = p->next; 
		return length;
	
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
	if(!Q){
		printf("����δ��ʼ����");
		return FALSE; 
		//TODO
	}
	else 
	{
     	Node *p = (Node *)malloc(sizeof(Node));
	 	if (NULL == p)
	 		return FALSE;
	 		p->data = data;
		 	Q->rear->next = p;		//���½�����ӵ���β 
		 	Q->rear = p;			//���½������Ϊ��β
		 	p->next = NULL;
		 	Q->length++; 
	 	return TRUE;

}
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
		if(!Q){
			printf("����δ��ʼ����");
			return FALSE; 
			//TODO
		}
		if(IsEmptyLQueue(Q)){
			printf("�ն��У����ܳ��ӡ�");
			return FALSE;
			//TODO
		}
		 struct node *p=malloc(sizeof(Node));
		 p=Q->front;
		Q->front=Q->front->next;
		p->next=NULL;
		Q->length--;
		free(p);
		printf("���ӳɹ���");
		return TRUE ;
		
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
   
   	if (IsEmptyLQueue(Q))
   		return;
   	Node *p, *q;
   	Q->rear = Q->front;
   	p = Q->front->next; 
   	while (NULL != p) {
   		q = p;
   		p = p->next;
   		free(q);
   	}
   	free(p);
   	return;
  
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	Node* p = Q->front->next; 
	while(p!=NULL)
	{
		foo(p->data);
		p = p->next;
	}
	printf("\n");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q){
	if(type == 1){ 
		printf("%d -> ", *(int*)q );
	}
	if(type==2){
		printf("%f -> ",*(float*)q);
	}
	if(type == 3){
		printf("%s -> ", q);
	} 
	
 
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
// LQUEUE_H_INCLUDED
void show(void)
{
    printf("\n\n\n\n			***����***\n\n");
    printf("			***1.��ʼ������***\n");
    printf("			***2.���ٶ���***\n");
    printf("			***3.�������Ƿ�Ϊ��***\n");
    printf("			***4.�鿴��ͷԪ��***\n");
    printf("			***5.ȷ�����г���***\n");
    printf("			***6.��Ӳ���***\n");
    printf("			***7.���Ӳ���***\n");
    printf("			***8.��ն���***\n");
    printf("			***9.������������\n");
    printf("			***10.�˳�\n");
    printf("\n			***�������Ӧ������(1-10)��***");
}
int judge_int(void)  //��ֹ�û��������������ַ�
{
    int len, num = 0, arg = 1;
    char word[10];  
    int m, j= 1, k;
    while(j)
    {
        scanf("%s", word);
        len = strlen(word);
        for(m = 0;m<len;m++)
        {
            if(word[m]<'0' || word[m]>'9')  //�����Ƿ��������������ַ�
            {
                printf("������������");
                break;
            }
            else 
            {
                if(m == len-1)
                    j = 0;
            }
        }
    }
    j = len-1;
    for(m=0;m<len;m++)  // ���ַ�����ת��Ϊ����
    {
        for(k=0;k<j;k++)
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
} 
int main (void)
{
	int length;
	int choice;
	int times;
   int num;
	LQueue head;
	InitLQueue(&head);
	do{
		show();
		choice=judge_int();
		system("cls");
		switch (choice) {
			case 1:
			InitLQueue(&head);
				break;
			case 2:
				DestoryLQueue(&head);
				//TODO
				break;
			case 3:
				if(IsEmptyLQueue(&head)){
					printf("�ö���Ϊ�ա�"); 
					//TODO
				}
				else
				{
					printf("�ö��зǿա�"); 
				}
				break;
			case 4:
				GetHeadLQueue(&head,&num);
				break;
			case 5:
				length=LengthLQueue(&head);
				printf("�ö��г���Ϊ�� %d",length);
				break;
			case 6:
				     puts("��ѡ������������ͣ�\n");
				       puts("1:�������ݣ�2�����������ݣ�3���ַ�������\n");
				       type=judge_int();
				       if(type==1){
				       	printf("�����봴���ڵ�ĸ�����\n");
				       	scanf("%d",&times);
				       	for(int i=0;i<times;i++){
				        int *data1=(int*)malloc(sizeof(int));
				        printf("������������ݣ�\n");
				        scanf("%d",data1);
				        EnLQueue(&head,data1);
				       	}
				        //TODO
				       }
				       if(type==2){
				       	printf("�����봴���ڵ�ĸ�����\n");
						scanf("%d",&times);
						for(int i=0;i<times;i++){
				        float *data2=(float*)malloc(sizeof(float));
				        printf("������������ݣ�\n");
				        scanf("%f",data2);
				        EnLQueue(&head,data2);
						}
				       }
				       if(type==3){
				       	printf("�����봴���ڵ�ĸ�����\n");
						scanf("%d",&times);
						for(int i=0;i<times;i++){
				        char *string=(char*)malloc(20*sizeof(char));
				        printf("������������ݣ�\n");
				        scanf("%s",string);
				        EnLQueue(&head,string);
						}
				       }
				       break;
			case 7:
				DeLQueue(&head);
				break;	
			case 8:
				ClearLQueue(&head);
				break;	
			case 9:
				TraverseLQueue(&head,*LPrint);
				break;
			case 10:
				DestoryLQueue(&head);
				break;
			default:
				printf("��������������1-10.");
				break;			
		}
	}while(choice!=10);
}
