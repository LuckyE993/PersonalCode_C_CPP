//
// Created by izumi on 2023-06-15.
//
#include <iostream>

using namespace std;

// ����˫����ڵ�ṹ
struct Node {
    int data;       // ������
    Node* prev;     // ǰ��ָ��
    Node* next;     // ���ָ��
};

// ����˫����
Node* createList() {
    int n, data;
    cout << "����ڵ����: ";
    cin >> n;

    if (n <= 0) {
        cout << "��Ч�Ľڵ������" << endl;
        return nullptr;
    }

    Node* head = nullptr;
    Node* newNode, *temp;

    cout << "����ڵ�1������: ";
    cin >> data;
    head = new Node;
    head->data = data;
    head->prev = nullptr;
    head->next = nullptr;
    temp = head;

    for (int i = 2; i <= n; i++) {
        newNode = new Node;
        cout << "����ڵ�" << i << "������: ";
        cin >> data;
        newNode->data = data;
        newNode->prev = temp;
        newNode->next = nullptr;
        temp->next = newNode;
        temp = temp->next;
    }

    cout << "˫�������ɹ���" << endl;
    return head;
}

// ��ָ��λ�ò���ڵ�
void insertNode(Node*& head) {
    if (head == nullptr) {
        cout << "˫����Ϊ�գ�" << endl;
        return;
    }

    int pos, data;
    cout << "����Ҫ�����λ��: ";
    cin >> pos;
    cout << "����Ҫ���������: ";
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
                cout << "��Ч�Ĳ���λ�ã�" << endl;
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

    cout << "�ڵ����ɹ���" << endl;
}

// ɾ��ָ��λ�õĽڵ�
void deleteNode(Node*& head) {
    if (head == nullptr) {
        cout << "˫����Ϊ�գ�" << endl;
        return;
    }

    int pos;
    cout << "����Ҫɾ����λ��: ";
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
                cout << "��Ч��ɾ��λ�ã�" << endl;
                return;
            }
        }

        temp->prev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    cout << "�ڵ�ɾ���ɹ���" << endl;
}

// ����˫����
void traverseList(Node* head) {
    if (head == nullptr) {
        cout << "˫����Ϊ�գ�" << endl;
        return;
    }

    cout << "˫�����Ԫ��: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // ����˫����
    head = createList();

    // ����˫����
    traverseList(head);

    // ��ָ��λ�ò���ڵ�
    insertNode(head);

    // ����˫����
    traverseList(head);

    // ɾ��ָ��λ�õĽڵ�
    deleteNode(head);

    // ����˫����
    traverseList(head);

    return 0;
}

