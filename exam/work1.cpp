//
// Created by izumi on 2023-06-15.
//
#include <iostream>

using namespace std;

// 定义双链表节点结构
struct Node {
    int data;       // 数据域
    Node* prev;     // 前驱指针
    Node* next;     // 后继指针
};

// 创建双链表
Node* createList() {
    int n, data;
    cout << "输入节点个数: ";
    cin >> n;

    if (n <= 0) {
        cout << "无效的节点个数！" << endl;
        return nullptr;
    }

    Node* head = nullptr;
    Node* newNode, *temp;

    cout << "输入节点1的数据: ";
    cin >> data;
    head = new Node;
    head->data = data;
    head->prev = nullptr;
    head->next = nullptr;
    temp = head;

    for (int i = 2; i <= n; i++) {
        newNode = new Node;
        cout << "输入节点" << i << "的数据: ";
        cin >> data;
        newNode->data = data;
        newNode->prev = temp;
        newNode->next = nullptr;
        temp->next = newNode;
        temp = temp->next;
    }

    cout << "双链表创建成功！" << endl;
    return head;
}

// 在指定位置插入节点
void insertNode(Node*& head) {
    if (head == nullptr) {
        cout << "双链表为空！" << endl;
        return;
    }

    int pos, data;
    cout << "输入要插入的位置: ";
    cin >> pos;
    cout << "输入要插入的数据: ";
    cin >> data;

    Node* newNode = new Node;
    newNode->data = data;

    if (pos == 1) {
        newNode->prev = nullptr;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
            if (temp == nullptr) {
                cout << "无效的插入位置！" << endl;
                delete newNode;
                return;
            }
        }

        newNode->prev = temp;
        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    cout << "节点插入成功！" << endl;
}

// 删除指定位置的节点
void deleteNode(Node*& head) {
    if (head == nullptr) {
        cout << "双链表为空！" << endl;
        return;
    }

    int pos;
    cout << "输入要删除的位置: ";
    cin >> pos;

    Node* temp;
    if (pos == 1) {
        temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    } else {
        temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
            if (temp == nullptr) {
                cout << "无效的删除位置！" << endl;
                return;
            }
        }

        temp->prev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    cout << "节点删除成功！" << endl;
}

// 遍历双链表
void traverseList(Node* head) {
    if (head == nullptr) {
        cout << "双链表为空！" << endl;
        return;
    }

    cout << "双链表的元素: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // 创建双链表
    head = createList();

    // 遍历双链表
    traverseList(head);

    // 在指定位置插入节点
    insertNode(head);

    // 遍历双链表
    traverseList(head);

    // 删除指定位置的节点
    deleteNode(head);

    // 遍历双链表
    traverseList(head);

    return 0;
}

