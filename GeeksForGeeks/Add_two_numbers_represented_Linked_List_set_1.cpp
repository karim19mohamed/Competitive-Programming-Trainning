// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-list/1
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

Node* addSameSize(Node* head1, Node* head2, int* carry) {
	if(head2==NULL){
	    return NULL;
	}
	Node* n=new Node(0);
	n->next=addSameSize(head1->next,head2->next,carry);

	int tmp=head1->data+head2->data+*carry;
	n->data=tmp%10;
	*carry=tmp/10;
	return n;
}

void addCarryToRemaining(Node* head1, Node* curr, int* carry, Node** result) {
	if (head1==curr){
	    return ;
	}
	Node* n=new Node(0);
    addCarryToRemaining(head1->next,curr,carry,result);
    int tmp=head1->data+*carry;
    n->data=tmp%10;
    *carry=tmp/10;
    n->next=*result;
    *result=n;
}

int main() {
	//code

	return 0;
}
















