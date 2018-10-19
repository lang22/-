#include"BinaryTree.h"
#include<iostream>
using namespace std;

int main() {
	cout << "**********************************" << endl;
	cout << "请按先序输入二叉树序列!" << endl;
	BTnode tree = new node();
	createTree(tree, 1);
	cout << "**********************************" << endl;	
	cout << "二叉树结构如下:" << endl;
	printTree(tree);
	cout << "**********************************" << endl;
	cout << "先序遍历二叉树,结果如下:" << endl;
	PRTraverse(tree);
	cout << endl;
	cout << "**********************************" << endl;
	cout << "中序遍历二叉树,结果如下:" << endl;
	IOTraverse(tree);
	cout << endl;
	cout << "**********************************" << endl;
	cout << "后序遍历二叉树,结果如下:" << endl;
	POTraverse(tree);
	cout << endl;
	cout << "**********************************" << endl;
	return 0;
}