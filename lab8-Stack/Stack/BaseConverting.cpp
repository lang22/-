#include"BaseConverting.h"
#include<iostream>
using namespace std;
void convert() {
	Stack<int> num;
	cout << "please enter a postive number!" << endl;
	long long int m; cin >> m;
	while (cin.fail())
	{
		cin.clear();
		cin.sync();
		cin.ignore();
		cout << "you bad! Invalid input! Resume!" << endl;
		cin >> m;
	}
	cout << "please enter the base(2~16)!" << endl;
	int b; cin >> b;
	while (cin.fail()||b<2||b>16)
	{
		cin.clear();
		cin.sync();
		cin.ignore();
		cout << "you bad! Invalid input! Resume!" << endl;
		cin >> b;
	}
	cout << "Successfully convert!" << endl;
	while (m != 0) {
		num.push(m%b);
		m /= b;
	}
	while (!num.empty()) {
		char c = num.top() - 10 + 'A';
//		cout <<( num.top() > 9 ?c:num.top());
		if (num.top() > 9)
			cout << c;
		else
			cout << num.top();
		num.pop();
	}
	cout << endl;
	return;
}