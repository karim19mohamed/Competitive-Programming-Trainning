#include <iostream>
#include <stdio.h>

using namespace std;
long long n,k,ans;

long long cal(long long v){
    long long num=v,w=k;
    while ((v/w)!=0){
        num+=(v/w);
        w*=k;
    }
    return num;
}

long long binary(){
    long long i=1,j=n,m,res;
    long long num=0;
    while (i<=j){
        m=i+(j-i)/2;
        num=cal(m);
        //cout << m << " " <<  num << endl;
        if (n>num) i=m+1;
        else if (n<num){
            j=m-1;
            res=m;
        }else return m;
    }
    return res;
}

int main()
{
    scanf("%lld%lld",&n,&k);
    ans=binary();
    printf("%lld\n",ans);
    return 0;
}
