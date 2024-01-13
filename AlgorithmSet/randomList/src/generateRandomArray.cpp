#pragma once

#ifndef randomList_H   // 确保头文件只被编译一次  防止头文件的重复包含
#define randomList_H

#include <iostream>
#include <ctime>
#include <cassert>

#include <randomList/generateRandomArray.h>

using namespace std;

namespace SortTestHelper {

	// 生成 有 n个元素的 随机数组,  每个数组的随机范围是 (rangeL, rangelR)
	int* generateRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeL <= rangeR);
		int* arr = new int[n];

		srand(time(NULL));

		for (int i = 0; i < n; i++)
		{
			//Core Code : 生成一个位于 rangeL 和 rangeR 之间的随机整数，每个整数的生成概率相等
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}

		return arr;   //返回数组 
	}

	//打印arr数组的所有内容
	template<typename T>
	void  printArray(T arr[], int n) {

		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;

		return;
	}


	template<typename T>
	void selectionSort(T arr[], int n) {

		for (int i = 0; i < n; i++) {

			int minIndex = i;
			for (int j = i + 1; j < n; j++)
				if (arr[j] < arr[minIndex])
					minIndex = j;

			swap(arr[i], arr[minIndex]);
		}
	}

};

#endif // !randomList_H
