#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node* next;

        Node(){}

        Node(int val){
            value = val;
            next = NULL;
        }
};

class LinkedList {
    
    public:
        Node* head;
        int lenght;
        // constructor
        LinkedList(Node &node){
            head = &node;
            lenght = 1;
        }

        // to display linked list
        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->value<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL";
        }

        Node* get_head(){
            return head;
        }

        // append
        void append(Node &node){
            // exception is when same nodes are passed multiple times
            Node* temp = head;
            while(temp->next != NULL) temp = temp->next;
            temp->next = &node;
            lenght ++;
        }

        // insert in the begining of linked list
        void insert_head(Node &node){
            Node* temp = new Node();
            temp->value = head->value;
            temp->next = head->next;
            head = &node;
            head->next = temp;
            lenght++;
        }

        // returns true if there is a node with given value; else false
        bool find(int val){
            for (Node* temp = head; temp != NULL; temp = temp->next)
                if (temp->value == val) return true;
            return false;
        }

        // returns the pointer of a node with given value
        Node* find_pointer(int val){
            for (Node* temp = head; temp != NULL; temp = temp->next)
                if (temp->value == val) return temp;
            return NULL;
        }

        void delete_by_value(int val){
            if (!find(val)){
                cout<<"\nvalue is not in linked list"<<endl;
                return;
            }
            Node* temp;
            for (temp = head; temp->next != NULL; temp = temp->next)
                if (temp->next->value == val) break;
            temp->next = temp->next->next;
            lenght--;
        }
        
        // will throw error if there is only head is left
        void pop(){
            if (lenght <= 1) return;
            Node* temp;
            for (temp = head; temp->next->next != NULL; temp=temp->next);
            temp->next = NULL;
            lenght--;
        }

        void reverse(){
            Node* previous = NULL;
            Node* current = head;
            Node* next_ptr;
            while(current != NULL){
                next_ptr = current->next;
                current->next = previous;

                previous = current;
                current = next_ptr;
            }
            head = previous;
        }
};

Node* reverse_Recursively(Node* &head){
    if (head->next == NULL) return head;
    Node* reversed_list = reverse_Recursively(head->next);
    // getting last node in reversed list
    Node* temp;
    for (temp=reversed_list; temp->next != NULL; temp=temp->next);
    // adding head to last element of reversed_list
    temp->next = head;
    head->next = NULL;
    return reversed_list;
}

// reverse K nodes at a time of a linked list
Node* reverseK(Node* &head, int k){
    Node* previous = NULL;
    Node* current = head;
    Node* next_ptr;
    int count = 0;
    while(current != NULL && count<k){
        next_ptr = current->next;
        current->next = previous;

        previous = current;
        current = next_ptr;
        count++;
    }

    if (next_ptr != NULL)
        head->next = reverseK(next_ptr, k);
    
    return previous;
}

void makeCycle(Node* &head, Node* &posi){
    int count = 1;
    Node* temp;
    for (temp=head; temp->next!=NULL; temp=temp->next);
    temp->next = posi;
}

void removeCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow!=fast);
    
    // making fast = head
    fast = head;
    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next = NULL;
}

bool isCyclic(Node* &head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow -> next;
        fast = fast->next->next;
        if (fast == slow) return true;
    }
    return false;
}

int main(){

    Node head(1); // initialising head node for LinkedList
    LinkedList llist(head);
    
    Node arr[4];

    // inserting elements in back
    for (int i = 0; i<4; i++){
        Node temp(i+2);
        arr[i] = temp;
        llist.append(arr[i]);
    }

    Node arr1[4];
    // inserting element in head
    for (int i = 0; i<4; i++){
        Node temp1(-i);
        arr1[i] = temp1;
        llist.insert_head(arr1[i]);        
    }
    
    // printing LinkedList
    llist.display();
    cout<<"\nlenght of LinkedList: "<<llist.lenght;

    // deleting 5
    llist.delete_by_value(5);
    cout<<endl;
    llist.display();
    cout<<"\nlenght of LinkedList: "<<llist.lenght;

    // reversing the linked list
    llist.reverse();
    cout<<"\nReversed Linked_list: ";
    llist.display();

    // reversing the linked list recursively
    llist.head = reverse_Recursively(llist.head);
    cout<<"\nRecursively Reversed Linked_list: ";
    llist.display();


    // reversing K nodes at a time
    cout<<"\nReversed k(=3) nodes: ";
    Node* new_head = reverseK(llist.head, 3);
    for(Node* temp = new_head; temp != NULL; temp=temp->next) cout<<temp->value<<" -> ";
    cout<<"NULL";

    // detecting cycle
    cout<<"\nisCyclic: "<<isCyclic(llist.head);

    // //makeCycle
    // Node* posi = llist.find_pointer(-1);
    // makeCycle(llist.head, posi);
    // // llist.display();
    // cout<<"\nisCyclic: "<<isCyclic(llist.head);

    // // remove cycle
    // removeCycle(llist.head);
    // cout<<"\nisCyclic: "<<isCyclic(llist.head);
    // cout<<endl;
    // llist.display();


    return 0;
}
