#include<iostream>
#include<iomanip>
#define SIZE 100
#define ADDSIZE 10 //附加容量（可多次扩容）
using namespace std;
struct SqStack{
	int *base;
	int *top;
	int size;
};
int Init(SqStack &s)//初始化栈
{
	s.base=(int*)malloc(sizeof(int)*SIZE);
	if(!s.base) exit(0);
	s.top=s.base;
	s.size=SIZE;
}
int Push(SqStack &s,int e)//把元素e压入栈顶
{
	if(s.top-s.base>s.size)//栈满，追加ADDSIZE大小的空间
	{
		s.base=(int *)realloc(s.base,(s.size+ADDSIZE)*sizeof(int));
		if(!s.base) exit(0);
		s.size=s.size+ADDSIZE;
		
	}
	*s.top=e;
	s.top++;
	return 1;
}
int Pop(SqStack &s,int &e)//取出栈顶元素，并删除栈顶
{
	if(s.top==s.base) return 0;
	s.top--;
	e=*s.top;
	return 1;
}
int IsEmpty(SqStack s)//判空
{
	if(s.top==s.base) return 1;
	else return 0;
}
void Destory(SqStack &s)//销毁栈    
{
	free(s.base);
}
int main()
{

}
