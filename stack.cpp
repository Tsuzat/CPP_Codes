#include<bits/stdc++.h>
using namespace std;
class stackNode{
    public:
        int value;
        stackNode* next;
        stackNode(int val){
            this->value = val;
            this->next = NULL;
        }

		stackNode(stackNode* node){
			this->value = node->value;
			this->next = node->next;
		}
};

bool empty(stackNode* &s){
	if (s == NULL) return true;
	return false;
}

int top(stackNode* &s){
	if (!empty(s)) 
		return s->value;
	return INT_MIN;
}

void pop(stackNode* &s){
	if (empty(s)) {
		cout<<"Stack is empty";
		return;
	} 
	stackNode* temp = s->next;
	s = temp;
}

void push(stackNode* &s, int x){
	stackNode* node = new stackNode(x), *temp = s;
	s = node;
	s->next = temp;
}

void print(stackNode* &s){
	for (stackNode* temp = s; temp->next!= NULL; temp=temp->next) cout<<temp->value<<" -> ";
	cout<<"NULL\n";
}

int main(){
    stackNode* s = new stackNode(0);
    for (int i = 1; i<=5; i++) push(s,i);
    print(s);
	pop(s);
	print(s);
	cout<<empty(s)<<endl;
	cout<<top(s)<<endl;
    return 0;
}