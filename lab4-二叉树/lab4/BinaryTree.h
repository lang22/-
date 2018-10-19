#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include <iomanip>
using namespace std;
//二叉树节点定义
typedef struct node 
{
	char data;           //数据
	struct node* lchild; //左孩子
	struct node* rchild; //右孩子
	int depth;           //深度
}*BTnode;
//创建一棵二叉树
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
	//利用递归层数算深度
	createTree(root->lchild, nowdep+1);
	createTree(root->rchild, nowdep+1);
}
//按凹入表形式横向打印二叉树结构
void printTree(BTnode root) {
	if (root == nullptr)
		return;
	printTree(root->rchild);
	cout << std::setw(root->depth)<<setfill('.') << root->data << endl;
	printTree(root->lchild);
}
//先序遍历二叉树
void PRTraverse(BTnode& root) {
	if (root == nullptr)
		return;
	cout << root->data<<" ";
	PRTraverse(root->lchild);
	PRTraverse(root->rchild);
}
//中序遍历二叉树
void IOTraverse(BTnode& root) {
	if (root == nullptr)
		return;
	IOTraverse(root->lchild);
	cout << root->data<<" ";
	IOTraverse(root->rchild);	
}
//后序遍历二叉树
void POTraverse(BTnode& root) {
	if (root == nullptr)
		return;
	POTraverse(root->lchild);
	POTraverse(root->rchild);
	cout << root->data << " ";
}