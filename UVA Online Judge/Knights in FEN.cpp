#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;
int t;
string s1,w;
int arr[5][5];
int res[5][5]={ {1,1,1,1,1},{0,1,1,1,1},{0,0,-1,1,1},{0,0,0,0,1},{0,0,0,0,0} };
bool wrong[5][5];
queue <pair <int,int> > q;
int dis[10][10];
int ans;
void bfs (int a,int b,int v);

int main()
{
    cin >> t;
    for (int k=0;k<t;k++){
        getline (std::cin,w);
        for (int i=0;i<5;i++){
            getline (std::cin,s1);
            for (int j=0;j<5;j++){
                if (s1[j]=='1') arr[i][j]=1;
                else if (s1[j]=='0') arr[i][j]=0;
                else arr[i][j]=-1;
                if (arr[i][j]!=res[i][j]) wrong[i][j]=1;
            }
        }
        for (int i=0;i<5;i++){
            for (int j=0;j<5;j++){
                if (wrong[i][j]){
                    while (!q.empty()) q.pop();
                    memset(dis,-1,sizeof (dis[0][0])*5*5);
                    bfs(i,j,arr[i][j]);
                    wrong[i][j]=0;
                    cout << i << "  "<< j << "  " << ans <<endl;
                }
            }
        }
        for (int i=0;i<5;i++){
            for (int j=0;j<5;j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
        if (ans>10) cout << "Unsolvable in less than 11 move(s)." << endl;
        else cout << "Solvable in " << ans <<" move(s)." << endl;

    }

    return 0;
}
void bfs (int a,int b,int v){
    q.push(make_pair(a,b));
    dis[a][b]=0;
    while (!q.empty()){
        pair <int,int> u;
        u=q.front();
        int x=u.first;
        int y=u.second;
        q.pop();
        if (v==res[x][y]){
            if (v!=-1) ans+=(2*dis[x][y]);
            else ans+=(dis[x][y]);
            wrong[x][y]=0;
            int as=arr[x][y];
            arr[x][y]=arr[a][b];
            arr[a][b]=as;
            break;
        }

        if (x+2>=0 && y+1>=0 && x+2<5 && y+1<5 && arr[x][y]==res[x+2][y+1] && dis[x+2][y+1]==-1){
            q.push(make_pair(x+2,y+1));
            dis[x+2][y+1]=dis[x][y]+1;
        }
        if (x-2>=0 && y+1>=0 && x-2<5 && y+1<5 && arr[x][y]==res[x-2][y+1] && dis[x-2][y+1]==-1){
            q.push(make_pair(x-2,y+1));
            dis[x-2][y+1]=dis[x][y]+1;
        }
        if (x+2>=0 && y-1>=0 && x+2<5 && y-1<5 && arr[x][y]==res[x+2][y-1] && dis[x+2][y-1]==-1){
            q.push(make_pair(x+2,y-1));
            dis[x+2][y-1]=dis[x][y]+1;
        }
        if (x+1>=0 && y+2>=0 && x+1<5 && y+2<5 && arr[x][y]==res[x+1][y+2] && dis[x+1][y+2]==-1){
            q.push(make_pair(x+1,y+2));
            dis[x+1][y+2]=dis[x][y]+1;
        }
        if (x-1>=0 && y+2>=0 && x-1<5 && y+2<5 && arr[x][y]==res[x-1][y+2] && dis[x-1][y+2]==-1){
            q.push(make_pair(x-1,y+2));
            dis[x-1][y+2]=dis[x][y]+1;
        }
        if (x+1>=0 && y-2>=0 && x+1<5 && y-2<5 && arr[x][y]==res[x+1][y-2] && dis[x+1][y-2]==-1){
            q.push(make_pair(x+1,y-2));
            dis[x+1][y-2]=dis[x][y]+1;
        }
        if (x-2>=0 && y-1>=0 && x-2<5 && y-1<5 && arr[x][y]==res[x-2][y-1] && dis[x-2][y-1]==-1){
            q.push(make_pair(x-2,y-1));
            dis[x-2][y-1]=dis[x][y]+1;
        }
        if (x-1>=0 && y-2>=0 && x-1<5 && y-2<5 && arr[x][y]==res[x-1][y-2] && dis[x-1][y-2]==-1){
            q.push(make_pair(x-1,y-2));
            dis[x-1][y-2]=dis[x][y]+1;
        }

    }
}




