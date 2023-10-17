//
// Created by Lucky_E on 2023-06-29.
//
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void Insert(Node*& node, int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = nullptr;

    if(node == nullptr)
    {
        node = newNode;
    }
    else
    {
        Node* current = node;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

}

Node* Merge(Node* l1, Node* l2)
{
    Node* temp = new Node;
    Node* current = temp;

    while (l1!=nullptr && l2!=nullptr)
    {
        if(l1->data<=l2->data)
        {
            current->next = l1;
            l1 = l1->next;
        }
        else
        {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;

    }
    if(l1!= nullptr)
    {
        current->next = l1;
    }
    if(l2!= nullptr)
    {
        current->next = l2;
    }

    Node* Merged_list = temp->next;
    return Merged_list;
}

void Print(Node* ls)
{
    Node* current = ls;
    while(current!=nullptr)
    {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

int main()
{
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    for(int i=0;i<10;i+=2)
    {
        Insert(list1,i);
    }
    for(int i=1;i<10;i+=2)
    {
        Insert(list2,i);
    }

    cout<<"ls1:"<<endl;
    Print(list1);
    cout<<endl;

    cout<<"ls2:"<<endl;
    Print(list2);

    Node* MergedList = Merge(list1,list2);
    cout<<"mergedlist:"<<endl;
    Print(MergedList);
    return 0;
}
