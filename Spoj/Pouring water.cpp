#include <iostream>
#include <map>
#include <queue>

using namespace std;
queue <pair <int,int> > q;
map <pair <int,int>,int> dis;
//int dis[400][400];
int t,a,b,c,ans1,ans2;
bool f;
void bfs(int x,int y);

int main()
{
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> a >> b >> c;
        bfs(0,0);
        if (f) cout << dis[make_pair(ans1,ans2)]-1 << endl;
        else cout << "-1" << endl;
        while (!q.empty()) q.pop();
        dis.erase(dis.begin(),dis.end());
        ans1=0;
        ans2=0;
        f=0;
    }
    return 0;
}
void bfs(int x,int y){
    q.push(make_pair(x,y));
    dis[make_pair(x,y)]=1;
    while(!q.empty()){
        pair <int,int> u=q.front();
        q.pop();
        //////////////////////////////////
        if (dis[make_pair(a,u.second)]==0){
            q.push(make_pair(a,u.second));
            dis[make_pair(a,u.second)]=dis[u]+1;
        }
        if (dis[make_pair(u.first,b)]==0){
            q.push(make_pair(u.first,b));
            dis[make_pair(u.first,b)]=dis[u]+1;
        }
        //////////////////////////////////
        if (dis[make_pair(0,u.second)]==0){
            q.push(make_pair(0,u.second));
            dis[make_pair(0,u.second)]=dis[u]+1;
        }
        if (dis[make_pair(u.first,0)]==0){
            q.push(make_pair(u.first,0));
            dis[make_pair(u.first,0)]=dis[u]+1;
        }
        //////////////////////////////////
        if (u.first-(b-u.second)>=0 && dis[make_pair(u.first-(b-u.second),b)]==0){
            q.push(make_pair(u.first-(b-u.second),b));
            dis[make_pair(u.first-(b-u.second),b)]=dis[u]+1;
        }
        if (u.second-(a-u.first)>=0 && dis[make_pair(a,u.second-(a-u.first))]==0){
            q.push(make_pair(a,u.second-(a-u.first)));
            dis[make_pair(a,u.second-(a-u.first))]=dis[u]+1;
        }
        //////////////////////////////////
        if (u.first+u.second<=b && dis[make_pair(0,u.first+u.second)]==0){
            q.push(make_pair(0,u.first+u.second));
            dis[make_pair(0,u.first+u.second)]=dis[u]+1;
        }
        if (u.first+u.second<=a && dis[make_pair(u.first+u.second,0)]==0){
            q.push(make_pair(u.first+u.second,0));
            dis[make_pair(u.first+u.second,0)]=dis[u]+1;
        }
        //////////////////////////////////
        if (u.first==c || u.second==c){
            ans1=u.first;
            ans2=u.second;
            f=1;
            break;
        }
    }
}





