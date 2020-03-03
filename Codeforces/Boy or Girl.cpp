#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;
string s;
map<char,bool> arr;
int ans;

int main()
{
    cin >> s;
    for (int i=0;i<s.length();++i){
        if (!arr[s[i]]){
            //cout << s[i] << "  " << arr[s[i]] << endl;
            ++ans;
            arr[s[i]]=1;
        }
    }
    (ans%2)?  printf("IGNORE HIM!\n") : printf("CHAT WITH HER!\n") ;
    return 0;
}

