//
// Created by Lucky_E on 2023-06-24.
//
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool IsEmpty(Node* queue)
{
    return (front==nullptr && back==nullptr);
}

void Insert(Node** queue,int value)
{
    Node* new_node = new Node;

    new_node->data = value;
    new_node->next = nullptr;

    if(IsEmpty(*queue))
    {
        front = back = new_node;
    }
    else
    {
        back->next = new_node;
        back = new_node;
    }

    cout<<value<<" 入队成功"<<endl;

}

void Remove(Node** queue)
{
    if(IsEmpty(*queue))
    {
        cout<<"空队列。"<<endl;
        return;
    }
    else
    {
        Node* temp_node = new Node;
        temp_node = front;
        front = front->next;

        if(front->next == nullptr)
        {
            back = nullptr;
        }

        cout<<temp_node->data<<" 出队成功"<<endl;
        delete temp_node;

    }
}

void PrintQueue(Node* queue)
{
    if(IsEmpty(queue))
    {
        cout<<"队列为空"<<endl;
        return;
    }
    else
    {
        Node* current = new Node;
        current = front;
        while(current != nullptr)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
}

void GetQueue(Node* queue)
{
    if(IsEmpty(queue))
    {
        cout<<"队列为空"<<endl;
    }
    else
    {
        cout<<front->data<<" 是队列末尾元素"<<endl;
    }

}

int main()
{
    Node* queue = new Node;
    queue = nullptr;

    if(IsEmpty(queue))
    {
        cout<<"队列为空"<<endl;
    }
    else
    {
        cout<<"队列不为空"<<endl;
    }

    for(int i=0;i<10;i++)
    {
        Insert(&queue,i);
    }
    GetQueue(queue);
    PrintQueue(queue);

    Remove(&queue);
    GetQueue(queue);


    Remove(&queue);
    PrintQueue(queue);
    return 0;
}