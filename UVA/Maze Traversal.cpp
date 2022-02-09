#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

const int N=100+9,M=100+9;


char dir[]={'N','W','S','E'};
void rotate(char &direction,char &n){
	int idx=0;
	for (int i=0;i<4;++i) if (dir[i]==direction) idx=i;
	idx = (n=='L')? (idx+1+4)%4 : (idx-1+4)%4 ;
	direction=dir[idx];
}
void forward(int &x,int &y,char &direction,const int &n,const int &m,const vector <string> &state){
	if (direction=='E' && y<m-1 && state[x][y+1]!='*') ++y;
	else if (direction=='W' && y>0 && state[x][y-1]!='*') --y;
	else if (direction=='S' && x<n-1 && state[x+1][y]!='*') ++x;
	else if (direction=='N' && x>0 && state[x-1][y]!='*')  --x;
}


int main() {
	int t;
	scanf("%d",&t);
	while (t--){
		int n,m,x,y;
		vector <string> state;
		char direction='N';
		string s;

		scanf("%d %d",&n,&m);

		getline(std::cin,s);
		scanf("%d %d",&n,&m);
		for (int i=0;i<n;++i){
			getline(std::cin,s);
			state.push_back(s);
		}

		scanf("%d %d",&x,&y);
		--x,--y;
		while(1){

			cin>>s;
			bool quit=0;
			for (int i=0;i<s.size();++i){
				if (s[i]=='F') forward(x,y,direction,n,m,state);
				else if (s[i]=='R' || s[i]=='L') rotate(direction,s[i]);
				else if (s[i]=='Q'){
					quit=1;
					break;
				}
			}
			if(quit){
				printf("%d %d %c\n",x+1,y+1,direction);
				break;
			}
		}
		if (t) puts("");
	}
    return 0;
}

















