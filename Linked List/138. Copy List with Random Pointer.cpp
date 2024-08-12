#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        unordered_map<Node *, Node *> aux;
        Node *new_head = new Node(head->val);
        Node *curr = head;
        Node *new_curr = new_head;
        aux[head] = new_head;

        while (curr != nullptr)
        {
            if (curr->next)
            {
                if (aux.find(curr->next) == aux.end())
                    aux[curr->next] = new Node(curr->next->val);
                new_curr->next = aux[curr->next];
            }
            if (curr->random)
            {
                if (aux.find(curr->random) == aux.end())
                    aux[curr->random] = new Node(curr->random->val);
                new_curr->random = aux[curr->random];
            }
            curr = curr->next;
            new_curr = new_curr->next;
        }

        return new_head;
    }
};