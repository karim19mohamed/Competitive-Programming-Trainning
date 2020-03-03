#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int n;
string a,b;

int main()
{
    cin >> n >> a >> b ;
    if (b=="week"){
        ((n!=6 && n!=5)? printf("52\n"): printf("53\n"));
    }else{
        if (n<=29){
            printf("12\n");
        }else if (n==30){
            printf("11\n");
        }else{
            printf("7\n");
        }
    }
    return 0;
}