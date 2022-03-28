#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 21
#define ERROR 0
#define SUCCESS 1
typedef struct Num{
    int msg[MAX_SIZE];
    int top;
}numStack;
void initStack(numStack *num){
    num->top = 0;
}

int push(numStack *num,int e){
    if(num->top == MAX_SIZE)
        return ERROR;
    num->msg[num->top++] = e;
    return SUCCESS;
}
int pop(numStack *num,int *e){
    if(num->top == 0)
        return ERROR;
    *e = num->msg[--num->top];
    return SUCCESS;
}
int getTop(numStack *num,int *e){
    if(num->top == 0)
        return ERROR;
    *e = num->msg[num->top - 1];
    return SUCCESS;
}
int isEmpty(numStack *num){
    return num->top == 0;
}
typedef struct FU{
    char msg[MAX_SIZE];
    int top;
}fuStack;
void initFuStack(fuStack *fu){
    fu->top = 0;
}

int pushFu(fuStack *fu,char e){
    if(fu->top == MAX_SIZE)
        return ERROR;
    fu->msg[fu->top++] = e;
    return SUCCESS;
}
int popFu(fuStack *fu,char *e){
    if(fu->top == 0)
        return ERROR;
    *e = fu->msg[--fu->top];
    return SUCCESS;
}
int getFuTop(fuStack *fu,char *e){
    if(fu->top == 0)
        return ERROR;
    *e = fu->msg[fu->top - 1];
    return SUCCESS;
}
int isFuEmpty(fuStack *fu){
    return fu->top == 0;
}
int level(char ch){
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}
int isNum(char ch){
    if(ch >= '0' && ch <= '9')
        return 1;
    return 0;
}
int yunsuan(char ch,numStack *num,int *result){
   int a,b;
   pop(num,&a);
   pop(num,&b);//����ջ����������Ԫ�أ��������ǵ�ֵ����a��b
   switch(ch){
      case '+':
          *result = b + a;
           break;
      case '-':
          *result = b - a;
           break;
      case '*':
          *result = b * a;
           break;
      case '/':
          if(a == 0){
            return ERROR;//������������㷨����ô����ERROR
          }
          *result = b / a;
          break;
   }
   return SUCCESS;
}
void getPreExpression(numStack *num,fuStack *fu,char *msg){
    int i,result,j,k = 0,a,b,count = 0;//count��ʾ���ֵĸ���
    char ch,tmp,arr[MAX_SIZE];//arr�������ڶ�λ���ֵ�ƴ��,ch��ʾ��ǰ���ַ���tmp��ʾfuStack��ջ��Ԫ��
    for(i = 0; msg[i] != '\0'; i++){
        ch = msg[i];
        if(isNum(ch)){
            j = i;
            k = 0;//����k
            //ƴ������
            while(isNum(msg[j])){
                arr[k++] = msg[j];
                j++;
            }
            arr[k] = '\0';
            i = j - 1;
            a = atoi(arr);//����atoi�������Ӷ��������λ���ֵ��ַ���ת����������
            count++;
            if(count == 1)
                printf("%d",a);//����ǵ�һ�����֣���ôǰ�治��Ҫ���һ���ո񣬷���Ҫ��ǰ������ո�
            else
                printf(" %d",a);
            push(num,a);//������ѹ��ջ��
        }else{
            if(isFuEmpty(fu) || ch == '('){
                pushFu(fu,ch);
            }else{
         
                getFuTop(fu,&tmp);
                if(tmp == '('){
                    //���ջ��Ԫ����һ�������ţ���ôֱ����ջ
                    pushFu(fu,ch);
                }else{
                  //��ǰ���ַ�����һ�������ţ���ô��Ҫ�жϵ�ǰ�ķ����Ƿ�Ϊһ��������
                  if(ch == ')'){
                    getFuTop(fu,&tmp);
                    while(tmp != '('){
                       popFu(fu,&tmp);
                       printf(" %c",tmp);
                       if(!yunsuan(tmp,num,&result)){
                          printf("������������Ϊ0���������!!!\n");
                          return;
                       }
                       push(num,result);//�������������㷨����ô��������ѹ�뵽ջ��
                       getFuTop(fu,&tmp);
                    }
                    popFu(fu,&tmp);
                  }else{
                     //��ǰ�ķ�����һ����ͨ���ţ���ô��Ҫ�Ƚ����ȼ�
                     label:
                         if(isFuEmpty(fu) || level(ch) > level(tmp)){
                                //��ǰ���ŵ����ȼ�����ջ�����ŵ����ȼ�����ôֱ����ջ
                            pushFu(fu,ch);
                         }else{
                             //��ǰ�ķ��ŵ����ȼ�С�ڵ���ջ�����ŵ����ȼ�����ô��ջ��Ԫ�ش�fuջ�����������
                            popFu(fu,&tmp);
                            printf(" %c",tmp); 
                            if(!yunsuan(tmp,num,&result)){
                                printf("������������Ϊ0���������!!!\n");
                                return;
                            }
                            push(num,result);//�������������㷨����ô��������ѹ�뵽ջ��
                            getFuTop(fu,&tmp);
                            goto label;
                         }
                  }
                }
            }

        }
    }
    while(!isFuEmpty(fu)){
         popFu(fu,&tmp);
         printf(" %c",tmp);
         if(!yunsuan(tmp,num,&result)){
         //��������Ӧ�����㣬Ȼ�󽫶�Ӧ����������ֵ��result
            printf("������������Ϊ0���������!!!\n");
            return;
         }
         push(num,result);//�������������㷨����ô��������ѹ�뵽ջ��
    }
    printf("\n");
    pop(num,&a);
    printf("%s��������Ϊ%d\n",msg,a);
}
int main(){
    numStack *num = (numStack *)malloc(sizeof(numStack));
    fuStack *fu= (fuStack *)malloc(sizeof(fuStack));
    char msg[MAX_SIZE];
    initStack(num);//��ջ���г�ʼ��
    initFuStack(fu);
    printf("������������׺����ʽ��\n");
    scanf("%s",msg);//�����ַ���
    getPreExpression(num,fu,msg);//����׺���ʽ�����ͬʱ���������������
    return 0;
}


