// https://practice.geeksforgeeks.org/problems/run-length-encoding/1
#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

char *encode(char *src)
{
  //Your code here
  char *ans= new char[2*strlen(src)];
  int cnt=0;
  char curr;
  for (int i=0;i<strlen(src);++i){
      if (src[i]!=curr){
          if (cnt) strcat(ans,to_string(cnt).c_str());
          strcat( ans,string(1,src[i]).c_str() );
          curr=src[i];
          cnt=1;
      }else{
          ++cnt;
      }
  }
  strcat(ans,to_string(cnt).c_str());
  return ans;
}

int main() {
	char* s=new char[100];
	s="asdavdaaavdvfvvvvseevbtgggg";
	cout << encode(s) << endl;

	return 0;
}















