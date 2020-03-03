#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;
int k,n=1;
int a[600][600];
string s,b;

int main()
{
    scanf("%d",&k);
    a[0][0]=1;
    for (int w=0;w<k;w++){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                a[i+n][j]=a[i][j];
                a[i][j+n]=a[i][j];
                a[i+n][j+n]=-a[i][j];
            }
        }
        n*=2;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (a[i][j]==1) printf("+");
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}