#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

vector <string> rotate(vector<string> s,int n){
	vector <string> res(n);
	for (int j=0;j<n;++j){
		res[j]="";
		for (int i=n-1;i>=0;--i){
			res[j]=res[j]+s[i][j];
		}
	}
	return res;
}

int main() {
    int N,n;
    while(scanf("%d %d",&N,&n) && N){
    	vector <string> big(N),small(n),rot[4];
    	for (int i=0;i<N;++i) cin>>big[i];
    	for (int i=0;i<n;++i){
    		cin>>small[i];
    		rot[0].push_back(small[i]);
    	}
    	rot[1]=rotate(rot[0],n);
    	rot[2]=rotate(rot[1],n);
    	rot[3]=rotate(rot[2],n);
    	int ans[]={0,0,0,0};
    	for (int i=0;i<4;++i) for (int j=0;j<=N-n;++j) for (int k=0;k<=N-n;++k){
			int ch=1;
			for (int x=j;x<n+j;++x){
				for (int y=k;y<n+k;++y){
					//dbg2(x,y);
					if (rot[i][x-j][y-k]!=big[x][y]){
						ch=0;
						break;
					}
				}
				if (!ch) break;
			}
			ans[i]+=ch;
		}
    	for (int i=0;i<4;++i) cout<< ans[i] << " \n"[i==3];
    	/*for (int i=0;i<4;++i){
    		for (int j=0;j<n;++j){
    			cout << rot[i][j]<< endl;
    		}
    		cout << endl;
    	}*/
    }

    return 0;
}









