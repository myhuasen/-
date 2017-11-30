#include <iostream>
class array
{
public:
	array(int Int_Queue);
	~array();
	void InitArray();//���������������
	bool tmptyArray()const;//�ж϶����ǲ��ǿ�
	bool insertArray(int tmp);//��������
	bool DeleArray(int tmp);//ɾ������
	bool IfArray();//�ж��Ƿ�����
	void LookArray();//��������е�����
	int ArrayLen();//���ض��еĴ�С

private:
	int Queuelen;//���д�С
	int H_Queue;//����ͷ
	int L_Queue;//����β
	int* P_Queue;//����ָ��
	int QueueCapaticy;//���пռ��С
};

array::array(int Int_Queue)
{
	Queuelen = 0;
	H_Queue = 0;
	L_Queue = 0;
	P_Queue = new int[QueueCapaticy];
	QueueCapaticy = Int_Queue;
}
array::~array()
{
	delete[] P_Queue;
	P_Queue = NULL;
}

inline void array::InitArray()
{
	H_Queue = 0;
	L_Queue = 0;
	Queuelen = 0;
}

inline bool array::tmptyArray() const
{
	return Queuelen==0? false:true;
}
bool array::insertArray(int tmp)
{
	if (IfArray() == false)
	{
		P_Queue[L_Queue] = tmp;
		L_Queue++;
		L_Queue = L_Queue % QueueCapaticy;
		Queuelen++;
		return true;
	}
	else
	{
		return false;
	}
	
}
bool array::DeleArray(int tmp)
{
	if (tmptyArray() == false)
	{
		P_Queue[H_Queue] = tmp;
		H_Queue++;
		H_Queue = H_Queue % QueueCapaticy;
		Queuelen--;
		return true;
	}
	else
		return false;
}
inline bool array::IfArray()
{
	return Queuelen == QueueCapaticy ? true : false;
}
inline void array::LookArray()
{
	for (int i = H_Queue; i < Queuelen + H_Queue; i++)
	{
		std::cout << P_Queue[i%QueueCapaticy];
	}
}
inline int array::ArrayLen()
{
	return Queuelen;
}