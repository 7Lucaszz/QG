#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "linkedList.h"


Status InitList(LinkedList *L) {
    LinkedList list;

    list = (LinkedList)malloc(sizeof(LNode));
    if(list == NULL)
    {
    	printf("�ڴ����ʧ��\n");
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
//�����ڳ�ʼ������ 
Status InsertList1(LNode *p, ElemType data) {
    LinkedList current = p;
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));

    if(newNode == NULL)
    {
        printf("�ڴ����ʧ��\n");
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
        printf("����Ϊ�գ��޷�ɾ��\n");
    }
    else
    {
        while(posNode->data != e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if(posNode == NULL)
            {
                printf("û�и�����\n");
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
    LNode *newHead;		//����ÿ�η�ת��ĵ�һ���ڵ� 
    LNode *p1;			//ÿ�ζ�ָ��ǰһ���ڵ�	
    LNode *p2;			// ����δ��תǰ����һ���ڵ� 
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
    printf("\n\n\n\n			***������ADT***\n\n");
    printf("			***1.����������***\n");
    printf("			***2.��������***\n");
    printf("			***3.������***\n");
    printf("			***4.ɾ�����***\n");
    printf("			***5.��������***\n");
    printf("			***6.��������***\n");
    printf("			***7.��ת����***\n");
    printf("			***8.�ж������Ƿ�ɻ�***\n");
    printf("			***9.��ת�����е�ż�����***\n");
    printf("			***10.�����м���***\n");
    printf("			***11.�˳�\n");
    printf("\n			***�������Ӧ������(1-11)��***");
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
            case 1://����������
            {
                if(InitList(&head))
                {
                    printf("���������ɹ�\n");
                    
                }
                else
                {
                    printf("��������ʧ��\n");
                }
                break;
            }
            case 2://��������
            {
                DestroyList(&head);
                printf("�����������\n");
                break;
            }
            case 3://��������
            {
             if(head == NULL)
		    {
		     printf("����Ϊ�գ� ���ȴ�������\n");
		    }
		    else
		    {
		   int n,num; 
		 	printf("�����봴�����ĸ�����");
		 	scanf("%d",&n);
		 	for(int i=0;i<n;i++)
		 	{ 
		 	 printf("���������ݣ�");
		 	 scanf("%d", &num);
		 	 InsertList1(head, num);
		 	 
		 	 
		 	  printf("���ݲ���ɹ�\n");
		 
		 	  }
		 	
		     }
			break;
            }
		
            case 4://ɾ������
            {
                printf("����ɾ���ĸ����ݣ�");
                scanf("%d", &num);
                if(DeleteList(head, num))
                {
                    printf("����ɾ���ɹ�\n");
                }
                else
                {
                	printf("����ɾ��ʧ��\n");
                }
                break;
            }
            case 5://��������
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("�������ڻ���ֻ����һ���յ�ͷ���\n");
                }
                else
                {
                    TraverseList(head,visit);
                }
                break;
            }
            case 6://��������
            {
                printf("��������Ҫ���ҵ����ݣ�");
                scanf("%d", &num);
                if(SearchList(head, num))
                {
                    printf("��������\n");
                }
                else
                {
                    printf("����������\n");
                }
                break;
            }
            case 7://��ת����
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("����Ϊ�ջ�������ֻ�����������\n");
                    printf("����תʧ��\n");
                }
                else
                {
                    if(ReverseList(&head))
                    {
                        printf("����ת�ɹ�\n");
                    }
                    else
                    {
                        printf("����תʧ��\n");
                    }
                    
                }
                break;
            }
            case 8://�ж������Ƿ�ɻ�
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("����Ϊ��\n");
                }
                else
                {
                    if(IsLoopList(head))
                    {
                        printf("����ɻ�\n");
                    }
                    else
                    {
                        printf("����û�гɻ�\n");
                    }
                }
                break;
            }
            case 9://��ת�����е�ż�����
            {
            	
			    if(head == NULL || head->next == NULL)
			    {
				  printf("���ǿ�����\n");
				}
				else
				{
				
					printf("ż������ѷ�ת\n");
				    ReverseEvenList(&head);
					
				}
                break;
            }
            case 10://�����м���
            {
                if(head == NULL || head->next == NULL)
                {
                    printf("���ǿ�����\n");
                }
                else
                {
                    printf("�����м䴢���ֵΪ%d\n", (FindMidNode(&head))->data);
                }
                break;
            }
     
            case 11://��������
            {
                DestroyList(&head);
                break;
            }
            default:
            {
                printf("�������������֣�(1-11)\n");
                break;
            }
        }
    } while (choice != 11);
    
    return 0;
}
