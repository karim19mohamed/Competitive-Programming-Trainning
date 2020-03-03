#include <iostream>
#include <stdio.h>

using namespace std;
string s;

int main()
{
    cin >> s;
    if (s[s.size()-1]=='0'){
        printf("2\n");
    }else{
        printf("1\n%c\n",s[s.size()-1]);
    }
    return 0;
}
