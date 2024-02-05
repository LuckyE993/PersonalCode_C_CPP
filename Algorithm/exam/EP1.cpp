#include <iostream>

using namespace std;

// 定义链表节点结构体
struct ListNode
{
    int val;
    ListNode* next;
};

// 创建一个新节点并插入到链表末尾
void insert(ListNode*& head, int val)
{
    ListNode* newNode = new ListNode;
    newNode->val = val;
    newNode->next = nullptr;
    //如果链表为空，将新节点作为链表的头节点
    if (head == nullptr)
    {
        head = newNode;
    }
    else//遍历到链表的最后一个节点，将新节点插入到最后一个节点的next指针上。
    {
        ListNode* curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// 合并两个有序链表为一个有序链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{

    ListNode* temp = new ListNode;//临时头结点

    ListNode* curr = temp;//定义一个当前指针变量

    while (l1 != nullptr && l2 != nullptr)//二者有一个到头跳出
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

    // 处理剩余的节点
    if (l1 != nullptr)
    {
        curr->next = l1;
    }
    if (l2 != nullptr)
    {
        curr->next = l2;
    }

    ListNode* mergedList = temp->next;

    return mergedList;//返回合并有序链表
}

// 打印链表
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
    // 创建两个有序链表
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;

    int n1, n2;
    cout << "输入第一个有序表元素个数: " << endl;
    cin >> n1;
    cout << "依次输入第一个有序表元素" << endl;
    for (int i = 0; i < n1; ++i)
    {
        int val;
        cin >> val;
        insert(l1, val);
    }

    cout << "输入第二个有序表元素个数: " << endl;
    cin >> n2;
    cout << "依次输入第二个有序表元素" << endl;
    for (int i = 0; i < n2; ++i)
    {
        int val;
        cin >> val;
        insert(l2, val);
    }

    ListNode* MergedList = mergeTwoLists(l1, l2);
    cout << "合并后的有序链表为：";
    printList(MergedList);
}
