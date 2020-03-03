#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
char x[1001];

int main()
{
    scanf("%s",&x);
    if (x[0]>90){
        x[0]-=32;
    }
    printf("%s\n",x);
    return 0;
}
