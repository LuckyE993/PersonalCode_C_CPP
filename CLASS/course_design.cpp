//
// Created by Lucky_E on 2023-06-21.
//
#include <iostream>
#include <string>
using namespace std;

// 定义通讯录节点结构
struct ContactNode {
    string name;
    string phoneNumber;
    string qqNumber;
    string email;
    ContactNode* prev;
    ContactNode* next;
};

// 添加联系人
void addContact(ContactNode*& head, const string& name, const string& phoneNumber, const string& qqNumber, const string& email) {
    ContactNode* newNode = new ContactNode;
    newNode->name = name;
    newNode->phoneNumber = phoneNumber;
    newNode->qqNumber = qqNumber;
    newNode->email = email;

    if (head == nullptr) {
        head = newNode;
        head->prev = newNode;
        head->next = newNode;
    }
    else {
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev->next = newNode;
        head->prev = newNode;
    }
    cout << "联系人已添加：" << name << endl;
}

// 插入联系人
void insertContact(ContactNode*& head, const string& name, const string& phoneNumber, const string& qqNumber, const string& email, int position) {
    if (position <= 0) {
        cout << "无效的插入位置" << endl;
        return;
    }

    ContactNode* newNode = new ContactNode;
    newNode->name = name;
    newNode->phoneNumber = phoneNumber;
    newNode->qqNumber = qqNumber;
    newNode->email = email;

    if (head == nullptr) {
        head = newNode;
        head->prev = newNode;
        head->next = newNode;
    }
    else {
        ContactNode* current = head;
        for (int i = 1; i < position && current->next != head; i++) {
            current = current->next;
        }
        newNode->prev = current;
        newNode->next = current->next;
        current->next->prev = newNode;
        current->next = newNode;
    }
    cout << "联系人已插入：" << name << endl;
}

// 删除联系人
void deleteContact(ContactNode*& head, const string& name) {
    if (head == nullptr) {
        cout << "通讯录为空" << endl;
        return;
    }

    ContactNode* current = head;
    do {
        if (current->name == name) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            if (current == head) {
                head = current->next;
            }
            delete current;
            cout << "联系人已删除：" << name << endl;
            return;
        }
        current = current->next;
    } while (current != head);

    cout << "未找到联系人：" << name << endl;
}

// 查询联系人
void searchContact(ContactNode* head, const string& name) {
    if (head == nullptr) {
        cout << "通讯录为空" << endl;
        return;
    }

    ContactNode* current = head;
    do {
        if (current->name == name) {
            cout << "姓名：" << current->name << endl;
            cout << "手机号：" << current->phoneNumber << endl;
            cout << "QQ 号：" << current->qqNumber << endl;
            cout << "邮箱：" << current->email << endl;
            return;
        }
        current = current->next;
    } while (current != head);

    cout << "未找到联系人：" << name << endl;
}

// 统计联系人数量
int countContacts(ContactNode* head) {
    int count = 0;
    ContactNode* current = head;
    if (current == nullptr) {
        return count;
    }

    do {
        count++;
        current = current->next;
    } while (current != head);

    return count;
}

int main() {
    ContactNode* head = nullptr;
    addContact(head, "John", "123456789", "12345", "john@example.com");
    addContact(head, "Jane", "987654321", "54321", "jane@example.com");
    insertContact(head, "Alice", "111111111", "11111", "alice@example.com", 2);
    searchContact(head, "John");
    deleteContact(head, "Jane");
    cout << "联系人数量：" << countContacts(head) << endl;

    return 0;
}
