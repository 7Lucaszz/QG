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
   pop(num,&b);//将从栈中跳出两个元素，并将他们的值赋给a、b
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
            return ERROR;//如果不符合运算法则，那么返回ERROR
          }
          *result = b / a;
          break;
   }
   return SUCCESS;
}
void getPreExpression(numStack *num,fuStack *fu,char *msg){
    int i,result,j,k = 0,a,b,count = 0;//count表示数字的个数
    char ch,tmp,arr[MAX_SIZE];//arr数组用于多位数字的拼接,ch表示当前的字符，tmp表示fuStack的栈顶元素
    for(i = 0; msg[i] != '\0'; i++){
        ch = msg[i];
        if(isNum(ch)){
            j = i;
            k = 0;//重置k
            //拼接数字
            while(isNum(msg[j])){
                arr[k++] = msg[j];
                j++;
            }
            arr[k] = '\0';
            i = j - 1;
            a = atoi(arr);//调用atoi方法，从而将这个多位数字的字符串转成整形数字
            count++;
            if(count == 1)
                printf("%d",a);//如果是第一个数字，那么前面不需要输出一个空格，否则要在前面输出空格
            else
                printf(" %d",a);
            push(num,a);//将数字压入栈中
        }else{
            if(isFuEmpty(fu) || ch == '('){
                pushFu(fu,ch);
            }else{
         
                getFuTop(fu,&tmp);
                if(tmp == '('){
                    //如果栈顶元素是一个左括号，那么直接入栈
                    pushFu(fu,ch);
                }else{
                  //当前的字符不是一个左括号，那么需要判断当前的符号是否为一个右括号
                  if(ch == ')'){
                    getFuTop(fu,&tmp);
                    while(tmp != '('){
                       popFu(fu,&tmp);
                       printf(" %c",tmp);
                       if(!yunsuan(tmp,num,&result)){
                          printf("被除数不可以为0，运算错误!!!\n");
                          return;
                       }
                       push(num,result);//如果运算符合运算法则，那么将运算结果压入到栈中
                       getFuTop(fu,&tmp);
                    }
                    popFu(fu,&tmp);
                  }else{
                     //当前的符号是一个普通符号，那么需要比较优先级
                     label:
                         if(isFuEmpty(fu) || level(ch) > level(tmp)){
                                //当前符号的优先级大于栈顶符号的优先级，那么直接入栈
                            pushFu(fu,ch);
                         }else{
                             //当前的符号的优先级小于等于栈顶符号的优先级，那么将栈顶元素从fu栈中跳出并输出
                            popFu(fu,&tmp);
                            printf(" %c",tmp); 
                            if(!yunsuan(tmp,num,&result)){
                                printf("被除数不可以为0，运算错误!!!\n");
                                return;
                            }
                            push(num,result);//如果运算符合运算法则，那么将运算结果压入到栈中
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
         //将进行相应的运算，然后将对应的运算结果赋值给result
            printf("被除数不可以为0，运算错误!!!\n");
            return;
         }
         push(num,result);//如果运算符合运算法则，那么将运算结果压入到栈中
    }
    printf("\n");
    pop(num,&a);
    printf("%s的运算结果为%d\n",msg,a);
}
int main(){
    numStack *num = (numStack *)malloc(sizeof(numStack));
    fuStack *fu= (fuStack *)malloc(sizeof(fuStack));
    char msg[MAX_SIZE];
    initStack(num);//将栈进行初始化
    initFuStack(fu);
    printf("请输入您的中缀运算式：\n");
    scanf("%s",msg);//输入字符串
    getPreExpression(num,fu,msg);//将后缀表达式输出，同时将它的运算结果输出
    return 0;
}


