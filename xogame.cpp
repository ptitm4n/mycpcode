#include<iostream>

using namespace std;
#define MAX_ROW 100000
#define MAX_COL 100
#define base 311
#define hashsize 300000

int sh, sc, ntc = 0, curM, curMO, maxidx, tongsoO;
struct Node{
    char data[100];
    int soluong;
    int soO;
    int vitriX[MAX_COL];
    int soluongx;
    int intc;
    Node()
    {
        intc = 0;
    }
};
Node hashtbl[hashsize];
Node* luudcmax[MAX_COL];
int haichuoituongduong(char* xaugoc,const char* xausosanh)
{
    for(int i = 0; i < sc; i ++)
    if(xaugoc[i] != xausosanh[i])
    return 0;
    return 1;
}
void themVaoHashTable(int hashValue, const char* xau) 
{
    int tam = hashValue;
    while(hashtbl[tam].intc == ntc 
    && !haichuoituongduong(hashtbl[tam].data, xau))
    {
        tam ++;
    }

    if(hashtbl[tam].intc < ntc)
    {
        hashtbl[tam].intc = ntc;
        hashtbl[tam].soluong = 1;
        hashtbl[tam].soluongx = 0;
        hashtbl[tam].soO = 0;
        for(int i = 0; i < sc; i ++)
        {
            hashtbl[tam].data[i] = xau[i];
            if(xau[i] == 'X')
            hashtbl[tam].vitriX[hashtbl[tam].soluongx ++] = i;
        }
    }else{
        hashtbl[tam].soluong ++; 
        if(hashtbl[tam].soluong > curM)
        {
            curM = hashtbl[tam].soluong;
            maxidx = 0;
            luudcmax[maxidx ++] = &hashtbl[tam];
        }else if(hashtbl[tam].soluong == curM)
        {
            luudcmax[maxidx ++] = &hashtbl[tam];
        }
    }
}
void xuly(int R, int C, int K, const char game[MAX_ROW][MAX_COL], int* maxRow, int* maxO)
{
    ntc ++;
    curM = 0;
    curMO = 0;
    maxidx = 0;
    sh = R;
    sc = C;
    tongsoO = 0;
    int soluongO[MAX_COL] = {0};
    for(int i = 0; i < R; i ++)
    {
        int sox = 0;
        int hashValue = 0;
        for(int j = 0; j < C; j ++)
        {
            hashValue = hashValue * base + game[i][j];
            hashValue %= hashsize; 

            if(game[i][j] == 'X')
            sox ++;
            else
            {
                soluongO[j] ++;
                tongsoO ++;
            }

            if(K >= sox && (K - sox) & 1 == 0)
            {
                themVaoHashTable(hashValue, game[i]);
            }
        }
    }

    for(int i = 0; i < maxidx; i ++)
    {
        int soOtangthem = 0;
        for(int j = 0; j < luudcmax[i] ->soluongx; j ++)
        {
            soOtangthem += - soluongO[luudcmax[i] -> vitriX[j]] 
            + sh - soluongO[luudcmax[i] -> vitriX[j]];
        }
        luudcmax[i] -> soO = tongsoO + soOtangthem;
        if(luudcmax[i] -> soO > curMO)
        curMO = luudcmax[i] -> soO;
    }
}

int main()
{
    cout << " hello world" << endl;
}