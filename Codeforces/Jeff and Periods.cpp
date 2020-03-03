#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;
long long n;
long long arr[100009];
long long cnt[100009][4],t;
set <long long> s;
set<long long>::iterator it;

int main()
{
    scanf("%lld",&n);
    for (long long i=0;i<n;++i){
        scanf("%lld",&arr[i]);
        s.insert(arr[i]);
        if (cnt[arr[i]][0]==0){
            ++t;
            cnt[arr[i]][0]=i+1;
            //cout << cnt[arr[i]][0] << "  " << arr[i] << " " << t << endl;
        }else if (cnt[arr[i]][1]==0){
            cnt[arr[i]][1]=i+1;
            cnt[arr[i]][2]=cnt[arr[i]][1]-cnt[arr[i]][0];
        }else if (cnt[arr[i]][2]!=i+1-cnt[arr[i]][1] && !cnt[arr[i]][3]){
            cnt[arr[i]][3]=1;
            --t;
        }else{
            cnt[arr[i]][0]=cnt[arr[i]][1];
            cnt[arr[i]][1]=i+1;
        }
    }
    printf("%lld\n",t);
    for (it=s.begin(); it!=s.end(); ++it){
        if (!cnt[*it][3]) printf("%lld %lld\n",*it,cnt[*it][2]);
    }
    return 0;
}
