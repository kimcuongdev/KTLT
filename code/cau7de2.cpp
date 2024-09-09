#include <bits/stdc++.h>
using namespace std;
 struct node{
    int data;
    node* pnext;
};
node* newnode(int data)
{
    node* newnode = new node;
    newnode->data = data;
    newnode->pnext = NULL;
    return newnode;
}
int maxEven(node* head)
{
    int max = -1;
    if (head == NULL)
    {
        return 0;
    }
    while (head != NULL)
    {
        if ((head->data % 2 == 0) && (head->data > max))
        {
            max = head->data;
        }
        head = head->pnext;
    }
    return (max == -1)?0:max;
}

int main()
{
    node* head=newnode(2);
    node* p1=newnode(10);
    head->pnext = p1;
    node* p2 = newnode(6);
    p1->pnext = p2;
    int max = maxEven(head);
    printf("%d",max);
}