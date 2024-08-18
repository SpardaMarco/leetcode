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

class WordDictionary
{
private:
    Node *head;

    bool dfs(string word, int j, Node *root)
    {
        for (int i = j; i < word.size(); i++)
        {
            const char c = tolower(word[i]);
            if (c == '.')
            {
                for (int k = 0; k < 26; k++)
                {
                    if (root->edges[k] && dfs(word, i + 1, root->edges[k]))
                        return true;
                }
                return false;
            }
            else
            {
                Node *next = root->edges[c - 'a'];
                if (!next)
                {
                    return false;
                }
                else
                    root = next;
            }
        }
        return root->value;
    }

public:
    WordDictionary()
    {
        head = new Node();
    }

    void addWord(string word)
    {
        Node *curr = head;
        for (const char &c : word)
        {
            const char new_c = tolower(c);
            Node *next = curr->edges[new_c - 'a'];
            if (!next)
            {
                curr->edges[new_c - 'a'] = new Node();
                curr = curr->edges[new_c - 'a'];
            }
            else
                curr = next;
        }
        curr->value = true;
    }

    bool search(string word)
    {
        return dfs(word, 0, head);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */