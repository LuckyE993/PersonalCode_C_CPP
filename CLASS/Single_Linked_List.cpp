//
// Created by Lucky_E on 2023-06-16.
//
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insert(Node** head,int data)
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    if(*head==nullptr)
    {
        *head = new_node;
    }
    else
    {
        Node* current = *head;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insertAtPosition(Node** head,int data,int position)
{
    cout << "insertAtPosition >= 0"<<endl;
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    if(position==0)
    {
        new_node->next = *head;
        *head = nullptr;
    }
    else
    {
        Node* current = *head;
        for(int i=0;i<position-1;i++)
        {
            if(current == nullptr)
            {
                cout<<"Invalid position."<<endl;
                return;
            }
            else
            {
                current = current->next;
            }
        }

        new_node->next = current;
        current->next = new_node;
    }
}

int main()
{

    return 0;
}