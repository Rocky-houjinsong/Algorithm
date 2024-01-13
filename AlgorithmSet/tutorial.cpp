// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>


#include "randomList/generateRandomArray.h"
#include "randomList/src/generateRandomArray.cpp"


int main(int argc, char* argv[])
{


    // 测试排序算法辅助函数
    int N = 20000;
    int* arr = SortTestHelper::generateRandomArray(N, 0, 100000);
    SortTestHelper::selectionSort(arr, N);
    SortTestHelper::printArray(arr, N);
    delete[] arr;

    return 0;
}


