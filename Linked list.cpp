#include <iostream>
using namespace std;

typedef struct node {

	int data;
	node *next;

}ElemSN;
typedef ElemSN *List;
typedef ElemSN *Position;

//测试链表是否为空
int IsEmpty(List L)
{
	return L->next == NULL;
}

//测试当前位置是否是链表的末尾的函数
int IsLast(Position P)
{
	return P->next == NULL;
}

//查找输入的数在链表哪个位置
Position Find(int x, List L)
{
	Position P;
	P = L->next;
	while (P != NULL && P->data != x)
		P = P->next;
	return P;
}

//
Position FindPrevious(int x, List L)
{
	Position P;
	P = L;
	while (P->next != NULL && P->next->data)
	{
		P = P->next;
	}
	return P;
}
//删除链表
void Delete(int x, List L)
{
	Position P, tmp;
	P = FindPrevious(x, L);
	tmp = P;
	if (!IsLast(P))
	{
		tmp->next = P->next;
		P->next = tmp->next;
		delete(tmp);//释放内存
	}
}

void Insert(int x, List L, Position P)
{
	Position tmp;
	tmp = new struct node;
	if (tmp == NULL)
		cout << "为空";
	tmp->data = x;
	tmp->next = P->next;
	P->next = tmp;
}
