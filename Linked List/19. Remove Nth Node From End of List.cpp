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
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *prev = nullptr;
        ListNode *slow = head;
        ListNode *fast = head->next;

        for (int i = 1; i < n; i++)
            fast = fast->next;
        while (fast != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (prev)
        {
            prev->next = slow->next;
            return head;
        }
        else
        {
            return slow->next;
        }
    }
};