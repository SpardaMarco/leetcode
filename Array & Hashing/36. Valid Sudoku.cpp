using namespace std;
#include <vector>

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int table[27][9] = {{0}};
        for (int i = 0; i < 9; i++)
        {
            int aux = i / 3 * 3;
            for (int j = 0; j < 9; j++)
            {
                char value = board[i][j];
                if (value == '.')
                    continue;
                int index = value - '1';
                int box_index = aux + j / 3;
                if (++table[i][index] > 1)
                    return false;
                if (++table[9 + j][index] > 1)
                    return false;
                if (++table[box_index + 18][index] > 1)
                    return false;
            }
        }
        return true;
    }
};