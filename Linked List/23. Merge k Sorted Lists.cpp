using namespace std;

#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        else if (!l2)
            return l1;

        ListNode *head;
        ListNode *curr;
        if (l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }
        curr = head;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            }
        }
        if (l1)
            curr->next = l1;
        else
            curr->next = l2;
        return head;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        else if (lists.size() == 2)
        {
            return mergeTwoLists(lists[0], lists[1]);
        }
        else
        {
            int size = lists.size();
            while (size > 1)
            {
                for (int i = 0; i < size / 2; i++)
                {
                    lists[i] = mergeTwoLists(lists[i], lists[size - i - 1]);
                }
                size = (size + 1) / 2;
            }
        }
        return lists[0];
    }
};