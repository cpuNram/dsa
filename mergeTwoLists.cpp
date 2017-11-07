#include <iostream>

using namespace std;
struct node {
    int data;
    node *next;
};

typedef struct node Node;

Node* addItem(Node *head, int item)
{
    Node *tmpnode = nullptr;
    tmpnode = new Node;
    tmpnode->data = item;
    tmpnode->next = nullptr;
    if (!head) head = tmpnode;
    else {
        Node *tmpnode1 = head;
        while(tmpnode1->next) tmpnode1 = tmpnode1->next;
        tmpnode1->next = tmpnode;
    }
    return head;
}

Node* mergeLists(Node *L1, Node *L2)
{

    if (!L1 && !L2) return nullptr;
    if (!L1) return L2;
    if (!L2) return L1;
    Node *mergeList = nullptr;

    while (L1 && L2) {
        int item = 0;
        if (L1->data <= L2->data) {
            item = L1->data;
            L1 = L1->next;
        } else {
            item = L2->data;
            L2 = L2->next;
        }
        mergeList = addItem(mergeList, item);
    }

    while (L1) {
        mergeList = addItem(mergeList, L1->data);
        L1 = L1->next;
    }
    while (L2) {
        mergeList = addItem(mergeList, L2->data);
        L2 = L2->next;
    }

    return mergeList;
}

Node* printList(Node* mergeList)
{
    Node *head = mergeList;
    while (head) {
        cout << head->data << ", ";
        head = head->next;
    }
    return mergeList;
}

int main(void)
{
    Node *L1 = nullptr;
    Node *L2 = nullptr;
    L1 = addItem(L1, 1);
    L1 = addItem(L1, 2);
    L1 = addItem(L1, 3);
    L1 = addItem(L1, 4);

    L2 = addItem(L2, 3);
    L2 = addItem(L2, 3);
    L2 = addItem(L2, 5);
    L2 = addItem(L2, 6);

   Node* mergeList = mergeLists(L1, L2);
   printList(mergeList);
}
