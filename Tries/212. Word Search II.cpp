using namespace std;

#include <string>
#include <vector>
#include <unordered_set>

class Node
{
public:
    bool value;
    Node *edges[26] = {nullptr};
    int ref = 0;

    Node()
    {
        value = false;
    }

    Node(bool val) : value(val) {}
};

class Trie
{
public:
    Node *head;
    Trie()
    {
        head = new Node();
    }

    void addWord(string word)
    {
        Node *curr = head;
        curr->ref++;
        for (const char &c : word)
        {
            Node *next = curr->edges[c - 'a'];
            if (!next)
            {
                curr->edges[c - 'a'] = new Node();
                curr = curr->edges[c - 'a'];
            }
            else
                curr = next;
            curr->ref++;
        }
        curr->value = true;
    }

    void removeWord(string word)
    {
        Node *curr = head;
        curr->ref--;
        for (const char &c : word)
        {
            curr = curr->edges[c - 'a'];
            curr->ref--;
        }
    }
};

class Solution
{
private:
    int rows;
    int cols;
    void dfs(int i, int j, vector<vector<char>> &board, Node *curr, string word, unordered_set<string> &res, unordered_set<string> &visit, Trie &t)
    {
        if (i < 0 || i >= this->rows || j < 0 || j >= this->cols || visit.count(to_string(i) + '|' + to_string(j)) != 0 || !curr->edges[board[i][j] - 'a'] || curr->edges[board[i][j] - 'a']->ref <= 0)
            return;
        char c = board[i][j];
        string coord = to_string(i) + '|' + to_string(j);
        visit.insert(coord);
        word = word + c;
        curr = curr->edges[c - 'a'];
        if (curr->value)
        {
            curr->value = false;
            res.insert(word);
            t.removeWord(word);
        }
        dfs(i + 1, j, board, curr, word, res, visit, t);
        dfs(i - 1, j, board, curr, word, res, visit, t);
        dfs(i, j + 1, board, curr, word, res, visit, t);
        dfs(i, j - 1, board, curr, word, res, visit, t);
        visit.erase(coord);
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie t = Trie();
        for (string w : words)
            t.addWord(w);

        unordered_set<string> res;
        unordered_set<string> visit;
        this->rows = board.size();
        this->cols = board[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                dfs(i, j, board, t.head, "", res, visit, t);
            }
        }
        return vector(res.begin(), res.end());
    }
};