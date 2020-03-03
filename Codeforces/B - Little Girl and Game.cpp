#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
string s;
int arr[30],odd;

int main()
{
    cin >> s;
    for (int i=0;i<s.size();++i) arr[s[i]-'a']++;
    for (int i=0;i<30;++i) if (arr[i]%2) odd++;
    if (odd==0 || odd==1 || odd%2) printf("First\n");
    else printf("Second\n");
    return 0;
}