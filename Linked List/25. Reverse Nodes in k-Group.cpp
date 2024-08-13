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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next;
        if (curr == nullptr)
            return curr;
        while (curr->next != nullptr)
        {
            next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        curr->next = prev;
        return curr;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;

        for (int i = 1; i < k; i++)
        {
            fast = fast->next;
            if (fast == nullptr)
                return head;
        }
        ListNode *next_slow = fast->next;
        ListNode *prev_slow = slow;
        fast->next = nullptr;
        head = reverseList(slow);
        slow->next = next_slow;
        slow = next_slow;
        fast = next_slow;
        while (slow != nullptr)
        {
            for (int i = 1; i < k; i++)
            {
                fast = fast->next;
                if (fast == nullptr)
                    return head;
            }
            ListNode *next_slow = fast->next;
            fast->next = nullptr;
            prev_slow->next = reverseList(slow);
            slow->next = next_slow;
            prev_slow = slow;
            slow = next_slow;
            fast = next_slow;
        }
        return head;
    }
};