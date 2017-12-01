#include <iostream>
using namespace::std;

struct TreeNode
{
	char element;//�ýڵ��Ԫ��
	TreeNode *FistChid;//ָ��ڵ��һ������
	TreeNode *NextSibling;//ָ��ýڵ���ֵܽڵ�
};

class Tree
{
public:
	Tree(TreeNode * r = NULL) :root(r) {};
	Tree(int node_num);
	~Tree();

	void addNode(int x, int y);//������ݽ�ȥ
	void preOrder();//ǰ�����
	void print();//��ӡ

private:
	void print(TreeNode * node, int num);
	void addBrotherNode(TreeNode* bro, TreeNode* node);
	void preOrder(TreeNode * parent);

private:
	TreeNode * root;
};

Tree::Tree(int node_num)
{
	root = new TreeNode[node_num];
	char ch = 'A';
	for (int i = 0; i < node_num; ++i)
	{
		root[i].element = ch + i;
		root[i].FistChid = NULL;
		root[i].NextSibling = NULL;
	}
}

void Tree::print()
{
	print(root, 0);
}

Tree::~Tree()
{
	if (root != NULL)
	{
		delete[]root;
	}
}

void Tree::addNode(int x, int y)
{
	TreeNode * parent = &root[x];
	TreeNode * node = &root[y];

	if (parent->FistChid == NULL)
		parent->FistChid = node;
	else
		addBrotherNode(parent->FistChid, node);
}
void Tree::addBrotherNode(TreeNode * bro, TreeNode * node)
{
	//������ǿյ��Ǿ�Ѱ�ҵ��¸�NULL
	if (bro->NextSibling == NULL)
		bro->NextSibling = node;
	else
		addBrotherNode(bro->NextSibling, node);
}

void Tree::preOrder()
{
	cout << "ǰ�����";
	preOrder(root);
	cout << endl;
}

void Tree::preOrder(TreeNode * parent)
{
	if (parent != NULL)
	{
		cout << parent->element << " ";
		preOrder(parent->FistChid);
		preOrder(parent->NextSibling);
	}
}

void PrintSpace(int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
		cout << " ";
	for (; i < num - 2; ++i)
		cout << "|";
	for (; i < num; ++i)
		cout << "_";
}

void Tree::print(TreeNode * node, int num)
{
	if (node != NULL)
	{
		PrintSpace(num);
		cout << node->element << endl;
		print(node->FistChid, num + 4);
		print(node->NextSibling, num);
	}
}
int main()
{
	Tree tree(16);
	tree.addNode(0, 1);
	tree.addNode(0, 2);
	tree.addNode(0, 3);
	tree.addNode(0, 4);
	tree.addNode(0, 5);
	tree.addNode(0, 6);
	tree.addNode(3, 7);
	tree.addNode(4, 8);
	tree.addNode(4, 9);
	tree.addNode(5, 10);
	tree.addNode(5, 11);
	tree.addNode(5, 12);
	tree.addNode(6, 13);
	tree.addNode(9, 14);
	tree.addNode(9, 15);
	cout << "tree1" << endl;
	tree.preOrder();
	tree.print();
}