#include <iostream>
class array
{
public:
	array(int Int_Queue);
	~array();
	void InitArray();//清理队列所有数据
	bool tmptyArray()const;//判断队列是不是空
	bool insertArray(int tmp);//插入数据
	bool DeleArray(int tmp);//删除数据
	bool IfArray();//判断是否满了
	void LookArray();//浏览队列中的数据
	int ArrayLen();//返回队列的大小

private:
	int Queuelen;//队列大小
	int H_Queue;//队列头
	int L_Queue;//队列尾
	int* P_Queue;//队列指针
	int QueueCapaticy;//队列空间大小
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