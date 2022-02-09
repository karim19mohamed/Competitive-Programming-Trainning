#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=100+9,M=100+9;
bool state[N][M];

char dir[]={'N','W','S','E'};
void rotate(char &direction,char &n){
	int idx=0;
	for (int i=0;i<4;++i) if (dir[i]==direction) idx=i;
	idx = (n=='L')? (idx+1+4)%4 : (idx-1+4)%4 ;
	direction=dir[idx];
}
void forward(int &x,int &y,char &direction){
	if (direction=='N') ++y;
	else if (direction=='S') --y;
	else if (direction=='E') ++x;
	else  --x;
}

int main() {
	int n,m,x,y;
	char direction;
	scanf("%d %d",&n,&m);
	while (scanf("%d %d %c",&x,&y,&direction)!= EOF){
		bool lost=0;
		string s;
		cin>>s;
		for (int i=0;i<s.size();++i){
			if (s[i]=='F') forward(x,y,direction);
			else rotate(direction,s[i]);
			if (x<0){
				if (state[x+1][y]){
					++x;
					continue;
				}
				lost=1;
				state[++x][y]=1;
				break;
			}else if (x>n){
				if (state[x-1][y]){
					--x;
					continue;
				}
				lost=1;
				state[--x][y]=1;
				break;
			}else if (y<0){
				if (state[x][y+1]){
					++y;
					continue;
				}
				lost=1;
				state[x][++y]=1;
				break;
			}else if (y>m){
				if (state[x][y-1]){
					--y;
					continue;
				}
				lost=1;
				state[x][--y]=1;
				break;
			}
		}
		printf("%d %d %c",x,y,direction);
		(lost)? puts(" LOST") : puts("");
	}
    return 0;
}

















