#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

int wrong_pen[109][20],accepted_pen[109][20];
bool problems_acc[109][20],teams[109];
void reset(){
	memset(teams,0,sizeof(teams));
	for (int i=0;i<109;++i){
		memset(wrong_pen[i],0,sizeof(wrong_pen[i]));
		memset(problems_acc[i],0,sizeof(problems_acc[i]));
		memset(accepted_pen[i],-1,sizeof(accepted_pen[i]));
	}
}


int main() {
	int t;
	char submission[10];
	scanf("%d",&t);
	for (int i=0;i<2;++i) gets(submission);
	priority_queue <pair<pair<int,int>,int > > q;
	while(t--){
		reset();
		int team_num,prob_num,time_pen;
		char judge;
		while(gets(submission) && strlen(submission)!=0){
			//if (strlen(submission)!=0) break;
			sscanf(submission,"%d %d %d %c",&team_num,&prob_num,&time_pen,&judge);
			teams[team_num]=1;
			if (judge=='C'){
				if (accepted_pen[team_num][prob_num]==-1) accepted_pen[team_num][prob_num]=time_pen;
				problems_acc[team_num][prob_num]=1;
			}else if (judge=='I'){
				if (accepted_pen[team_num][prob_num]==-1) wrong_pen[team_num][prob_num]+=20;
			}
		}
		for (int i=0;i<109;++i){
			if (teams[i]){
				int problem_cnt=0,total_pen=0;
				for (int j=0;j<11;++j){
					if(problems_acc[i][j]) ++problem_cnt,total_pen+=accepted_pen[i][j]+wrong_pen[i][j];
				}
				q.push({{problem_cnt,-total_pen},-i});
			}
		}
		while(!q.empty()){
			printf("%d %d %d\n",-q.top().second,q.top().first.first,-q.top().first.second);
			q.pop();
		}
		if(t) printf("\n");
	}
	return 0;
}
















