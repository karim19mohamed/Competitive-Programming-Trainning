#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
string s;
int n;

int main()
{
    cin >> s;
    n=s.size();
    printf("%d\n",(26-n)*(n+1)+n*n);
    return 0;
}
