#include "D:\QG\week2\largegroup\LQueue.h" 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
		printf("队列初始化成功。");
	return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
if (IsEmptyLQueue(Q))
		return; 
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
	printf("队列销毁成功。");
	
	
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front==NULL&&Q->length==0){
		printf("该队列为空。");
		return TRUE;
		//TODO
	}
	else
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	Node* p;
	if(Q->front == Q->rear)
		return FALSE;
	p = Q->front->next;
	
	if(type == 1){ 
		printf("队头元素为int值: %d\n", *((int*)(p->data)) );
	}
	if(type==2){
		printf("队头元素为float值：%f\n", *((float*)(p->data)));
	}
	if(type == 3){
		printf("队头元素为字符串: %s\n", p->data);
	}

	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	if(!Q){
		printf("队列未初始化。");
		return FALSE; 
		//TODO
	}
	else 
	{
     	Node *p = (Node *)malloc(sizeof(Node));
	 	if (NULL == p)
	 		return FALSE;
	 		p->data = data;
		 	Q->rear->next = p;		//将新结点连接到队尾 
		 	Q->rear = p;			//将新结点设置为队尾
		 	p->next = NULL;
		 	Q->length++; 
	 	return TRUE;

}
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
		if(!Q){
			printf("队列未初始化。");
			return FALSE; 
			//TODO
		}
		if(IsEmptyLQueue(Q)){
			printf("空队列，不能出队。");
			return FALSE;
			//TODO
		}
		 struct node *p=malloc(sizeof(Node));
		 p=Q->front;
		Q->front=Q->front->next;
		p->next=NULL;
		Q->length--;
		free(p);
		printf("出队成功。");
		return TRUE ;
		
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q
 
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
    printf("\n\n\n\n			***队列***\n\n");
    printf("			***1.初始化队列***\n");
    printf("			***2.销毁队列***\n");
    printf("			***3.检查队列是否为空***\n");
    printf("			***4.查看队头元素***\n");
    printf("			***5.确定队列长度***\n");
    printf("			***6.入队操作***\n");
    printf("			***7.出队操作***\n");
    printf("			***8.清空队列***\n");
    printf("			***9.遍历函数操作\n");
    printf("			***10.退出\n");
    printf("\n			***请输入对应的数字(1-10)：***");
}
int judge_int(void)  //防止用户乱输入其他的字符
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
            if(word[m]<'0' || word[m]>'9')  //检验是否有乱输入其他字符
            {
                printf("请输入整数：");
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
    for(m=0;m<len;m++)  // 将字符重新转换为数字
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
					printf("该队列为空。"); 
					//TODO
				}
				else
				{
					printf("该队列非空。"); 
				}
				break;
			case 4:
				GetHeadLQueue(&head,&num);
				break;
			case 5:
				length=LengthLQueue(&head);
				printf("该队列长度为： %d",length);
				break;
			case 6:
				     puts("请选择入队数据类型：\n");
				       puts("1:整型数据，2：浮点型数据，3：字符型数据\n");
				       type=judge_int();
				       if(type==1){
				       	printf("请输入创建节点的个数：\n");
				       	scanf("%d",&times);
				       	for(int i=0;i<times;i++){
				        int *data1=(int*)malloc(sizeof(int));
				        printf("请输入入队数据：\n");
				        scanf("%d",data1);
				        EnLQueue(&head,data1);
				       	}
				        //TODO
				       }
				       if(type==2){
				       	printf("请输入创建节点的个数：\n");
						scanf("%d",&times);
						for(int i=0;i<times;i++){
				        float *data2=(float*)malloc(sizeof(float));
				        printf("请输入入队数据：\n");
				        scanf("%f",data2);
				        EnLQueue(&head,data2);
						}
				       }
				       if(type==3){
				       	printf("请输入创建节点的个数：\n");
						scanf("%d",&times);
						for(int i=0;i<times;i++){
				        char *string=(char*)malloc(20*sizeof(char));
				        printf("请输入入队数据：\n");
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
				printf("请重新输入数字1-10.");
				break;			
		}
	}while(choice!=10);
}
