#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;
long long n;
long long arr[100009];
long long out25,out50;
bool ans=1;
//set <long long> s;
//set<long long>::iterator it;

int main()
{
    scanf("%lld",&n);
    for (long long i=0;i<n;++i){
        scanf("%lld",&arr[i]);
        if (!ans) continue;
        if (arr[i]==25) out25+=25;
        else if (arr[i]==50){
            if (out25-25>=0){
                out25-=25;
                out50+=50;
            }else{
                ans=0;
            }
        }else{
            if (out25-25>=0 && out50-50>=0){
                out25-=25;
                out50-=50;
            }else if (out25-75>=0){
                out25-=75;
            }else{
                ans=0;
            }
        }

    }
    (!ans) ? printf("NO\n"):printf("YES\n");
    //for (it=s.begin(); it!=s.end(); ++it){}
    return 0;
}
