//
// Created by Lucky_E on 2023-06-21.
//
#include <iostream>
#include <string>
#include <regex>

using namespace std;

/**
 *@brief  �ֻ���������֤
 *
 * @param[in] phoneNumber �ֻ���
 *
 * @return none
 */
bool isValidPhoneNumber(const string& phoneNumber) {
    regex pattern("^\\d{11}$");
    return regex_match(phoneNumber, pattern);
}

/**
 *@brief  ����������֤
 *
 * @param[in] email �����ַ
 *
 * @return none
 */
bool isValidEmail(const string& email) {
    regex pattern("^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$");
    return regex_match(email, pattern);
}


/**
 *@brief  ����ͨѶ¼�ڵ�ṹ
 *
 * @param[in] none
 *
 * @return none
 */
struct ContactNode {
    string name;
    string phoneNumber;
    string qqNumber;
    string email;
    ContactNode* prev;
    ContactNode* next;
};

/**
 * @brief �����ϵ��
 *
 * @param[in] head ͷ�ڵ�ָ��
 * @param[in] name ��ϵ������
 * @param[in] phoneNumber ��ϵ���ֻ���
 * @param[in] qqNumber ��ϵ��QQ��
 * @param[in] email ��ϵ������
 *
 * @return none
 */
void addContact(ContactNode*& head, const string& name, const string& phoneNumber, const string& qqNumber,
                const string& email) {
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

/**
 * @brief ������ϵ��
 *
 * @param[in] head ͷ�ڵ�ָ��
 * @param[in] name ��ϵ������
 * @param[in] phoneNumber ��ϵ���ֻ���
 * @param[in] qqNumber ��ϵ��QQ��
 * @param[in] email ��ϵ������
 * @param[in] position ����λ��
 *
 * @return none
 */
void insertContact(ContactNode*& head, const string& name, const string& phoneNumber, const string& qqNumber,
                   const string& email, int position) {
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

/**
 * @brief ɾ����ϵ��
 *
 * @param[in] head ͷ�ڵ�ָ��
 * @param[in] name ��ϵ������
 *
 * @return none
 */
void deleteContact(ContactNode*& head, const string& name) {
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

/**
 * @brief ��ѯ��ϵ��
 *
 * @param[in] head ͷ�ڵ�ָ��
 * @param[in] name ��ϵ������
 *
 * @return none
 */
void searchContact(ContactNode* head, const string& searchQuery) {
    if (head == nullptr) {
        cout << "ͨѶ¼Ϊ��" << endl;
        return;
    }

    ContactNode* current = head;
    do {
        if (current->name == searchQuery ||
            current->phoneNumber == searchQuery ||
            current->qqNumber == searchQuery ||
            current->email == searchQuery) {
            cout << "������" << current->name << endl;
            cout << "�ֻ��ţ�" << current->phoneNumber << endl;
            cout << "QQ �ţ�" << current->qqNumber << endl;
            cout << "���䣺" << current->email << endl;
            return;
        }
        current = current->next;
    } while (current != head);

    cout << "δ�ҵ�ƥ�����ϵ�ˣ�" << searchQuery << endl;
}


/**
 * @brief ͳ����ϵ������
 *
 * @param[in] head ͷ�ڵ�ָ��
 *
 * @return ��ϵ������
 */
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

void printMenu() {
    cout << "========================" << endl;
    cout << "ͨѶ¼����ϵͳ" << endl;
    cout << "1. �����ϵ��" << endl;
    cout << "2. ������ϵ��" << endl;
    cout << "3. ɾ����ϵ��" << endl;
    cout << "4. ��ѯ��ϵ��" << endl;
    cout << "5. ͳ����ϵ������" << endl;
    cout << "0. �˳�" << endl;
    cout << "========================" << endl;
    cout << "���������ѡ�";
}

int main() {
    ContactNode* head = nullptr;
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, phoneNumber, qqNumber, email;
                cout << "��������ϵ��������";
                cin >> name;

                cout << "��������ϵ���ֻ��ţ�";
                cin >> phoneNumber;
                while (!isValidPhoneNumber(phoneNumber)) {
                    cout << "��Ч���ֻ��Ÿ�ʽ,���������롣" << endl;
                    cin >> phoneNumber;
                }

                cout << "��������ϵ��QQ�ţ�";
                cin >> qqNumber;

                cout << "��������ϵ�����䣺";
                cin >> email;
                while(!isValidEmail(email)) {
                    cout << "��Ч�������ʽ,���������롣" << endl;
                    cin >> email;
                }

                addContact(head, name, phoneNumber, qqNumber, email);
                break;
            }
            case 2: {
                string name, phoneNumber, qqNumber, email;
                int position;
                cout << "��������ϵ��������";
                cin >> name;
                cout << "��������ϵ���ֻ��ţ�";
                cin >> phoneNumber;
                cout << "��������ϵ��QQ�ţ�";
                cin >> qqNumber;
                cout << "��������ϵ�����䣺";
                cin >> email;

                if (!isValidPhoneNumber(phoneNumber)) {
                    cout << "��Ч���ֻ��Ÿ�ʽ" << endl;
                    break;
                }

                if (!isValidEmail(email)) {
                    cout << "��Ч�������ʽ" << endl;
                    break;
                }

                cout << "���������λ�ã�";
                cin >> position;
                insertContact(head, name, phoneNumber, qqNumber, email, position);
                break;
            }
            case 3: {
                string name;
                cout << "������Ҫɾ������ϵ��������";
                cin >> name;
                deleteContact(head, name);
                break;
            }
            case 4: {
                string name;
                cout << "������Ҫ��ѯ����ϵ����Ϣ���������ֻ��š�QQ�š����䣩��";
                cin >> name;
                searchContact(head, name);
                break;
            }
            case 5: {
                cout << "��ϵ��������" << countContacts(head) << endl;
                break;
            }
            case 0: {
                cout << "���˳�ͨѶ¼����ϵͳ" << endl;
                break;
            }
            default:
                cout << "��Ч��ѡ��" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}