#include"Daclaration.h"
#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
string ms, pts;
int cnt, index;
clock_t start, finish;
double cost;

void Input() {
	ifstream cin;
	cin.open("x:\\test1.in");
	cout << "***********************************************************" << endl;
	cout << "Please input the main string." << endl;
	cin >> ms;
	cout << "Please input the pattern string." << endl;
	cin >> pts;
	cout << "***********************************************************" << endl;
//	cout << ms << endl;
}
void Show() {
	cost = (double)(finish - start) / CLOCKS_PER_SEC * 1000;
//	cout << "*************************************************" << endl;
//	cout << ms << endl;
	if (index > 0) {
//		for (int i = 0; i < index; i++)
//			cout << " ";
//		cout << pts << endl;
		cout<<"Cost "<<cost<<" ms and " << cnt << " times of comparison,we found:" << endl;
		cout << "From " << index + 1 << "th position in main string,match succeeds." << endl;
	}
	else
		cout << pts << endl << "After " << cnt << " times of comparison,we found:" << endl << "Match fails" << endl;

	cout << "***********************************************************" << endl;
}
int main() { 
	Input();
	cout << "1.Brute force" << endl;
	start = clock();
	index = Index_BF(ms, pts, cnt);	
	finish = clock();
	Show();
	cnt = 0;
	cout << "2.KMP" << endl;
	start = clock();
	index = Index_KMP(ms, pts, cnt);
	finish = clock();
	Show();
	cnt = 0;
	cout << "3.KMP_PLUS" << endl;
	start = clock();
	index = Index_KMP_PLUS(ms, pts, cnt);
	finish = clock();
	Show();
	while (1);
	return 0;
}