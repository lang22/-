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
//二叉搜索树节点定义
typedef struct node
{
	int key;             //键值
	struct node* lchild; //左孩子
	struct node* rchild; //右孩子
	int depth;           //深度
}*BTnode;
//判断孩子是左孩子还是右孩子
BTnode& realChild(BTnode parent, BTnode& kid) {
	if (kid == parent->lchild)
		return parent->lchild;
	else
		return parent->rchild;
}
//得到单支子树节点的唯一子树
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
	//利用递归层数算深度
	getDepth(root->lchild, nowdep + 1);
	getDepth(root->rchild, nowdep + 1);
}
//按凹入表形式横向打印二叉搜索树结构
void printTree(BTnode root) {
	if (root == nullptr)
		return;
	printTree(root->rchild);
	cout <<std::setw(root->depth+getBits(root->key)-1) << setfill('+') << root->key << endl;
	printTree(root->lchild);
}
//在二叉搜索树中插入结点
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
//在二叉搜索树中删除节点
bool Delete(BTnode& root, int badKey) {
	bool isFound = false;
	BTnode p = root;
	BTnode q = new node();
	//找到要删除的节点p，及它的父亲q
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
		cout<<"树中没有你要找的节点！"<<endl;
		return isFound;
	}
	//p为叶节点，直接删除	
	if (!p->lchild && !p->lchild) {	
		if (p == root)//p为根节点（只有一个节点的树）
			root = nullptr;
		else          //p非根节点
		{
			realChild(q, p) = nullptr;
		}
		delete p;
	}
	//p只有一个子树
	else if (realChild(p) != p) {
		if (p == root)//p是根节点，删除p，将p的单一孩子作为新的根节点
			root = realChild(p);
		else          //P不是根节点，让p的子树与p的父亲节点相连，删除p
		{
			realChild(q, p) = realChild(p);
		}
		delete p;
	}	
	//p有两个子树
	else
	{
		//找到p的后继,右子树的最左节点
		BTnode successor = p->rchild;
		BTnode st = p;
		for (; successor->lchild; successor = successor->lchild)
			st = successor;
		//将后继的键值作为p的新键值
		p->key = successor->key;
		//删除p的后继successor，用successor的右子树代替它
		realChild(st, successor) = successor->rchild;
		delete successor;
	}
	cout << (isFound ? "删除成功！" : "删除失败！") << endl;
	getDepth(root, 1);//重新计算每个节点的深度
	printTree(root);  //打印新的二叉树
	return isFound;
}
//建立二叉搜索树
void createBST(BTnode& root,int k[],int n) {
	sort(k, k + n-1);
	swap(k[0], k[n / 2]);
	for (int i = 0; i < n; i++)
		Insert(root, k[i]);
//	Delete(root, 0);
	getDepth(root, 1);
	cout << "创建成功！" << endl;
	printTree(root);
}
//中序遍历二叉搜索树
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
