//
// Created by LuckyE on 2023-06-04.
//
#include <iostream>

using namespace std;

// 定义链栈节点结构体
struct Node
{
    int data;
    Node* next;
};

// 链栈结构体
struct Stack
{
    Node* top;
};

// 初始化链栈
void initStack(Stack& stack)
{
    stack.top = nullptr;
}

// 判断链栈是否为空
bool isEmpty(Stack& stack)
{
    return stack.top == nullptr;
}

// 创建链栈节点
Node* createNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// 入栈
void push(Stack& stack, int data)
{
    Node* newNode = createNode(data);
    newNode->next = stack.top;
    stack.top = newNode;
}

// 出栈
int pop(Stack& stack)
{
    if (isEmpty(stack))
    {
        cerr << "当前栈为空" << endl;
        exit(1);
    }

    Node* temp = stack.top;
    int data = temp->data;
    stack.top = temp->next;// 将栈顶指针指向下一个节点，即将栈顶节点出栈
    delete temp;//释放内存
    return data;
}

//逆序并输出
void reverse(Stack& stack)
{
    cout << "逆序结果输出：";
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
    cout << "输入栈的元素个数：";
    cin >> n;

    cout << "依次输入入栈的元素";
    for (int i = 0; i < n; ++i)
    {
        int data;
        cin >> data;
        push(stack, data);
    }

    reverse(stack);

    return 0;
}
