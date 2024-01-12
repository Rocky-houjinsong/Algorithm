// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>


#include "randomList/generateRandomArray.h"


int main(int argc, char* argv[])
{


    // 测试排序算法辅助函数
    int N = 20000;
    int* arr = generateRandomArray(N, 0, 100000);
    selectionSort(arr, N);
    printArray(arr, N);
    delete[] arr;

    return 0;
}


