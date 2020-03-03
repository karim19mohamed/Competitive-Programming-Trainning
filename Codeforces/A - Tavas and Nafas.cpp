#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int n;
string arr[109];

int main()
{
    scanf("%d",&n);
    arr[0]="zero";arr[1]="one";arr[2]="two";arr[3]="three";arr[4]="four";arr[5]="five";arr[6]="six";arr[7]="seven";
    arr[8]="eight";arr[9]="nine";arr[10]="ten";arr[11]="eleven";arr[12]="twelve";arr[13]="thirteen";arr[14]="fourteen";
    arr[15]="fifteen";arr[16]="sixteen";arr[17]="seventeen";arr[18]="eighteen";arr[19]="nineteen";
    arr[20]="twenty";arr[30]="thirty";arr[40]="forty";arr[50]="fifty";arr[60]="sixty";arr[70]="seventy";
    arr[80]="eighty";arr[90]="ninety";
    if (arr[n].size()==0){
        int a=n%10;
        n/=10;n*=10;
        cout << arr[n] << "-" << arr[a] << endl;
    }else{
        cout << arr[n] << endl;
    }
    return 0;
}