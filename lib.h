#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define loop(i, a, b) for(int i = a; i <= b; i ++)
struct numberGenerator{
    numberGenerator()
    {
        srand(time(0));
    }

    int generateANumberInRange(int start, int end)
    {
        return start + rand() % (end - start + 1); 
    }

    int* generateAnArrayInRange(int start, int end,int startidx,int n)
    {
        int* arr = new int[n + 1];
        loop(i, startidx, n - 1 + startidx)
        arr[i] = generateANumberInRange(start, end);
        return arr;
    }
};