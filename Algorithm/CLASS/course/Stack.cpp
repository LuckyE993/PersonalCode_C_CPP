//
// Created by Lucky_E on 2023-06-23.
//
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* Init(Node** stack)
{
    *stack = nullptr;
    return *stack;
}

bool IsEmpty(Node* stack)
{
    return stack == nullptr;
}

void Push(Node** stack,int value)
{
    Node* new_node =new Node;

    new_node->data = value;
    new_node->next = *stack;

    *stack = new_node;
}

void Pop(Node** stack)
{
    if(IsEmpty(*stack))
    {
        cout << "The stack is empty." << endl;
        return ;
    }
    Node* temp = *stack;
    *stack = (*stack)->next;

    delete temp;
}

int GetTop(Node* stack)
{
    if(IsEmpty(stack))
    {
        cout<<"The stack is empty."<<endl;
        return -1;
    }
    else
    {
        return stack->data;
    }

}

void PrintStack(Node* stack)
{
    if(IsEmpty(stack))
    {
        cout<<"The stack is empty."<<endl;
        return;
    }
    else
    {
        cout<<"The stack's element(s) is ";

        Node* current = stack;
        while(current!= nullptr)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
}

int main()
{
    Node* Stack = nullptr;

    for(int i = 0; i < 5 ; i++)
    {
        Push(&Stack,i);
    }

    PrintStack(Stack);

    cout<<"The top element is "<<GetTop(Stack)<<endl;

    Pop(&Stack);

    PrintStack(Stack);

    cout<<"The top element is "<<GetTop(Stack)<<endl;

    return 0;
}