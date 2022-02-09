// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
#include <bits/stdc++.h>
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

int solve(int x,int y,Node* n){
    int sum=n->data+x+y;
    n->data=sum%10;
    return sum/10;
}
Node* addTwoLists(Node* first, Node* second) {
    // Code here
    int r=0;
    Node* n=new Node(0);
    Node* ans=new Node(0);
    ans=n;
    while(first!=NULL || second!=NULL){
        if (first==NULL){
            r=solve(0,second->data,n);
            second=second->next;
        }else if (second==NULL){
            r=solve(0,first->data,n);
            first=first->next;
        }else{
            r=solve(first->data,second->data,n);
            first=first->next;
            second=second->next;
        }
        if (first!=NULL || second!=NULL || r!=0){
            Node* tmp=new Node(0);
            n->next=tmp;
            n=n->next;
            n->data=r;
        }
    }
    return ans;
}

int main() {
	//code

	return 0;
}
















