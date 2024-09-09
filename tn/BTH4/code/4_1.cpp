#include <iostream> 
using namespace std;
struct Node { 
    int data; 
    Node* next;
};
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
Node* createNewNode(int data) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node* newNode = createNewNode(data);
    newNode->next=head;
    head=newNode;
    return head;
}

// print the list content on a line
void print(Node* head) {
    
    while (head != NULL)
    {
        cout<<head -> data<<" ";
        head=head->next;
    }
    cout<<endl;
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    Node* curr = head;
    Node* pre = NULL;
    Node* nex = NULL;
    while (curr != NULL)
    {
        nex = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nex;
    }
    head=pre;
    return head;
}
  
int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}