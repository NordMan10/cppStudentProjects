#include <iostream>
#include <stack>
#include <time.h>
#include <chrono>
#include "main.h"

using namespace std;

void QuickSort(int* array, int left, int right)
{
	if (left == right) return;
	auto pivot = *(array + right);
	auto separatingIndex = left;
	for (auto i = left; i <= right - 1; i++)
		if (*(array + i) <= pivot)
		{
			auto temp = *(array + i);
			*(array + i) = *(array + separatingIndex);
			*(array + separatingIndex) = temp;
			separatingIndex++;
		}
	auto temp = *(array + separatingIndex);
	*(array + separatingIndex) = *(array + right);
	*(array + right) = temp;
	if (separatingIndex > left) QuickSort(array, left, separatingIndex - 1);
	if (separatingIndex < right) QuickSort(array, separatingIndex + 1, right);
}

void NotRecursiveQuickSort(int* array, int left, int right)
{
	auto s = stack<int>();
	s.push(right);
	s.push(left);
	while (!s.empty())
	{
		left = s.top();
		s.pop();
		right = s.top();
		s.pop();

		if (left == right) continue;
		auto pivot = *(array + right);
		auto separatingIndex = left;
		for (auto i = left; i <= right - 1; i++)
		{
			if (*(array + i) <= pivot)
			{
				auto temp = *(array + i);
				*(array + i) = *(array + separatingIndex);
				*(array + separatingIndex) = temp;
				separatingIndex++;
			}
		}

		auto temp = *(array + separatingIndex);
		*(array + separatingIndex) = *(array + right);
		*(array + right) = temp;
		
		if (separatingIndex > left)
		{
			s.push(separatingIndex - 1);
			s.push(left);
		}
		if (separatingIndex < right)
		{
			s.push(right);
			s.push(separatingIndex + 1);
		}
		
	}
}

// simple search by enumeration
int SimpleSearch(int value, int* array, int length)
{
	for (auto i = 0; i < length; i++)
	{
		if (*(array + i) == value)
		{
			return *(array + i);
		}
	}
	return -1;
}

int BSearch(int value, int* array, int left, int right)
{
	while (left < right)
	{
		int middle = ((right - left) / 2) + left;
		if (value <= *(array + middle))
			right = middle;
		else left = middle + 1;
	}
	if (*(array + right) == value) return right;
	return -1;
}

int RecursiveBSearch(int value, int* array, int left, int right)
{
	if (left == right)
		if (value == *(array + right)) return right;
		else return -1;
	int middle = ((right - left) / 2) + left;
	if (value <= *(array + middle))
		RecursiveBSearch(value, array, left, middle);
	else RecursiveBSearch(value, array, middle + 1, right);
}

int main()
{
	const int length = 10000;
	int myArray[length]{};
	int leftBorder = -1000;
	int rightBorder = 1000;

	const int length2 = 100;
	int myArray2[length2]{};
	int leftBorder2 = -10;
	int rightBorder2 = 10;

	// значение для поиска а массиве
	int value = -999;

	// arrays initialization 
	for (auto i = 0; i < length; i++)
	{
		*(myArray + i) = leftBorder + rand() % ((rightBorder + 1) - leftBorder);
	}

	for (auto i = 0; i < length2; i++)
	{
		*(myArray2 + i) = leftBorder2 + rand() % ((rightBorder2 + 1) - leftBorder2);
	}
	//

	// output not sorted array
	for (auto i = 0; i < length2 / 2; i++)
	{
		cout << *(myArray2 + i) << endl;
	}
	cout << "=====================================" << endl;

	// поиск в неотсортированном массиве и замер времени для последующего сравнения
	auto start = chrono::high_resolution_clock::now();
	int valueIndexSimple = SimpleSearch(value, myArray, length - 1);
	auto end = chrono::high_resolution_clock::now();

	chrono::duration<float> duration = end - start;

	// бинарная сортировка 
	QuickSort(myArray, 0, length - 1);
	NotRecursiveQuickSort(myArray2, 0, length2 - 1);

	for (auto i = 0; i < length2 / 2; i++)
	{
		cout << *(myArray2 + i) << endl;
	}
	cout << "=====================================" << endl;

	// сравнение поиска в неотсортированном и отсортированном массиве
	cout << "Simple method time: " << duration.count() << endl;

	// бинарный поиск и замер времени 
	start = chrono::high_resolution_clock::now();
	int valueIndexBinary = BSearch(value, myArray, 0, length - 1);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Binary method time: " << duration.count() << endl;

	// рекурсивный бинарный поиск и замер времени 
	start = chrono::high_resolution_clock::now();
	int valueIndexRBinary = RecursiveBSearch(value, myArray, 0, length - 1);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Recursive binary method time: " << duration.count() << endl;

	// вывод результатов поиска
	if (valueIndexSimple == -1)
		cout << "That item not exist in the array!" << endl;
	else
	{
		cout << "SimpleSearch: " << *(myArray + valueIndexSimple) << endl;
		cout << "BSearch: " << *(myArray + valueIndexBinary) << endl;
		cout << "RecursiveBSearch: " << *(myArray + valueIndexRBinary) << endl;
	}

	return 0;
}
