using namespace std;

#include <vector>
#include <unordered_set>

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int ROWS = board.size();
        int COLS = board[0].size();
        unordered_set<int> visited;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                int coord = i * COLS + j;
                if (board[i][j] == 'O' && !visited.count(coord))
                {
                    if (sorrounded(i, j, board, visited))
                    {
                        paint(i, j, board);
                    }
                }
            }
        }
    }

private:
    bool sorrounded(int i, int j, vector<vector<char>> &board, unordered_set<int> &visited)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if (board[i][j] == 'X')
            return true;
        int coord = i * board[0].size() + j;
        if (visited.count(coord))
            return true;

        visited.insert(coord);

        bool right = sorrounded(i + 1, j, board, visited);
        bool left = sorrounded(i - 1, j, board, visited);
        bool up = sorrounded(i, j - 1, board, visited);
        bool down = sorrounded(i, j + 1, board, visited);
        return right && left && up && down;
    }

    void paint(int i, int j, vector<vector<char>> &board)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 'X')
            return;
        board[i][j] = 'X';
        paint(i + 1, j, board);
        paint(i - 1, j, board);
        paint(i, j + 1, board);
        paint(i, j - 1, board);
    }
};