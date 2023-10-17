#include <iostream>

using namespace std;

// ��������ڵ�ṹ��
struct ListNode
{
    int val;
    ListNode* next;
};

// ����һ���½ڵ㲢���뵽����ĩβ
void insert(ListNode*& head, int val)
{
    ListNode* newNode = new ListNode;
    newNode->val = val;
    newNode->next = nullptr;
    //�������Ϊ�գ����½ڵ���Ϊ�����ͷ�ڵ�
    if (head == nullptr)
    {
        head = newNode;
    }
    else//��������������һ���ڵ㣬���½ڵ���뵽���һ���ڵ��nextָ���ϡ�
    {
        ListNode* curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// �ϲ�������������Ϊһ����������
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{

    ListNode* temp = new ListNode;//��ʱͷ���

    ListNode* curr = temp;//����һ����ǰָ�����

    while (l1 != nullptr && l2 != nullptr)//������һ����ͷ����
    {
        if (l1->val <= l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    // ����ʣ��Ľڵ�
    if (l1 != nullptr)
    {
        curr->next = l1;
    }
    if (l2 != nullptr)
    {
        curr->next = l2;
    }

    ListNode* mergedList = temp->next;

    return mergedList;//���غϲ���������
}

// ��ӡ����
void printList(ListNode* head)
{
    ListNode* curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    // ����������������
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;

    int n1, n2;
    cout << "�����һ�������Ԫ�ظ���: " << endl;
    cin >> n1;
    cout << "���������һ�������Ԫ��" << endl;
    for (int i = 0; i < n1; ++i)
    {
        int val;
        cin >> val;
        insert(l1, val);
    }

    cout << "����ڶ��������Ԫ�ظ���: " << endl;
    cin >> n2;
    cout << "��������ڶ��������Ԫ��" << endl;
    for (int i = 0; i < n2; ++i)
    {
        int val;
        cin >> val;
        insert(l2, val);
    }

    ListNode* MergedList = mergeTwoLists(l1, l2);
    cout << "�ϲ������������Ϊ��";
    printList(MergedList);
}
