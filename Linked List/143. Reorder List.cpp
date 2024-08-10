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
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;
        int i = 0;
        ListNode *slow = head, *fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *head2 = slow->next;
        slow->next = nullptr;

        ListNode *prev = nullptr;
        ListNode *next;
        while (head2->next != nullptr)
        {
            next = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = next;
        }
        head2->next = prev;
        slow = head;
        while (slow != nullptr)
        {
            next = slow->next;
            slow->next = head2;

            if (head2 != nullptr)
            {
                head2 = head2->next;
                slow->next->next = next;
            }
            slow = next;
        }
    }
};
