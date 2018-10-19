#pragma once
#include<iostream>
using namespace std;
long long cmpt, movt;
//打印数组
void print(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
//直接插入排序
void StraightInsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {   //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入  
			int j = i - 1;
			int x = a[i];        //复制为哨兵，即存储待排序元素  
			a[i] = a[i - 1];     //先后移一个元素 
			movt++;
			while (x < a[j] && j>0) {   //查找在有序表的插入位置
				cmpt++;
				a[j + 1] = a[j];
				movt++;
				j--;             //元素后移  
			}
			cmpt++;
			a[j + 1] = x;        //插入到正确位置  
			movt+=2;
		}
		cmpt ++;
	}
	return ;
}
//折半插入排序
void BinaryInsertionSort(int a[], int n) {
	int low, mid, high;
	for (int i = 1; i < n; i++) {
		cmpt++;
		if (a[i] < a[i - 1]) {   //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入  
			int x = a[i];	//复制为哨兵，即存储待排序元素  
			a[i] = a[i - 1]; //先后移一个元素 
			movt += 2;
			low = 0;
			high = i - 1;
			while (low <= high) {   //二分查找在有序表的插入位置  
				mid = (low + high) / 2;
				cmpt++;
				if (a[mid] < x)
					low = mid + 1;
				else
					high = mid - 1;
			}
			for (int j = i - 1; j > low; j--) {
				a[j + 1] = a[j];
				movt++;
			}				
			a[low + 1] = x;        //插入到正确位置 
			movt++;
		}
	}
	//	print(a, n);
	return ;
}
//冒泡排序
void BubbleSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			cmpt++;
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
				movt += 3;
			}				
		}
	}
	//	print(a, n);
	return ;
}
//快速排序
int QuickSort(int a[], int n, int left, int right) {
	int i, j, pivot, times = 0;
	if (left >= right) {
		//		print(a, n);
		return times;
	}
	i = left;
	j = right;
	pivot = a[left];//将最左边元素作为枢纽
	cmpt++;
	while (i != j) {
		while (a[j] >= pivot&&i < j)//从右边开始找
			j--, cmpt++;
		while (a[i] <= pivot&&i < j)
			i++, cmpt++;
		swap(a[i], a[j]);
		movt += 3;
	}
	swap(a[left], a[i]);//将枢纽元素归位，左边小于它，右边大于它
	movt += 3;
	QuickSort(a, n, left, i - 1);
	QuickSort(a, n, i + 1, right);
}
//希尔排序
void ShellSort(int a[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = 0; i < gap; i++) {
			for (int j = i + gap; j < n; j += gap) {
				cmpt++;
				if (a[j - gap] > a[j]) {
					int ow = a[j];//设置哨兵，存储待排元素
					movt++;
					int t = j - gap;
					while (t >= 0&&a[t] > ow) {//找到有序序列中第一个比哨兵小的
						a[t + gap] = a[t];
						t -= gap;
						cmpt++;
						movt++;
					}
					a[t + gap] = ow;//待排元素插入到正确位置
					cmpt++;
				}
			}
		}
	}
	return ;
}
//获取数组最小元素下标
int SelectMin(int a[], int n, int start) {
	int temp = start;
	for (int i = start + 1; i < n; i++) {
		cmpt++;
		if (a[temp] > a[i])
			temp = i;
	}
	return temp;
}
//简单选择排序
void SimpleSelectSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min = SelectMin(a, n, i);
		swap(a[i], a[min]);
		movt += 3;
		}
}
//调整大顶堆
void HeapAdjust(int a[], int s,int m) {
	//已知a[s..m]中除了a[s]外均满足大顶堆
	//本函数将a[s..m]调整为大顶堆,将a[s]一层层向下沉
	int temp = a[s];
	movt++;
	for (int i = 2 * s; i <= m; i *= 2) {//沿key大的子节点向下查找
		cmpt+=2;
		if (a[i] < a[i + 1] && i < m) {
			i++;
		}
		if (a[i] <= temp) break;
		a[s] = a[i];//a[s]的key的大的子节点上浮
		s = i;
		movt++;
	}
	a[s] = temp;//将a[s]的拷贝放到正确位置（此时的s）
	movt++;
}
//堆排序
void HeapSort(int a[], int n) {
	for (int i = (n-1) / 2; i > 0; i--)
		HeapAdjust(a, i, n); //初始化，建成大顶堆
	for (int i = n-1; i>0; i--) {
		swap(a[0], a[i]);//堆顶元素与最后一个元素交换
		movt += 3;
		HeapAdjust(a, 0, i - 1);//把前i个调整成大顶堆
	}
//	print(a,n);
}
//借助temp数组，合并两个有序数组
void MergeArray(int a[], int temp[],int first,int mid,int last) {
	int i = first, m = mid;		//左半边数组
	int j = mid + 1, n = last;  //右半边数组
	int k = 0;//temp数组的计数器
	while (i <= m&&j <= n) {
		cmpt++, movt++;
		if (a[i] <= a[j])//稳定
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	//确保遍历完左右两个数组
	while (i <= m)
		temp[k++] = a[i++], movt++;
	while (j <= n)
		temp[k++] = a[j++], movt++;
	for (i = 0; i < k; i++)
		a[first + i] = temp[i], movt++;//将合并到temp数组的序列拷贝到a数组中
}
//归并排序
void MergeSort(int a[], int first,int last,int temp[]) {
	int mid = (first + last) / 2;
	if (first < last) {		
		MergeSort(a, first, mid, temp);//递归左半边
		MergeSort(a, mid + 1, last, temp);//递归右半边
		MergeArray(a, temp, first, mid, last);//合并左右两边
	}
//	if (mid == 4999)
//		print(a, last);
}