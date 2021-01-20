#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char s[1000] = "nguyen   tuan thanh";
    char* token = strtok(s,  " ");
    while(token != NULL)
    {
        cout << token << endl;
        token = strtok(NULL, " ");
    }
}