#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
string s;

int main()
{
    cin >> s;
    int i=0;
    while (i<s.length()){
        if (s[i]=='.'){
            printf("0");
            ++i;
        }else if(s[i]=='-'){
            if (s[i+1]=='.'){
                printf("1");
            }else{
                printf("2");
            }
            i+=2;
        }
    }
    printf("\n");
    return 0;
}
