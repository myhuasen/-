#include <iostream>
using namespace std;

typedef struct node {

	int data;
	node *next;

}ElemSN;
typedef ElemSN *List;
typedef ElemSN *Position;

//���������Ƿ�Ϊ��
int IsEmpty(List L)
{
	return L->next == NULL;
}

//���Ե�ǰλ���Ƿ��������ĩβ�ĺ���
int IsLast(Position P)
{
	return P->next == NULL;
}

//������������������ĸ�λ��
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
//ɾ������
void Delete(int x, List L)
{
	Position P, tmp;
	P = FindPrevious(x, L);
	tmp = P;
	if (!IsLast(P))
	{
		tmp->next = P->next;
		P->next = tmp->next;
		delete(tmp);//�ͷ��ڴ�
	}
}

void Insert(int x, List L, Position P)
{
	Position tmp;
	tmp = new struct node;
	if (tmp == NULL)
		cout << "Ϊ��";
	tmp->data = x;
	tmp->next = P->next;
	P->next = tmp;
}
