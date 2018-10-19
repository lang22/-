#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include <iomanip>
using namespace std;
//�������ڵ㶨��
typedef struct node 
{
	char data;           //����
	struct node* lchild; //����
	struct node* rchild; //�Һ���
	int depth;           //���
}*BTnode;
//����һ�ö�����
void createTree(BTnode& root, int nowdep) {
	char c;
	cin >> c;
	if (c != '#')
	{
		root = new node();
		root->data = c;
		root->depth = nowdep;
	}
	else {
		return;
	}
	//���õݹ���������
	createTree(root->lchild, nowdep+1);
	createTree(root->rchild, nowdep+1);
}
//���������ʽ�����ӡ�������ṹ
void printTree(BTnode root) {
	if (root == nullptr)
		return;
	printTree(root->rchild);
	cout << std::setw(root->depth)<<setfill('.') << root->data << endl;
	printTree(root->lchild);
}
//�������������
void PRTraverse(BTnode& root) {
	if (root == nullptr)
		return;
	cout << root->data<<" ";
	PRTraverse(root->lchild);
	PRTraverse(root->rchild);
}
//�������������
void IOTraverse(BTnode& root) {
	if (root == nullptr)
		return;
	IOTraverse(root->lchild);
	cout << root->data<<" ";
	IOTraverse(root->rchild);	
}
//�������������
void POTraverse(BTnode& root) {
	if (root == nullptr)
		return;
	POTraverse(root->lchild);
	POTraverse(root->rchild);
	cout << root->data << " ";
}