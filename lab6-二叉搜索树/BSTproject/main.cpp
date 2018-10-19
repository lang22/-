#include<iostream>
#include"BST.h"
using namespace std;
int k[INT16_MAX];
int n;
int flag;
void checkCin(int& b, int min, int max) //�����쳣����
{
	while (cin.fail() || b<min || b>max)
	{
		cin.clear();
		cin.sync();
		cin.ignore();
		//		cout << "*************************************************" << endl;
		cout << "***********�Ƿ�����!������������ȷֵ!************" << endl;
		//		cout << "*************************************************" << endl;
		cout << "��������: ";
		cin >> b;
	}
}
void read() {
	cout << "������������������ܽڵ����" << endl;
	cin >> n;
	checkCin(n, 1, INT16_MAX);
	cout << "����������ÿ���ڵ�ļ�ֵ" << endl;
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
		cout << "****************************ʵ����*************************" << endl;
		cout << "**************************����������***********************" << endl;
		cout << "******************1.����һ���µĶ���������*****************" << endl;
		cout << "******************2.�ڵ�ǰ���в���ڵ�*********************" << endl;
		cout << "******************3.�ڵ�ǰ����ɾ���ڵ�*********************" << endl;
		cout << "******************4.������ǰ��*****************************" << endl;
		cout << "******************5.��ӡ��ǰ��*****************************" << endl;
		cout << "******************6.���Ҽ�ֵ*******************************" << endl;
		cout << "***********************************************************" << endl;
		cout << "��ѡ��";
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
			cout << "������һ����ֵ��";
			int newkey; cin >> newkey;
			checkCin(newkey, INT16_MIN, INT16_MAX);
			Insert(root, newkey);
			cout << "����ɹ���" << endl;
			getDepth(root, 1);
			printTree(root);
			break;
		case 3:
			cout << "������Ҫɾ���Ľڵ�ļ�ֵ��" << endl;
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
			cout << "������Ҫ���ҵļ�ֵ��";
			int goodkey; cin >> goodkey;
			checkCin(goodkey, INT16_MIN, INT16_MAX);
			flag = search(root, goodkey, 1);
			if (flag)
				cout << "���ҳɹ������ҳ���Ϊ" << flag << endl;
			else cout << "����ʧ�ܣ�" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}