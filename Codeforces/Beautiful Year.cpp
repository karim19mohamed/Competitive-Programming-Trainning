#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int y,x1,x2,x3,x4;

int main()
{
    scanf("%i",&y);
    while(1){
        ++y;
        x1=y/1000;
        x2=(y-x1*1000)/100;
        x3=(y-x1*1000-x2*100)/10;
        x4=y-x1*1000-x2*100-x3*10;
        if (x1!=x2 && x1!=x3 && x1!=x4 && x2!=x3 && x2!=x4 && x3!=x4){
            printf("%i\n",y);
            break;
        }
    }
    return 0;
}
