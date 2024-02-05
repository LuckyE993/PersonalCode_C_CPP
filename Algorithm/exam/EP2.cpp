//
// Created by LuckyE on 2023-06-04.
//
#include <iostream>

using namespace std;

// ������ջ�ڵ�ṹ��
struct Node
{
    int data;
    Node* next;
};

// ��ջ�ṹ��
struct Stack
{
    Node* top;
};

// ��ʼ����ջ
void initStack(Stack& stack)
{
    stack.top = nullptr;
}

// �ж���ջ�Ƿ�Ϊ��
bool isEmpty(Stack& stack)
{
    return stack.top == nullptr;
}

// ������ջ�ڵ�
Node* createNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// ��ջ
void push(Stack& stack, int data)
{
    Node* newNode = createNode(data);
    newNode->next = stack.top;
    stack.top = newNode;
}

// ��ջ
int pop(Stack& stack)
{
    if (isEmpty(stack))
    {
        cerr << "��ǰջΪ��" << endl;
        exit(1);
    }

    Node* temp = stack.top;
    int data = temp->data;
    stack.top = temp->next;// ��ջ��ָ��ָ����һ���ڵ㣬����ջ���ڵ��ջ
    delete temp;//�ͷ��ڴ�
    return data;
}

//�������
void reverse(Stack& stack)
{
    cout << "�����������";
    while (!isEmpty(stack))
    {
        int data = pop(stack);
        cout << data << " ";
    }
    cout << endl;
}

int main()
{
    Stack stack{};
    initStack(stack);

    int n;
    cout << "����ջ��Ԫ�ظ�����";
    cin >> n;

    cout << "����������ջ��Ԫ��";
    for (int i = 0; i < n; ++i)
    {
        int data;
        cin >> data;
        push(stack, data);
    }

    reverse(stack);

    return 0;
}
