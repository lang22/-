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
void printTime() { //打印花费
	cout << "花费了" << setw(6) << ending - start<< "ms, ";
	cout << setw(10) << cmpt << "次比较， " << setw(10) << movt << "次移动。" << endl;
	cmpt = 0;
	movt = 0;
}
void initialize(int n) {//初始化或重置数组
	for (int i = 0; i < n; i++) {
		srand(i);
		a[i] = rand() % n;
	}
}
void eightSort(int a[],int n) {
	initialize(n);
	cout << "直接插入排序";
	start = clock();
	StraightInsertionSort(a, n);
	ending = clock();
	printTime();
	//	for (int i : a)
	//		cout << i << " ";
	initialize(n);
	cout << "折半插入排序";
	start = clock();
	BinaryInsertionSort(a, n);
	ending = clock();
	printTime();
	initialize(n);
	cout << "冒泡排序    ";
	start = clock();
	BubbleSort(a, n);
	ending = clock();
	printTime();
	initialize(n);
	cout << "快速排序    ";
	start = clock();
	QuickSort(a, n, 0, n - 1);
	ending = clock();
	printTime();
	initialize(n);
	cout << "希尔排序    "; 
	start = clock();
	ShellSort(a, n);
	ending = clock();
	printTime();
	initialize(n);
	cout << "简单选择排序";
	start = clock();
	SimpleSelectSort(a, n);
	ending = clock();
	printTime();
	initialize(n);
	cout << "堆排序      ";
	start = clock();
	HeapSort(a, n);
	ending = clock();
	printTime();
	initialize(n);
	cout << "归并排序    ";
	start = clock();
	MergeSort(a, 0, n - 1, temp);
	ending = clock();
	printTime();
}
int main() {
	cout << "***************************************" << endl;
	cout << "100个随机数：" << endl;
	eightSort(a, 100);
	cout << "***************************************" << endl;
	cout << "100000个随机数：" << endl;
	eightSort(a, MAX);
	return 0;
}
