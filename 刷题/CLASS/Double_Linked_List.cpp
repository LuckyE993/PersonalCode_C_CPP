//
// Created by Lucky_E on 2023-06-21.
//
#include <iostream>
using namespace std;
struct Node;
void InsertNode(Node** head,int value);
void get_length(Node* head);
void isempty(Node* head);
void PrintList(Node* head);
Node* SearchNode(Node* head,int value);
void DeleteNode(Node** head,int value);



struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* CreateNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void InsertNode(Node** head,int value)
{
    Node* newNode = CreateNode(value);

    if(*head == nullptr)
    {
        newNode->prev = nullptr;
        *head = newNode;
        return;
    }

    Node* LastNode = *head;
    while(LastNode->next != nullptr)
    {
        LastNode = LastNode->next;
    }
    LastNode->next = newNode;
    newNode->prev = LastNode;

}

void DeleteNode(Node** head,int value)
{
    Node* currentNode = *head;

    while(currentNode!= nullptr&&currentNode->data!=value)
    {
        currentNode = currentNode->next;
    }

    if(currentNode == nullptr)
    {
        cout<<"The list is empty."<<endl;
        return;
    }

    if(currentNode->prev!= nullptr)
    {
        currentNode->prev->next = currentNode->next;
    }

    if(currentNode->next != nullptr)
    {
        currentNode->next->prev = currentNode->prev;
    }

    if(currentNode == *head)
    {
        *head = currentNode->next;
    }

    delete currentNode;

}

Node* SearchNode(Node* head,int value)
{
    Node* CurrentNode = head;
    while(CurrentNode != nullptr)
    {
        if(CurrentNode->data == value)
        {
            return CurrentNode;
        }
        CurrentNode = CurrentNode->next;
    }

    return nullptr;
}

void PrintList(Node* head)
{
    if(head == nullptr)
    {
        cout<<"Empty list"<<endl;
        return;
    }
    Node* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void isempty(Node* head)
{
    if(head == nullptr)
    {
        cout<<"The list is empty."<<endl;
    }
    else
    {
        cout<<"The list is not empty."<<endl;
    }
}

void get_length(Node* head)
{
    if(head == nullptr)
    {
        cout<<"0"<<endl;
        return;
    }

    int num = 1;
    Node* temp = head;
    while(temp != nullptr)
    {
        num++;
        temp = temp->next;
    }
    cout<<"The length of the List is "<<num<<endl;
}

int main()
{
    Node* list = nullptr;

    for(int i = 1; i <10;i++)
    {
        InsertNode(&list,i);
    }

    PrintList(list);

    get_length(list);

    isempty(list);

    if(SearchNode(list,5) == nullptr)
    {
        cout<<"Not found"<<endl;
    }
    else
    {
        cout<<"Node found"<<endl;
    }

    DeleteNode(&list,5);

    if(SearchNode(list,5) == nullptr)
    {
        cout<<"Not found"<<endl;
    }
    else
    {
        cout<<"Node found"<<endl;
    }

    return 0;
}