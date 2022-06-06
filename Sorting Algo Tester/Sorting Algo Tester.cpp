#include "Sorting.h"
#include <Python.h>
#include <math.h>
#include <iostream>

int getArrSize(void) {
	int arrSize;
	cout << "Array size (1 - 1000000): ";
	cin >> arrSize;
	cout << endl;

	if (arrSize < 1 || arrSize > 1000000) {
		cout << "Invalid input. Try again." << endl;
		arrSize = getArrSize();
	}

	return arrSize;
}

vector<int> createRandArr(int arrSize) {
	vector<int> randArr;

	for (int i = 0; i < arrSize; i++) {
		randArr.push_back(i + 1);
	}

	random_device myRandomDevice;
	unsigned seed = myRandomDevice();

	shuffle(randArr.begin(), randArr.end(), default_random_engine(seed));

	return randArr;
}

int main(void)
{
	int arrSize, option = 0;
	vector<int> randArr;

	cout << "WELCOME TO THE SORTING ALGORYTHM TESTER!!!" << endl;
	cout << endl;
	cout << "Options:" << endl;
	cout << "Option 1 - Bubble Sort" << endl;
	cout << "Option 2 - Selection Sort" << endl;
	cout << "Option 3 - Merge Sort" << endl;
	cout << "Option 4 - QuickSort" << endl;
	cout << "Option 5 - std::sort()" << endl;
	cout << "Option 6 - Open analysis menu" << endl;
	cout << "-1 to quit" << endl;
	cout << endl;
	cout << "Which option would you like to test? " << endl;

	cin >> option;

	cout << endl;

	switch (option) 
	{
	case 1:
		cout << "YOU CHOSE BUBBLE SORT!" << endl;
		cout << "Description: " << endl;
		cout << "\tBubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent \n\telements if they are in the wrong order. This algorithm is not suitable for large data sets \n\tas its average and worst case time complexity is quite high. \n\t-GeeksforGeeks" << endl;
		cout << "Time Complexity: " << endl;
		cout << "\tBest - O(n)" << endl;
		cout << "\tAverage - O(n^2)" << endl;
		cout << "\tWorst - O(n^2)" << endl;
		cout << endl;
		arrSize = getArrSize();
		randArr = createRandArr(arrSize);
		bubbleSort(randArr);
		break;
	case 2:
		cout << "YOU CHOSE SELECTION SORT!" << endl;
		cout << "Description: " << endl;
		cout << "\tThe selection sort algorithm sorts an array by repeatedly finding the minimum element \n\t(considering ascending order) from unsorted part and putting it at the beginning. \n\t-GeeksforGeeks" << endl;
		cout << "Time Complexity: " << endl;
		cout << "\tBest - O(n)" << endl;
		cout << "\tAverage - O(n^2)" << endl;
		cout << "\tWorst - O(n^2)" << endl;
		cout << endl;
		arrSize = getArrSize();
		randArr = createRandArr(arrSize);
		selectionSort(randArr);
		break;
	case 3:
		cout << "YOU CHOSE MERGE SORT!" << endl;
		cout << "Description: " << endl;
		cout << "\tLike QuickSort, Merge Sort is a Divide and Conquer algorithm. It divides the \n\tinput array into two halves, calls itself for the two halves, and then it \n\tmerges the two sorted halves.  \n\t-GeeksforGeeks" << endl;
		cout << "Time Complexity: " << endl;
		cout << "\tBest - O(n*log(n))" << endl;
		cout << "\tAverage - O(n*log(n))" << endl;
		cout << "\tWorst - O(n*log(n))" << endl;
		cout << endl;
		arrSize = getArrSize();
		randArr = createRandArr(arrSize);
		mergeSortCaller(randArr);
		break;
	case 4:
		cout << "YOU CHOSE QUICKSORT!" << endl;
		cout << "Description: " << endl;
		cout << "\tLike Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element \n\tas pivot and partitions the given array around the picked pivot. There are many \n\tdifferent versions of quickSort that pick pivot in different ways. \n\t-GeeksforGeeks" << endl;
		cout << "Time Complexity: " << endl;
		cout << "\tBest - O(n*log(n))" << endl;
		cout << "\tAverage - O(n*log(n))" << endl;
		cout << "\tWorst - O(n^2)" << endl;
		cout << endl;
		arrSize = getArrSize();
		randArr = createRandArr(arrSize);
		quickSortCaller(randArr);
		break;
	case 5:
		cout << "YOU CHOSE std::sort()" << endl;
		cout << "Description: " << endl;
		cout << "\tThis function internally uses IntroSort. In more details it is implemented using hybrid of \n\tQuickSort, HeapSort and InsertionSort.By default, it uses QuickSort but if QuickSort is \n\tdoing unfair partitioning and taking more than N*logN time, it switches to HeapSort and \n\twhen the array size becomes really small, it switches to InsertionSort. \n\t-GeeksforGeeks" << endl;
		cout << "Time Complexity: " << endl;
		cout << "\tBest - O(n*log(n))" << endl;
		cout << "\tAverage - O(n*log(n))" << endl;
		cout << "\tWorst - O(n^2)" << endl;
		cout << endl;
		arrSize = getArrSize();
		randArr = createRandArr(arrSize);
		builtInSort(randArr);
		break;
	case -1:
		exit(0);
	default:
		system("CLS");
		cout << "Invalid option... Try again" << endl;
		cout << endl;
		main();
		break;
	}

	return 0;
}