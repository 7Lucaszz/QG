#include "D:\QG\week2\largegroup\LinkStack.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
 s->top=NULL;
 s->count=0;
 return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if(s->top==NULL)
	{
		return SUCCESS;
	}
	return ERROR;
	
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->top->next==NULL){
		return ERROR;
		//TODO
	}
	*e=s->top->data;
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s){
	if(s->top==NULL||s->top->next==NULL){
		return ERROR;
		//TODO
	}
	while(!s->top->next){
		s->top=s->top->next;
		//TODO
	}
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s){
		if(s->top==NULL||s->top->next==NULL){
			return ERROR;
			//TODO
		}
		LinkStackPtr p=s->top,q;
		while(p){
				q=p;
				p=p->next;
				free(q);
			//TODO
		}
		s->count=0;
		return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	if(s->top==NULL||s->top->next==NULL)
	{
	    *length=0;
		printf("��ջ����Ϊ��%d",*length);
		return ERROR;
	}
	length=&(s->count);
	printf("��ջ����Ϊ��%d",*length);
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p;
	p=(LinkStackPtr)malloc(sizeof(StackNode));
	p->data=data;
	p->next=s->top;
	s->top=p;
	s->count++; 
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if(isEmptyLStack(s)){
		printf("����ջΪ�գ����ȴ����ǿ���ջ��");
		return ERROR;
		
		//TODO
	}
	LinkStackPtr p;
	*data=s->top->data;
	p=s->top;
	s->top=s->top->next;
	s->count--;
	free(p);
	return  SUCCESS;
}
//������ջ
void TraverseList (LinkStack *s, void (*visit)(ElemType e))
{
	LinkStackPtr p;
	p=s->top;
	while(p){
	    visit(p->data);
		p=p->next;
		//TODO
	}
	
} 
void visit(ElemType e){
	printf("%d   ",e);
}
void show(void)
{
    printf("\n\n\n\n			***��ջ***\n\n");
    printf("			***1.��������ջ***\n");
    printf("			***2.�ж�ջ�Ƿ�Ϊ��***\n");
    printf("			***3.�õ�ջ��Ԫ��***\n");
    printf("			***4.���ջ***\n");
    printf("			***5.����ջ***\n");
    printf("			***6.���ջ����***\n");
    printf("			***7.��ջ***\n");
    printf("			***8.��ջ***\n");
    printf("			***9.������ջ\n");
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
	int choice,num,length;
	int a,b=0;
	LinkStack s;
	do{
		show();
		choice=judge_int();
		 system("cls");
		switch (choice) {
			case 1:
					if(initLStack(&s)){
						printf("����ջ�����ɹ���");
						//TODO
					}
					else
					printf("����ջ����ʧ�ܡ�");
				break;
			case 2:
			if(isEmptyLStack(&s)){
				printf("����ջΪ����ջ��");
				//TODO
			}
			else 
			printf("����ջΪ�ǿ���ջ��");
				break;
			case 3:
				if(isEmptyLStack(&s)){
					printf("����ջΪ�գ����ȴ����ǿ���ջ��");
					//TODO
				}
				else
				getTopLStack(&s,&num);
				printf("ջ������Ϊ��%d",num);
				//TODO
				break;
			case 4:
				if(isEmptyLStack(&s)){
									printf("����ջΪ�գ����ȴ����ǿ���ջ��");
									//TODO
								}
				else
				clearLStack(&s);
				printf("��ջ����ա�");
				break;
				case 5:
					if(isEmptyLStack(&s)){
										printf("����ջΪ�գ����ȴ����ǿ���ջ��");
										//TODO
									}
					else 
					destroyLStack(&s);
					printf("��ջ�����١�");				
					break ;
				case 6:
					if(isEmptyLStack(&s)){
										printf("����ջΪ�գ����ȴ����ǿ���ջ��");
										//TODO
									}
					else LStackLength(&s,&length);			
					break;
				case 7:
					printf("��������ջ������");
					a=judge_int();
					pushLStack(&s,a);
					printf("��ջ�ɹ���");
					
					break;		
					case 8:
						popLStack(&s,&b);
						break;
					case 9:
						if(isEmptyLStack(&s)){
										      printf("����ջΪ�գ����ȴ����ǿ���ջ��");
										}	
						else
						TraverseList(&s,visit);			
						break;	
					case 10:
						destroyLStack(&s);
						break;	
					default:
					printf("��������������1-10.");
					break;		
		}
	}while(choice!=10);
}
 
