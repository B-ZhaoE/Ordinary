#include<iostream>
#include<iomanip>
#define SIZE 100
#define ADDSIZE 10 //�����������ɶ�����ݣ�
using namespace std;
struct SqStack{
	int *base;
	int *top;
	int size;
};
int Init(SqStack &s)//��ʼ��ջ
{
	s.base=(int*)malloc(sizeof(int)*SIZE);
	if(!s.base) exit(0);
	s.top=s.base;
	s.size=SIZE;
}
int Push(SqStack &s,int e)//��Ԫ��eѹ��ջ��
{
	if(s.top-s.base>s.size)//ջ����׷��ADDSIZE��С�Ŀռ�
	{
		s.base=(int *)realloc(s.base,(s.size+ADDSIZE)*sizeof(int));
		if(!s.base) exit(0);
		s.size=s.size+ADDSIZE;
		
	}
	*s.top=e;
	s.top++;
	return 1;
}
int Pop(SqStack &s,int &e)//ȡ��ջ��Ԫ�أ���ɾ��ջ��
{
	if(s.top==s.base) return 0;
	s.top--;
	e=*s.top;
	return 1;
}
int IsEmpty(SqStack s)//�п�
{
	if(s.top==s.base) return 1;
	else return 0;
}
void Destory(SqStack &s)//����ջ    
{
	free(s.base);
}
int main()
{

}
