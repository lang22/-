// 7/11/2017 XLL
#include"BaseConverting.h"
#include<iostream>
#include<string>
using namespace std;
int match() {	
	Stack<char> bra;
	string s;
	bool flag = true;
	cout << "***********************************************************" << endl;
	cout << "Please input a string consists of brackets only!" << endl;
	here: cin >> s;
	cout << "***********************************************************" << endl;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i]=='[')
			bra.push(s[i]);
		else if (s[i] == ')') {
			if (bra.top() == '(') {
				flag = true;
				bra.pop();
			}
			else {
				flag = false;
				cout << "�˴�����ƥ�䲻�Ϸ�!" << endl;
				return 0;
			}
		}
		else if (s[i] == ']') {
			if (bra.top() == '[') {
				flag = true;
				bra.pop();
			}
			else {
				flag = false;
				cout << "�˴�����ƥ�䲻�Ϸ�!" << endl;
				return 0;
			}
		}
		else
		{
			cout << "You bad!Invalid input!Please resume!" << endl;
			goto here;
		}
	}
	cout << (flag&&bra.empty() ? "ƥ��!" : "") << endl;
	cout << "***********************************************************" << endl;
	return 0;
}