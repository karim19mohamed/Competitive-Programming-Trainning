#include <iostream>
#include <stdio.h>
#include <map>
#include <queue>
#include <cstring>

using namespace std;
int n,t;
map<long long,long long> dis;
queue <long long> q;
long long ans;

int sumdigi (long long num){
    int sum=0;
    while (num!=0){
        sum+=num%10;
        num/=10;
    }
    return sum;
}

long long bfs(long long x){
    dis[x]=1;
    q.push(x);
    long long num;
    while (!q.empty()){
        long long u=q.front();
        q.pop();
        for (long long i=0;i<10;i++){
            long long ten=1;
            for (int j=1;j<dis[u];j++) ten*=10;
            num=u+i*ten;
            if (sumdigi(num)>n) continue;
            if (dis[num]==0 && num%n==0){
                cout << num << endl;
                if (num>n){
                    if (sumdigi(num)==n){
                        return num;
                    }
                }
                q.push(num);
                dis[num]=dis[u]+1;
            }
            //int z;cin>>z;
        }
        if (q.empty()){
            q.push(0);
            dis[0]++;
        }
    }
}


int main()
{
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        ans=bfs(0);
        printf("%lld\n",ans);
    }
    return 0;
}
