#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include <iomanip>
using namespace std;
int getBits(int a) {
	int count = 0;
	while (a != 0)
	{
		count++;
		a /= 10;
	}
	return count;
}
//�����������ڵ㶨��
typedef struct node
{
	int key;             //��ֵ
	struct node* lchild; //����
	struct node* rchild; //�Һ���
	int depth;           //���
}*BTnode;
//�жϺ��������ӻ����Һ���
BTnode& realChild(BTnode parent, BTnode& kid) {
	if (kid == parent->lchild)
		return parent->lchild;
	else
		return parent->rchild;
}
//�õ���֧�����ڵ��Ψһ����
BTnode& realChild(BTnode parent){
	if (parent->lchild && !parent->rchild)
		return parent->lchild;
	else if (!parent->lchild && parent->rchild)
		return parent->rchild;
	else
		return parent;
}

void getDepth(BTnode& root, int nowdep) {
	if (!root)
		return;
	root->depth = nowdep;	
	//���õݹ���������
	getDepth(root->lchild, nowdep + 1);
	getDepth(root->rchild, nowdep + 1);
}
//���������ʽ�����ӡ�����������ṹ
void printTree(BTnode root) {
	if (root == nullptr)
		return;
	printTree(root->rchild);
	cout <<std::setw(root->depth+getBits(root->key)-1) << setfill('+') << root->key << endl;
	printTree(root->lchild);
}
//�ڶ����������в�����
bool Insert(BTnode& root, int newKey) {
	
	if (root == nullptr)
	{
		root = new node();
		root->key = newKey;
		return true;
	}
	else
	{
		if (newKey < root->key)
			Insert(root->lchild, newKey);
		else if (newKey > root->key)
			Insert(root->rchild, newKey);
		else
			return false;
	}
}
//�ڶ�����������ɾ���ڵ�
bool Delete(BTnode& root, int badKey) {
	bool isFound = false;
	BTnode p = root;
	BTnode q = new node();
	//�ҵ�Ҫɾ���Ľڵ�p�������ĸ���q
	while (p && !isFound) {
		if (p->key == badKey)
			isFound = true;
		else if (p->key > badKey) {
			q = p;
			p = p->lchild;
		}
		else {
			q = p;
			p = p->rchild;
		}
	}
	if (!isFound) {
		cout<<"����û����Ҫ�ҵĽڵ㣡"<<endl;
		return isFound;
	}
	//pΪҶ�ڵ㣬ֱ��ɾ��	
	if (!p->lchild && !p->lchild) {	
		if (p == root)//pΪ���ڵ㣨ֻ��һ���ڵ������
			root = nullptr;
		else          //p�Ǹ��ڵ�
		{
			realChild(q, p) = nullptr;
		}
		delete p;
	}
	//pֻ��һ������
	else if (realChild(p) != p) {
		if (p == root)//p�Ǹ��ڵ㣬ɾ��p����p�ĵ�һ������Ϊ�µĸ��ڵ�
			root = realChild(p);
		else          //P���Ǹ��ڵ㣬��p��������p�ĸ��׽ڵ�������ɾ��p
		{
			realChild(q, p) = realChild(p);
		}
		delete p;
	}	
	//p����������
	else
	{
		//�ҵ�p�ĺ��,������������ڵ�
		BTnode successor = p->rchild;
		BTnode st = p;
		for (; successor->lchild; successor = successor->lchild)
			st = successor;
		//����̵ļ�ֵ��Ϊp���¼�ֵ
		p->key = successor->key;
		//ɾ��p�ĺ��successor����successor��������������
		realChild(st, successor) = successor->rchild;
		delete successor;
	}
	cout << (isFound ? "ɾ���ɹ���" : "ɾ��ʧ�ܣ�") << endl;
	getDepth(root, 1);//���¼���ÿ���ڵ�����
	printTree(root);  //��ӡ�µĶ�����
	return isFound;
}
//��������������
void createBST(BTnode& root,int k[],int n) {
	sort(k, k + n-1);
	swap(k[0], k[n / 2]);
	for (int i = 0; i < n; i++)
		Insert(root, k[i]);
//	Delete(root, 0);
	getDepth(root, 1);
	cout << "�����ɹ���" << endl;
	printTree(root);
}
//�����������������
void IOTraverse(BTnode& root) {
	if (root == nullptr)
		return;
	IOTraverse(root->lchild);
	cout << root->key << "->";
	IOTraverse(root->rchild);
}
int search(BTnode root, int goodkey, int slen) {
	if (root == nullptr)
		return 0;
	if (root->key == goodkey)
		return slen;
	else if (goodkey < root->key)
		search(root->lchild, goodkey, slen + 1);
	else
		search(root->rchild, goodkey, slen + 1);
}
