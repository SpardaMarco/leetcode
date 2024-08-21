using namespace std;

#include <vector>
#include <string>

class Solution
{
    int ROWS;
    int COLS;

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        this->ROWS = board.size();
        this->COLS = board[0].size();
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (dfs(board, word, i, j))
                    return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, string word, int row, int col)
    {
        if (word.empty())
            return true;
        if (row < 0 || row >= this->ROWS || col < 0 || col >= this->COLS || board[row][col] != word[0])
            return false;
        char original = board[row][col];
        board[row][col] = '.';
        if (dfs(board, word.substr(1, word.size() - 1), row + 1, col))
            return true;
        if (dfs(board, word.substr(1, word.size() - 1), row - 1, col))
            return true;
        if (dfs(board, word.substr(1, word.size() - 1), row, col + 1))
            return true;
        if (dfs(board, word.substr(1, word.size() - 1), row, col - 1))
            return true;
        board[row][col] = original;
        return false;
    }
};