// #include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define endl '\n'

class node {
    public:
        int val;
        node *next;
        node(int data):val(data), next(nullptr) {};
        node():val(0), next(nullptr){};
        node(int data, node* upnext):val(data), next(upnext){};
};

// taking head by value since we'll not modify
bool isPresent(node *head, int val) {
    for (node *temp = head; temp != nullptr; temp = temp->next) {
        if (temp->val == val)
            return true;
    }
    return false;
}

// taking head by reference since we'll modify it
void append(node *&head, int val) {
    node *n = new node(val);
    if (head == nullptr) {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = n;
}

// taking head by reference since we'll modify it
void insertAtHead(node *&head, int val) {
    node *n = new node(val);
    n->next = head;
    head = n;
}

//=============================================================//
/*
   Detection and removal of cycle in linked list
   Also known as Floyd's Algorithm or Hare and Tortoise Algorithm
   */

// taking head by value since we'll not modify
bool isCyclic(node *head) {
    node *fast = head;
    node *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

// taking head by reference since we'll modify it
// function takes a position and makes a cycle
void makeCycle(node *&head, int pos) {
    node *temp = head;
    node *startNode;
    int i = 1;
    while (temp->next != nullptr) {
        if (i == pos)
            startNode = temp;
        temp = temp->next;
        i++;
    }
    temp->next = startNode;
}

void removeCycle(node *&head) {
    if (!isCyclic(head))
        return;

    node *fast = head;
    node *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    fast = head;
    while (fast->next != slow->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = nullptr;
}

//===========================================================//

// taking head by reference since we'll modify it
void reverseIteratively(node *&head) {
    node *prev = nullptr;
    node *current = head;
    node *upnext;
    while (current != nullptr) {
        upnext = current->next;
        current->next = prev;

        prev = current;
        current = upnext;
    }
    head = prev;
}

// taking head by reference since we'll modify it
void reverseRecursively(node *&head) {
    if (head == nullptr)
        return;

    node *sortedList = head->next;
    head->next = nullptr;
    reverseRecursively(sortedList);

    // appending head in sortedList
    append(sortedList, head->val);
    head = sortedList;
}

// taking head by reference since we'll modify it
void reverseFirstK(node *&head, int k) {
    if (k == 0 || k == 1)
        return;

    node *prev = nullptr;
    node *current = head;
    node *upnext;
    for (int i = 0; current != nullptr && i < k; i++) {
        upnext = current->next;
        current->next = prev;

        prev = current;
        current = upnext;
    }
    head->next = current;
    head = prev;
}

// taking head by reference since we'll modify it
void remove(node *&head, int val) {
    // checking if the value is present
    if (!isPresent(head, val))
        return;
    // checking if the head has the value
    if (head->val == val) {
        node *todel = head;
        head = head->next;
        delete todel;
        return;
    }
    // searching for the node before node->val == val
    node *temp = head;
    while (temp->next != nullptr && temp->next->val != val)
        temp = temp->next;
    node *todel = temp->next;
    temp->next = todel->next;
    delete todel;
}

// taking head by value since we'll not modify
int length(node *head) {
    int count = 0;
    for (node *temp = head; temp != nullptr; temp = temp->next)
        count++;
    return count;
}

// taking head by reference since we'll modify it
void insertLastKElementsAtHead(node *&head, int k) {
    int l = length(head);
    k = k % l; // case if k is larger than l
    if (k == 0)
        return;
    int count = 1;
    node *newHead;
    node *newTail;
    node *tail = head;
    while (tail->next != nullptr) {
        if (count == l - k)
            newTail = tail;
        if (count == l - k + 1)
            newHead = tail;
        tail = tail->next;
        count++;
    }
    newTail->next = nullptr;
    tail->next = head;
    head = newHead;
}

// taking head by value since we'll not modify
int interSection(node *head1, node *head2) {
    int l1 = length(head1);
    int l2 = length(head2);
    int d = abs(l1 - l2);
    node *p1 = l1 > l2 ? head1 : head2;
    node *p2 = l1 > l2 ? head2 : head1;
    while (d--) {
        p1 = p1->next;
        if (p1 == nullptr)
            return -1;
    }

    while (p1 != nullptr && p2 != nullptr) {
        if (p1 == p2)
            return p1->val;
        p1 = p1->next;
        p2 = p2->next;
    }
    return -1;
}

// taking head by value since we'll modify it
// intersects head2 at position pos in head1 (considering len(head1) > pos)
void intersect(node *&head1, node *&head2, int pos) {

    if (pos <= 0 || pos > length(head1))
        return;

    node *temp1 = head1;
    pos--;
    while (pos--) {
        temp1 = temp1->next;
    }
    node *temp2 = head2;
    for (; temp2->next != nullptr; temp2 = temp2->next)
        ;
    temp2->next = temp1;
}

// taking head by value since we'll not modify it
node *mergeIteratively(node *head1, node *head2) {
    node *p1 = head1;
    node *p2 = head2;
    node *dummy = new node(INT_MAX);
    node *p = dummy;
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->val < p2->val) {
            p->next = p1;
            p1 = p1->next;
        } else {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    if (p1 != nullptr)
        p->next = p1;
    else
        p->next = p2;
    return dummy->next;
}

node *mergeRecursevily(node *head1, node *head2) {

    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    if (head1->val < head2->val) {
        head1->next = mergeRecursevily(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeRecursevily(head1, head2->next);
        return head2;
    }
}

int maxInList(node *&head) {
    int ans = INT_MIN;
    for (node *temp = head; temp != nullptr; temp = temp->next)
        ans = max(ans, temp->val);
    return ans;
}

int minInList(node *&head) {
    int ans = 0;
    for (node *temp = head; temp != nullptr; temp = temp->next) {
        ans = min(ans, temp->val);
    }
    return ans;
}

// taking head by value since we'll not modify
void display(node *head) {
    for (node *temp = head; temp != nullptr; temp = temp->next)
        cout << temp->val << " -> ";
    cout << "null\n";
}

int main() {
    node *head1 = nullptr;
    node *head2 = nullptr;

    for (int i = 1; i < 20; i += 2)
        append(head1, i);
    for (int i = 2; i < 20; i += 2)
        append(head2, i);

    display(head1);
    display(head2);

    display(mergeRecursevily(head1, head2));

    return 0;
}
