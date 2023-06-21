//
// Created by Lucky_E on 2023-06-21.
//
#include <iostream>
#include <string>
using namespace std;

// ����ͨѶ¼�ڵ�ṹ
struct ContactNode {
    string name;
    string phoneNumber;
    string qqNumber;
    string email;
    ContactNode* prev;
    ContactNode* next;
};

// ����ͨѶ¼��
class ContactList {
public:
    ContactList() {
        head = nullptr;
    }

    // �����ϵ��
    void addContact(const string& name, const string& phoneNumber, const string& qqNumber, const string& email) {
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
        cout << "��ϵ������ӣ�" << name << endl;
    }

    // ������ϵ��
    void insertContact(const string& name, const string& phoneNumber, const string& qqNumber, const string& email, int position) {
        if (position <= 0) {
            cout << "��Ч�Ĳ���λ��" << endl;
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
        cout << "��ϵ���Ѳ��룺" << name << endl;
    }

    // ɾ����ϵ��
    void deleteContact(const string& name) {
        if (head == nullptr) {
            cout << "ͨѶ¼Ϊ��" << endl;
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
                cout << "��ϵ����ɾ����" << name << endl;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "δ�ҵ���ϵ�ˣ�" << name << endl;
    }

    // ��ѯ��ϵ��
    void searchContact(const string& name) {
        if (head == nullptr) {
            cout << "ͨѶ¼Ϊ��" << endl;
            return;
        }

        ContactNode* current = head;
        do {
            if (current->name == name) {
                cout << "������" << current->name << endl;
                cout << "�ֻ��ţ�" << current->phoneNumber << endl;
                cout << "QQ �ţ�" << current->qqNumber << endl;
                cout << "���䣺" << current->email << endl;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "δ�ҵ���ϵ�ˣ�" << name << endl;
    }

    // ͳ����ϵ������
    int countContacts() {
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

private:
    ContactNode* head;
};

int main() {
    ContactList contacts;
    contacts.addContact("John", "123456789", "12345", "john@example.com");
    contacts.addContact("Jane", "987654321", "54321", "jane@example.com");
    contacts.insertContact("Alice", "111111111", "11111", "alice@example.com", 2);
    contacts.searchContact("John");
    contacts.deleteContact("Jane");
    cout << "��ϵ��������" << contacts.countContacts() << endl;

    return 0;
}
