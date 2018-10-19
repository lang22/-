#include<iostream>
#include<algorithm>
#include<fstream>
#include<time.h>
#include<iomanip>
#include"SortingAlgorithms.h"
using namespace std;
#define MAX 100000
int a[MAX];
int temp[MAX];
clock_t start, ending;
//int* p = data;
void printTime() { //��ӡ����
	cout << "������" << setw(6) << ending - start<< "ms, ";
	cout << setw(10) << cmpt << "�αȽϣ� " << setw(10) << movt << "���ƶ���" << endl;
	cmpt = 0;
	movt = 0;
}
void initialize(int n) {//��ʼ������������
	for (int i = 0; i < n; i++) {
		srand(i);
		a[i] = rand() % n;
	}
}
void eightSort(int a[],int n) {
	initialize(n);
	cout << "ֱ�Ӳ�������";
	start = clock();
	StraightInsertionSort(a, n);
	ending = clock();
	printTime();
	//	for (int i : a)
	//		cout << i << " ";
	initialize(n);
	cout << "�۰��������";
	start = clock();
	BinaryInsertionSort(a, n);
	ending = clock();
	printTime();
	initialize(n);
	cout << "ð������    ";
	start = clock();
	BubbleSort(a, n);
	ending = clock();
	printTime();
	initialize(n);
	cout << "��������    ";
	start = clock();
	QuickSort(a, n, 0, n - 1);
	ending = clock();
	printTime();
	initialize(n);
	cout << "ϣ������    "; 
	start = clock();
	ShellSort(a, n);
	ending = clock();
	printTime();
	initialize(n);
	cout << "��ѡ������";
	start = clock();
	SimpleSelectSort(a, n);
	ending = clock();
	printTime();
	initialize(n);
	cout << "������      ";
	start = clock();
	HeapSort(a, n);
	ending = clock();
	printTime();
	initialize(n);
	cout << "�鲢����    ";
	start = clock();
	MergeSort(a, 0, n - 1, temp);
	ending = clock();
	printTime();
}
int main() {
	cout << "***************************************" << endl;
	cout << "100���������" << endl;
	eightSort(a, 100);
	cout << "***************************************" << endl;
	cout << "100000���������" << endl;
	eightSort(a, MAX);
	return 0;
}
