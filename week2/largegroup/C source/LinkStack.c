#include "D:\QG\week2\largegroup\LinkStack.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//链栈

//初始化栈
Status initLStack(LinkStack *s){
 s->top=NULL;
 s->count=0;
 return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if(s->top==NULL)
	{
		return SUCCESS;
	}
	return ERROR;
	
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->top->next==NULL){
		return ERROR;
		//TODO
	}
	*e=s->top->data;
	return SUCCESS;
}

//清空栈
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

//销毁栈
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

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	if(s->top==NULL||s->top->next==NULL)
	{
	    *length=0;
		printf("链栈长度为：%d",*length);
		return ERROR;
	}
	length=&(s->count);
	printf("链栈长度为：%d",*length);
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p;
	p=(LinkStackPtr)malloc(sizeof(StackNode));
	p->data=data;
	p->next=s->top;
	s->top=p;
	s->count++; 
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	if(isEmptyLStack(s)){
		printf("该链栈为空，请先创建非空链栈。");
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
//遍历链栈
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
    printf("\n\n\n\n			***链栈***\n\n");
    printf("			***1.创建空链栈***\n");
    printf("			***2.判断栈是否为空***\n");
    printf("			***3.得到栈顶元素***\n");
    printf("			***4.清空栈***\n");
    printf("			***5.销毁栈***\n");
    printf("			***6.检测栈长度***\n");
    printf("			***7.入栈***\n");
    printf("			***8.出栈***\n");
    printf("			***9.遍历链栈\n");
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
						printf("空链栈创建成功。");
						//TODO
					}
					else
					printf("空链栈创建失败。");
				break;
			case 2:
			if(isEmptyLStack(&s)){
				printf("该链栈为空链栈。");
				//TODO
			}
			else 
			printf("该链栈为非空链栈。");
				break;
			case 3:
				if(isEmptyLStack(&s)){
					printf("该链栈为空，请先创建非空链栈。");
					//TODO
				}
				else
				getTopLStack(&s,&num);
				printf("栈顶数据为：%d",num);
				//TODO
				break;
			case 4:
				if(isEmptyLStack(&s)){
									printf("该链栈为空，请先创建非空链栈。");
									//TODO
								}
				else
				clearLStack(&s);
				printf("链栈已清空。");
				break;
				case 5:
					if(isEmptyLStack(&s)){
										printf("该链栈为空，请先创建非空链栈。");
										//TODO
									}
					else 
					destroyLStack(&s);
					printf("链栈已销毁。");				
					break ;
				case 6:
					if(isEmptyLStack(&s)){
										printf("该链栈为空，请先创建非空链栈。");
										//TODO
									}
					else LStackLength(&s,&length);			
					break;
				case 7:
					printf("请输入入栈的数据");
					a=judge_int();
					pushLStack(&s,a);
					printf("入栈成功。");
					
					break;		
					case 8:
						popLStack(&s,&b);
						break;
					case 9:
						if(isEmptyLStack(&s)){
										      printf("该链栈为空，请先创建非空链栈。");
										}	
						else
						TraverseList(&s,visit);			
						break;	
					case 10:
						destroyLStack(&s);
						break;	
					default:
					printf("请重新输入数字1-10.");
					break;		
		}
	}while(choice!=10);
}
 
