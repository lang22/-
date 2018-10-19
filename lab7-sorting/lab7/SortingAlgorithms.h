#pragma once
#include<iostream>
using namespace std;
long long cmpt, movt;
//��ӡ����
void print(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
//ֱ�Ӳ�������
void StraightInsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {   //����i��Ԫ�ش���i-1Ԫ�أ�ֱ�Ӳ��롣С�ڵĻ����ƶ����������  
			int j = i - 1;
			int x = a[i];        //����Ϊ�ڱ������洢������Ԫ��  
			a[i] = a[i - 1];     //�Ⱥ���һ��Ԫ�� 
			movt++;
			while (x < a[j] && j>0) {   //�����������Ĳ���λ��
				cmpt++;
				a[j + 1] = a[j];
				movt++;
				j--;             //Ԫ�غ���  
			}
			cmpt++;
			a[j + 1] = x;        //���뵽��ȷλ��  
			movt+=2;
		}
		cmpt ++;
	}
	return ;
}
//�۰��������
void BinaryInsertionSort(int a[], int n) {
	int low, mid, high;
	for (int i = 1; i < n; i++) {
		cmpt++;
		if (a[i] < a[i - 1]) {   //����i��Ԫ�ش���i-1Ԫ�أ�ֱ�Ӳ��롣С�ڵĻ����ƶ����������  
			int x = a[i];	//����Ϊ�ڱ������洢������Ԫ��  
			a[i] = a[i - 1]; //�Ⱥ���һ��Ԫ�� 
			movt += 2;
			low = 0;
			high = i - 1;
			while (low <= high) {   //���ֲ����������Ĳ���λ��  
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
			a[low + 1] = x;        //���뵽��ȷλ�� 
			movt++;
		}
	}
	//	print(a, n);
	return ;
}
//ð������
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
//��������
int QuickSort(int a[], int n, int left, int right) {
	int i, j, pivot, times = 0;
	if (left >= right) {
		//		print(a, n);
		return times;
	}
	i = left;
	j = right;
	pivot = a[left];//�������Ԫ����Ϊ��Ŧ
	cmpt++;
	while (i != j) {
		while (a[j] >= pivot&&i < j)//���ұ߿�ʼ��
			j--, cmpt++;
		while (a[i] <= pivot&&i < j)
			i++, cmpt++;
		swap(a[i], a[j]);
		movt += 3;
	}
	swap(a[left], a[i]);//����ŦԪ�ع�λ�����С�������ұߴ�����
	movt += 3;
	QuickSort(a, n, left, i - 1);
	QuickSort(a, n, i + 1, right);
}
//ϣ������
void ShellSort(int a[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = 0; i < gap; i++) {
			for (int j = i + gap; j < n; j += gap) {
				cmpt++;
				if (a[j - gap] > a[j]) {
					int ow = a[j];//�����ڱ����洢����Ԫ��
					movt++;
					int t = j - gap;
					while (t >= 0&&a[t] > ow) {//�ҵ����������е�һ�����ڱ�С��
						a[t + gap] = a[t];
						t -= gap;
						cmpt++;
						movt++;
					}
					a[t + gap] = ow;//����Ԫ�ز��뵽��ȷλ��
					cmpt++;
				}
			}
		}
	}
	return ;
}
//��ȡ������СԪ���±�
int SelectMin(int a[], int n, int start) {
	int temp = start;
	for (int i = start + 1; i < n; i++) {
		cmpt++;
		if (a[temp] > a[i])
			temp = i;
	}
	return temp;
}
//��ѡ������
void SimpleSelectSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min = SelectMin(a, n, i);
		swap(a[i], a[min]);
		movt += 3;
		}
}
//�����󶥶�
void HeapAdjust(int a[], int s,int m) {
	//��֪a[s..m]�г���a[s]�������󶥶�
	//��������a[s..m]����Ϊ�󶥶�,��a[s]һ������³�
	int temp = a[s];
	movt++;
	for (int i = 2 * s; i <= m; i *= 2) {//��key����ӽڵ����²���
		cmpt+=2;
		if (a[i] < a[i + 1] && i < m) {
			i++;
		}
		if (a[i] <= temp) break;
		a[s] = a[i];//a[s]��key�Ĵ���ӽڵ��ϸ�
		s = i;
		movt++;
	}
	a[s] = temp;//��a[s]�Ŀ����ŵ���ȷλ�ã���ʱ��s��
	movt++;
}
//������
void HeapSort(int a[], int n) {
	for (int i = (n-1) / 2; i > 0; i--)
		HeapAdjust(a, i, n); //��ʼ�������ɴ󶥶�
	for (int i = n-1; i>0; i--) {
		swap(a[0], a[i]);//�Ѷ�Ԫ�������һ��Ԫ�ؽ���
		movt += 3;
		HeapAdjust(a, 0, i - 1);//��ǰi�������ɴ󶥶�
	}
//	print(a,n);
}
//����temp���飬�ϲ�������������
void MergeArray(int a[], int temp[],int first,int mid,int last) {
	int i = first, m = mid;		//��������
	int j = mid + 1, n = last;  //�Ұ������
	int k = 0;//temp����ļ�����
	while (i <= m&&j <= n) {
		cmpt++, movt++;
		if (a[i] <= a[j])//�ȶ�
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	//ȷ��������������������
	while (i <= m)
		temp[k++] = a[i++], movt++;
	while (j <= n)
		temp[k++] = a[j++], movt++;
	for (i = 0; i < k; i++)
		a[first + i] = temp[i], movt++;//���ϲ���temp��������п�����a������
}
//�鲢����
void MergeSort(int a[], int first,int last,int temp[]) {
	int mid = (first + last) / 2;
	if (first < last) {		
		MergeSort(a, first, mid, temp);//�ݹ�����
		MergeSort(a, mid + 1, last, temp);//�ݹ��Ұ��
		MergeArray(a, temp, first, mid, last);//�ϲ���������
	}
//	if (mid == 4999)
//		print(a, last);
}