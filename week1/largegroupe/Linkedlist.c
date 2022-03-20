#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "linkedList.h"


Status InitList(LinkedList *L) {
    LinkedList list;

    list = (LinkedList)malloc(sizeof(LNode));
    if(list == NULL)
    {
    	printf("内存分配失败\n");
        return error;
    }
    list->next = NULL;
    *L = list;

    return success;
}

void DestroyList(LinkedList *L) {
    LinkedList temp;

    while(*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}
//可用于初始化链表 
Status InsertList1(LNode *p, ElemType data) {
    LinkedList current = p;
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));

    if(newNode == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    newNode->data = data;
    newNode->next = NULL;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return success;
}
Status InsertList(LNode *p, LNode *q)
{
    if(p==q) return error;
    else if(p==NULL||q==NULL) return error;
    LinkedList save =p->next;
    p->next=q;
    q->next=save;
    return success;
}
Status DeleteList(LNode *p, ElemType *e) {
    LinkedList posNode = p->next;
    LinkedList posNodeFront = p;
    if(posNode == NULL)
    {
        printf("链表为空，无法删除\n");
    }
    else
    {
        while(posNode->data != e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if(posNode == NULL)
            {
                printf("没有该数据\n");
                return error;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);
        return success;
    }
}


void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode*p = L->next;
	while(p){
		visit(p->data);
		p=p->next;
	}
}
void visit(ElemType e){
	printf("%d   ",e);
}

Status SearchList(LinkedList L, ElemType e) {
    while(L != NULL)
    {
        if(L->data == e)
        {
            return success;
        }
        L = L->next;
    }
    return error;
}



Status ReverseList(LinkedList *L) {
    LNode *newHead;		//储存每次反转后的第一个节点 
    LNode *p1;			//每次都指向前一个节点	
    LNode *p2;			// 储存未反转前的下一个节点 
    p1=(*L)->next;
    p2=p1->next;
    p1->next=NULL;
    newHead=p1;
    while (p2!= NULL) {
        p1=p2;
        p2=p1->next;
        p1->next=newHead;
        newHead=p1;
    }
    (*L)->next=newHead;
}
Status IsLoopList(LinkedList L) {
    LinkedList fast = L, slow = L;
    while(fast->next != NULL && slow->next != NULL)
    {
        slow = slow->next;
        if((fast = fast->next->next) == NULL)
        return error;
        if(fast == slow)
        return success;
    }
    return error;
}

LNode* ReverseEvenList(LinkedList *L) {
if(L == NULL||(*L)->next == NULL)return *L;
	LNode*cur,*prior;
	prior = (*L)->next;
	cur = prior->next;
	while(cur!=NULL){
		if(prior->data%2==0||cur->data%2==0){
			int temp=0;
			temp=prior->data;
			prior->data=cur->data;
			cur->data=temp;
			
	     
		}
		prior = prior->next;
		cur = cur->next;	
	}
	return *L;


}

LNode* FindMidNode(LinkedList *L) {
    LinkedList slow = *L, fast = *L;
    while(fast != NULL && slow != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}



void show(void)
{
    printf("\n\n\n\n			***单链表ADT***\n\n");
    printf("			***1.创建空链表***\n");
    printf("			***2.销毁链表***\n");
    printf("			***3.插入结点***\n");
    printf("			***4.删除结点***\n");
    printf("			***5.遍历链表***\n");
    printf("			***6.查找数据***\n");
    printf("			***7.反转链表***\n");
    printf("			***8.判断链表是否成环***\n");
    printf("			***9.反转链表中的偶数结点***\n");
    printf("			***10.查找中间结点***\n");
    printf("			***11.退出\n");
    printf("\n			***请输入对应的数字(1-11)：***");
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

int main(void)
{
    int choice, num = 0;
    LinkedList head = NULL;

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch(choice)
        {
            case 1://创建空链表
            {
                if(InitList(&head))
                {
                    printf("空链表创建成功\n");
                    
                }
                else
                {
                    printf("空链表创建失败\n");
                }
                break;
            }
            case 2://销毁链表
            {
                DestroyList(&head);
                printf("链表销毁完成\n");
                break;
            }
            case 3://插入数据
            {
             if(head == NULL)
		    {
		     printf("链表为空， 请先创建链表\n");
		    }
		    else
		    {
		   int n,num; 
		 	printf("请输入创建结点的个数：");
		 	scanf("%d",&n);
		 	for(int i=0;i<n;i++)
		 	{ 
		 	 printf("请输入数据：");
		 	 scanf("%d", &num);
		 	 InsertList1(head, num);
		 	 
		 	 
		 	  printf("数据插入成功\n");
		 
		 	  }
		 	
		     }
			break;
            }
		
            case 4://删除数据
            {
                printf("你想删除哪个数据：");
                scanf("%d", &num);
                if(DeleteList(head, num))
                {
                    printf("数据删除成功\n");
                }
                else
                {
                	printf("数据删除失败\n");
                }
                break;
            }
            case 5://遍历链表
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("链表不存在或者只存在一个空的头结点\n");
                }
                else
                {
                    TraverseList(head,visit);
                }
                break;
            }
            case 6://查找数据
            {
                printf("请输入你要查找的数据：");
                scanf("%d", &num);
                if(SearchList(head, num))
                {
                    printf("该数存在\n");
                }
                else
                {
                    printf("该数不存在\n");
                }
                break;
            }
            case 7://反转链表
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("链表为空或者链表只含有两个结点\n");
                    printf("链表反转失败\n");
                }
                else
                {
                    if(ReverseList(&head))
                    {
                        printf("链表反转成功\n");
                    }
                    else
                    {
                        printf("链表反转失败\n");
                    }
                    
                }
                break;
            }
            case 8://判断链表是否成环
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("链表为空\n");
                }
                else
                {
                    if(IsLoopList(head))
                    {
                        printf("链表成环\n");
                    }
                    else
                    {
                        printf("链表没有成环\n");
                    }
                }
                break;
            }
            case 9://反转链表中的偶数结点
            {
            	
			    if(head == NULL || head->next == NULL)
			    {
				  printf("这是空链表\n");
				}
				else
				{
				
					printf("偶数结点已反转\n");
				    ReverseEvenList(&head);
					
				}
                break;
            }
            case 10://查找中间结点
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("这是空链表\n");
                }
                else
                {
                    printf("链表中间储存的值为%d\n", (FindMidNode(&head))->data);
                }
                break;
            }
     
            case 11://销毁链表
            {
                DestroyList(&head);
                break;
            }
            default:
            {
                printf("请重新输入数字！(1-11)\n");
                break;
            }
        }
    } while (choice != 11);
    
    return 0;
}
