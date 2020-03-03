#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <queue>

using namespace std;
string arr[10009];
long long n,t,coach,num;
string sc; long long rel;
priority_queue <pair<long long,string> > q;

int main()
{
    freopen("coaches.in", "r", stdin);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        getline(std::cin,arr[0]);
        for (int i=0;i<n;i++){
            getline(std::cin,arr[i]);
        }
        for (int i=0;i<n;i++){
            if (arr[i][0]<'a' && arr[i]!="-1"){
                coach++;
                if (sc.size()!=0){
                    q.push({rel,sc});
                }
                sc=arr[i];
                rel=0;
                continue;
            }else if(arr[i]!="-1"){
                rel++;
            }
            bool re=0;
            num=coach;
            for (int j=i+1;j<n;j++){
                if (arr[j][0]<'a'){
                    num++;
                }
                if (arr[i]==arr[j]){
                    if (coach==num){
                        arr[j]="-1";
                    }else{
                        re=1;
                        arr[j]="-1";
                    }
                }
            }
            if (re){
                arr[i]="-1";
                rel--;
            }
        }
        if (sc.size()!=0){
            q.push({rel,sc});
        }
        while (!q.empty()){
            int x=q.top().first;
            string y=q.top().second;
            q.pop();
            cout << y << " " << x << endl;
        }
    }
    return 0;
}
