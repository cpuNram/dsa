#include <iostream>

using namespace std;
typedef struct node {
    int data;
    node *next;
} Node;

void addItem(Node **head, int item)
{
    Node *tmpnode = new Node;
    tmpnode->data = item;
    tmpnode->next = nullptr;
    if (!(*head)) *head = tmpnode;
    else {
        tmpnode->next = *head;
        *head = tmpnode;
    }
}

void MoveData(Node **src, Node **dest)
{
    Node *tmpnode = *src;
    *src = (*src)->next;
    tmpnode->next = *dest;
    *dest = tmpnode;
}

Node* mergeLists(Node *L1, Node *L2)
{

    if (!L1 && !L2) return nullptr;
    if (!L1) return L2;
    if (!L2) return L1;
    Node mergeList;
    mergeList.next = nullptr;
    Node *tail = &mergeList;

    while (L1 && L2) {
        if (L1->data <= L2->data) {
            MoveData(&L1, &(tail->next));
        } else {
            MoveData(&L2, &(tail->next));
        }
        tail = tail->next;
    }

    if (L1) {
        tail->next = L1;
    }
    if (L2) {
        tail->next = L2;
    }

    return mergeList.next;
}

void printList(Node* mergeList)
{
    Node *head = mergeList;
    while (head) {
        cout << head->data << ", ";
        head = head->next;
    }
    cout << "\n";
}

int main(void)
{
    Node *L1 = nullptr;
    addItem(&L1, 4);
    addItem(&L1, 3);
    addItem(&L1, 2);
    addItem(&L1, 1);
    cout << "L1 : "; printList(L1);
    Node *L2 = nullptr;
    addItem(&L2, 6);
    addItem(&L2, 5);
    addItem(&L2, 3);
    cout << "L2 : "; printList(L2);
    Node* mergeList = mergeLists(L1, L2);
    cout << "Merged List: "; printList(mergeList);
}
