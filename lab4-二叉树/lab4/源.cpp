#include"BinaryTree.h"
#include<iostream>
using namespace std;

int main() {
	cout << "**********************************" << endl;
	cout << "�밴�����������������!" << endl;
	BTnode tree = new node();
	createTree(tree, 1);
	cout << "**********************************" << endl;	
	cout << "�������ṹ����:" << endl;
	printTree(tree);
	cout << "**********************************" << endl;
	cout << "�������������,�������:" << endl;
	PRTraverse(tree);
	cout << endl;
	cout << "**********************************" << endl;
	cout << "�������������,�������:" << endl;
	IOTraverse(tree);
	cout << endl;
	cout << "**********************************" << endl;
	cout << "�������������,�������:" << endl;
	POTraverse(tree);
	cout << endl;
	cout << "**********************************" << endl;
	return 0;
}