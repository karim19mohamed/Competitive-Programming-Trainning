#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;
int n,m,max_int,num_max_int;
int a[59],b[59];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for (int i=0;i<m;++i){
        scanf("%d",&b[i]);
        for (int j=0;j<n;++j){
            //cout << b[i] << "  " << b[i]/a[j] << endl;
            if(b[i]%a[j]==0){

                if (max_int<b[i]/a[j]){
                    max_int=b[i]/a[j];
                    num_max_int=1;
                }else if (max_int==b[i]/a[j]){
                    ++num_max_int;
                }
            }
        }
    }
    printf("%d\n",num_max_int);
    return 0;
}
