using namespace std;
#include <string>

class Node
{
public:
    bool value;
    Node *edges[26] = {nullptr};

    Node()
    {
        value = false;
    }

    Node(bool val) : value(val) {}
};

class Trie
{
private:
    Node *head;
    void insert(string word, Node *curr)
    {
        while (word.size() != 1)
        {
            char c = tolower(word[0]);
            Node *next = curr->edges[c - 'a'];
            if (!next)
            {
                curr->edges[c - 'a'] = new Node();
                next = curr->edges[c - 'a'];
            }
            word = word.substr(1, word.size() - 1);
            curr = next;
        }
        char c = tolower(word[0]);
        Node *next = curr->edges[c - 'a'];
        if (!next)
        {
            curr->edges[c - 'a'] = new Node(true);
        }
        else
        {
            next->value = true;
        }
    }
    bool search(string word, Node *curr)
    {
        while (word.size() != 1 && curr != nullptr)
        {
            char c = tolower(word[0]);
            curr = curr->edges[c - 'a'];
            word = word.substr(1, word.size() - 1);
        }
        if (!curr)
            return false;
        char c = tolower(word[0]);
        Node *next = curr->edges[c - 'a'];
        return next && next->value;
    }
    bool startsWith(string word, Node *curr)
    {
        while (word.size() != 1 && curr != nullptr)
        {
            char c = tolower(word[0]);
            curr = curr->edges[c - 'a'];
            word = word.substr(1, word.size() - 1);
        }
        if (!curr)
            return false;
        char c = tolower(word[0]);
        Node *next = curr->edges[c - 'a'];
        return next;
    }

public:
    Trie()
    {
        head = new Node();
    }

    void insert(string word)
    {
        insert(word, head);
    }

    bool search(string word)
    {
        return search(word, head);
    }

    bool startsWith(string prefix)
    {
        return startsWith(prefix, head);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */