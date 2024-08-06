using namespace std;
#include <string>

#include <stack>

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> my_stack;

        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                my_stack.push(c);
            else
            {
                if (my_stack.empty())
                    return false;
                else if (c == ')' && (c - my_stack.top()) != 1)
                    return false;
                else if (c != ')' && (c - my_stack.top()) != 2)
                    return false;
                else
                    my_stack.pop();
            }
        }
        return my_stack.empty();
    }
};