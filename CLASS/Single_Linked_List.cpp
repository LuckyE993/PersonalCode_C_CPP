#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

Node* CreateNode(int value)
{
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

void InsertNode(Node** head,int value)
{
    Node* newNode = CreateNode(value);
    if(*head == nullptr)
    {
        *head = newNode;
    }
    else
    {
        Node* temp = *head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void DeleteNode(Node** head,int data)
{
    Node* temp = *head;
    Node* prev = nullptr;

    if(temp!=nullptr &&temp->value==data)
    {
        *head = temp->next;
        delete temp;
        return;
    }

    while(temp!=nullptr&&temp->value!=data)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == nullptr)
    {
        cout << "None node"<<endl;
        return ;
    }

    prev->next = temp->next;
    delete temp;

}

void PrintList(Node* head)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout<< temp->value<<endl;
        temp = temp->next;
    }

}
void FindPosition(Node* head,int data)
{
    int position = 0;
    Node* temp = head;

    if(temp!=nullptr&&temp->value==data)
    {
        cout<<"The "<<data<<" is "<<position<<" in this list."<<endl;
        return;
    }

    while(temp!=nullptr&&temp->value!=data)
    {
        temp=temp->next;
        position++;
        if(temp->value==data)
        {
            cout<<"The "<<data<<" is "<<position<<" in this list."<<endl;
            return;
        }
        if(temp->next == nullptr)
        {
            cout<<"Not found."<<endl;
            return;
        }
    }
    if(temp == nullptr)
    {
        cout<<"The list is empty"<<endl;
        return;
    }

}
void isEmpty(Node* head)
{
    if(head==nullptr)
    {
        cout<<"The list is empty."<<endl;
    }
    else
    {
        cout<<"The list is not empty"<<endl;
    }
}

int main()
{
    Node* Single_List = nullptr;
    isEmpty(Single_List);

    InsertNode(&Single_List,22);
    InsertNode(&Single_List,24);
    InsertNode(&Single_List,267);

    cout<<"After insert some nodes."<<endl;
    isEmpty(Single_List);

    PrintList(Single_List);
    cout<<"Delete Node Value 24"<<endl;

    DeleteNode(&Single_List,24);

    PrintList(Single_List);

    FindPosition(Single_List,22);

    FindPosition(Single_List,24);
    return 0;
}