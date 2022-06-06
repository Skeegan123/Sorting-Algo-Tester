#pragma once
#ifndef SORTING_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define SORTING_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int> randArr) {
	int size = randArr.size();
	int temp;
	bool swapped;

	/*for (int k = 0; k < size; k++) {
		cout << randArr[k] << endl;
	}*/

	auto start = high_resolution_clock::now();
	for (int i = 0; i < size; i++) {
		swapped = false;
		for (int j = 0; j < (size - i - 1); j++) {
			if (randArr[j] > randArr[j + 1]) {
				temp = randArr[j];
				randArr[j] = randArr[j + 1];
				randArr[j + 1] = temp;
				swapped = true;
			}
		}
		if (swapped == false) {
			break;
		}
	}
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	for (int g = 0; g < size; g++) {
		if (randArr[g] != g + 1) {
			cout << "SORT FAILED" << endl;
			exit(1);
		}
	}

	cout << "SORT COMPLETED SUCCESSFULLY" << endl;

	cout << endl;

	cout << "Time to sort: " << duration.count() << " microseconds" << endl;

	/*for (int g = 0; g < size; g++) {
		cout << randArr[g] << endl;
	}*/
}

void selectionSort(vector<int> randArr) {
	int size = randArr.size();
	int temp;
	int minIndex;

	auto start = high_resolution_clock::now();
	for (int i = 0; i < size; i++) {
		minIndex = i;
		for (int j = i; j < size; j++) {
			if (randArr[j] < randArr[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			temp = randArr[i];
			randArr[i] = randArr[minIndex];
			randArr[minIndex] = temp;
		}
	}
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	for (int g = 0; g < size; g++) {
		if (randArr[g] != g + 1) {
			cout << "SORT FAILED" << endl;
			exit(1);
		}
	}

	cout << "SORT COMPLETED SUCCESSFULLY" << endl;

	cout << endl;

	cout << "Time to sort: " << duration.count() << " microseconds" << endl;
}

vector<int> merge(vector<int> left, vector<int> right) {
	if (left.empty()) {
		return left;
	}
	if (right.empty()) {
		return right;
	}

	vector<int> result;
	int leftIndex = 0;
	int rightIndex = 0;
	int totalSize = left.size() + right.size();

	while (result.size() < totalSize) {
		if (left[leftIndex] < right[rightIndex]) {
			result.push_back(left[leftIndex]);
			leftIndex++;
		}
		else {
			result.push_back(right[rightIndex]);
			rightIndex++;
		}
		if (leftIndex == left.size()) {
			result.insert(result.end(), right.begin() + rightIndex, right.end());
			break;
		}
		else if (rightIndex == right.size()) {
			result.insert(result.end(), left.begin() + leftIndex, left.end());
			break;
		}
	}
	return result;
}

void mergeSort(vector<int>& randArr) {
	int size = randArr.size();
	vector<int> merged;

	if (size < 2) {
		return;
	}

	int mid = size / 2;

	vector<int> leftArr(randArr.begin(), randArr.begin() + mid);
	vector<int> rightArr(randArr.begin() + mid, randArr.end());

	mergeSort(leftArr);
	mergeSort(rightArr);

	merged = merge(leftArr, rightArr);

	randArr = merged;

	return;
}

void mergeSortCaller(vector<int> randArr) {
	int size = randArr.size();

	/*for (int k = 0; k < size; k++) {
		cout << randArr[k] << endl;
	}*/

	auto start = high_resolution_clock::now();
	mergeSort(randArr);
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	/*for (int l = 0; l < size; l++) {
		cout << merged[l] << endl;
	}*/

	for (int g = 0; g < size; g++) {
		if (randArr[g] != g + 1) {
			cout << "SORT FAILED" << endl;
			exit(1);
		}
	}

	cout << "SORT COMPLETED SUCCESSFULLY" << endl;

	cout << endl;

	cout << "Time to sort: " << duration.count() << " microseconds" << endl;
}

int partition(vector<int>& randArr, int start, int end) {
	int pivot = randArr[start];
	int count = 0;
	int temp;

	for (int i = start + 1; i <= end; i++) {
		if (randArr[i] <= pivot) {
			count++;
		}
	}

	int pivotIndex = start + count;
	temp = randArr[pivotIndex];
	randArr[pivotIndex] = randArr[start];
	randArr[start] = temp;

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {
		while (randArr[i] <= pivot) {
			i++;
		}
		while (randArr[j] > pivot) {
			j--;
		}
		if (i < pivotIndex && j > pivotIndex) {
			temp = randArr[i];
			randArr[i] = randArr[j];
			randArr[j] = temp;
			i++;
			j--;
		}
	}
	return pivotIndex;
}

void quickSort(vector<int>& randArr, int start, int end) {
	if (start >= end) {
		return;
	}

	int p = partition(randArr, start, end);
	quickSort(randArr, start, p - 1);
	quickSort(randArr, p + 1, end);
}

void quickSortCaller(vector<int> randArr) {
	int size = randArr.size();

	/*for (int k = 0; k < size; k++) {
		cout << randArr[k] << endl;
	}*/

	auto start = high_resolution_clock::now();
	quickSort(randArr, 0, size - 1);
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	/*for (int l = 0; l < size; l++) {
		cout << randArr[l] << endl;
	}*/

	for (int g = 0; g < size; g++) {
		if (randArr[g] != g + 1) {
			cout << "SORT FAILED" << endl;
			exit(1);
		}
	}

	cout << "SORT COMPLETED SUCCESSFULLY" << endl;

	cout << endl;

	cout << "Time to sort: " << duration.count() << " microseconds" << endl;
}

void builtInSort(vector<int> randArr) {
	int size = randArr.size();
	int temp;
	bool swapped;

	/*for (int k = 0; k < size; k++) {
		cout << randArr[k] << endl;
	}*/

	auto start = high_resolution_clock::now();
	sort(randArr.begin(), randArr.end());
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	for (int g = 0; g < size; g++) {
		if (randArr[g] != g + 1) {
			cout << "SORT FAILED" << endl;
			exit(1);
		}
	}

	cout << "SORT COMPLETED SUCCESSFULLY" << endl;

	cout << endl;

	cout << "Time to sort: " << duration.count() << " microseconds" << endl;

	/*for (int g = 0; g < size; g++) {
		cout << randArr[g] << endl;
	}*/
}

#endif