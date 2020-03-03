#include <bits/stdc++.h>
using namespace std;
int n,q,r,c;
int col_barr,diag_barr;
bool a[2][100009];

int main() {
	scanf("%d %d",&n,&q);
	for (int i=0;i<q;++i){
		scanf("%d %d",&r,&c);
		--r,--c;
		if(!a[r][c]){ // not forbiddean
			a[r][c]=1;
			if (r==0){
				if (a[r+1][c]==1) ++col_barr;
				if (a[r+1][c+1]==1) ++diag_barr;
				if (a[r+1][c-1]==1) ++diag_barr;
			}else if (r==1){
				if (a[r-1][c]==1) ++col_barr;
				if (a[r-1][c+1]==1) ++diag_barr;
				if (a[r-1][c-1]==1) ++diag_barr;
			}
		}else{ // forbiddean
			a[r][c]=0;
			if (r==0){
				if (a[r+1][c]==1) --col_barr;
				if (a[r+1][c+1]==1) --diag_barr;
				if (a[r+1][c-1]==1) --diag_barr;
			}else if (r==1){
				if (a[r-1][c]==1) --col_barr;
				if (a[r-1][c+1]==1) --diag_barr;
				if (a[r-1][c-1]==1) --diag_barr;
			}
		}
		//cout << col_barr << "  " << diag_barr << endl;
		if (col_barr>0 || diag_barr>0) puts("NO");
		else puts("YES");
	}
	return 0;
}
