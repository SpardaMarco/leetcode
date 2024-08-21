using namespace std;

#include <vector>
#include <string>
#include <unordered_set>

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        unordered_set<int> cols, pos_diag, neg_diag;
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        recursive(0, n, cols, pos_diag, neg_diag, board, res);
        return res;
    }

private:
    void recursive(int r, int n, unordered_set<int> &cols, unordered_set<int> &pos_diag, unordered_set<int> &neg_diag, vector<string> &board, vector<vector<string>> &res)
    {
        if (r == n)
        {
            res.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (cols.count(i) || pos_diag.count(r + i) || neg_diag.count(r - i))
                continue;
            cols.insert(i);
            pos_diag.insert(r + i);
            neg_diag.insert(r - i);

            board[r][i] = 'Q';

            recursive(r + 1, n, cols, pos_diag, neg_diag, board, res);
            cols.erase(i);
            pos_diag.erase(r + i);
            neg_diag.erase(r - i);

            board[r][i] = '.';
        }
    }
};