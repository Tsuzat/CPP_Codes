# include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node* previous;
        Node* next;

        Node(int val){
            this->value = val;
            this->next = NULL;
            this->previous = NULL;
        }
};

void insertAtTail(Node* &head, int val){
    Node* node = new Node(val);
    Node* temp;
    for (temp = head; temp->next != NULL; temp=temp->next);
    temp->next = node;
    node->previous = temp;
}

void insertAtHead(Node* &head, int val){
    Node* node = new Node(val);
    node->next = head;
    head->previous = node;
    head = node;
}

void print(Node* &head){
    Node* temp;
    for(temp = head; temp->next != NULL; temp = temp->next){
        cout<<temp->value<<" <--> ";
    }
    cout<<"NULL\n";
}

void deleteByValue(Node* &head, int val){
    Node* temp;
    for (temp = head; temp->next != NULL and temp->value != val; temp = temp->next);
    // if temp is in last node and temp->value != val
    if (temp->value != val){
        cout<<"Couldn't find '"<<val<<"'\n";
        return;
    }
    
    if (temp == head){
        head = head->next;
        head->previous = NULL;
    }
    else if (temp->next == NULL){
        temp->previous->next = NULL;
    }
    else{
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
    }
    delete temp;
}

int main(){
    Node* head = new Node(0);
    for (int i = 0; i<5; i++) insertAtTail(head, i+1);
    for (int i = 1; i<6; i++) insertAtHead(head, -i);

    print(head);
    deleteByValue(head,2);
    print(head);
    deleteByValue(head,100);
    print(head);
    deleteByValue(head, head->value);
    print(head);
    deleteByValue(head, 4);
    print(head);
    return 0;
}