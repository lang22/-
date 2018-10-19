#include<iostream>
#include"BST.h"
using namespace std;
int k[INT16_MAX];
int n;
int flag;
void checkCin(int& b, int min, int max) //输入异常处理
{
	while (cin.fail() || b<min || b>max)
	{
		cin.clear();
		cin.sync();
		cin.ignore();
		//		cout << "*************************************************" << endl;
		cout << "***********非法输入!请重新输入正确值!************" << endl;
		//		cout << "*************************************************" << endl;
		cout << "重新输入: ";
		cin >> b;
	}
}
void read() {
	cout << "请输入二叉搜索树的总节点个数" << endl;
	cin >> n;
	checkCin(n, 1, INT16_MAX);
	cout << "请依次输入每个节点的键值" << endl;
	for (int i = 0; i < n;i++) {
		cout << i + 1 << ".:";
		cin >> k[i];
		checkCin(k[i], INT16_MIN, INT16_MAX);
	}
}
int main()
{
	int choice;
	BTnode root = nullptr;
	while (true)
	{
		cout << "***********************************************************" << endl;
		cout << "****************************实验六*************************" << endl;
		cout << "**************************二叉搜索树***********************" << endl;
		cout << "******************1.建立一棵新的二叉搜索树*****************" << endl;
		cout << "******************2.在当前树中插入节点*********************" << endl;
		cout << "******************3.在当前树中删除节点*********************" << endl;
		cout << "******************4.遍历当前树*****************************" << endl;
		cout << "******************5.打印当前树*****************************" << endl;
		cout << "******************6.查找键值*******************************" << endl;
		cout << "***********************************************************" << endl;
		cout << "请选择：";
		cin >> choice;
		checkCin(choice, 1, 6);	
		switch (choice)
		{
		case 1:
			read();
			root = nullptr;
			createBST(root, k, n);
			break;
		case 2:
			cout << "请输入一个键值：";
			int newkey; cin >> newkey;
			checkCin(newkey, INT16_MIN, INT16_MAX);
			Insert(root, newkey);
			cout << "插入成功！" << endl;
			getDepth(root, 1);
			printTree(root);
			break;
		case 3:
			cout << "请输入要删除的节点的键值：" << endl;
			int badkey; cin >> badkey;
			checkCin(badkey, INT16_MIN, INT16_MAX);
			Delete(root, badkey);
			break;
		case 4:
			IOTraverse(root);
			cout << "\b\b" << endl;
			break;
		case 5:
			printTree(root);
			break;
		case 6:
			cout << "请输入要查找的键值：";
			int goodkey; cin >> goodkey;
			checkCin(goodkey, INT16_MIN, INT16_MAX);
			flag = search(root, goodkey, 1);
			if (flag)
				cout << "查找成功！查找长度为" << flag << endl;
			else cout << "查找失败！" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}