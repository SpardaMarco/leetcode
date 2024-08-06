using namespace std;
#include <vector>
#include <string>
#include <stack>

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> my_stack;
        for (string s : tokens)
        {
            if (s == "+")
            {
                int second_op = my_stack.top();
                my_stack.pop();
                int first_op = my_stack.top();
                my_stack.pop();
                my_stack.push(first_op + second_op);
            }
            else if (s == "-")
            {
                int second_op = my_stack.top();
                my_stack.pop();
                int first_op = my_stack.top();
                my_stack.pop();
                my_stack.push(first_op - second_op);
            }
            else if (s == "*")
            {
                int second_op = my_stack.top();
                my_stack.pop();
                int first_op = my_stack.top();
                my_stack.pop();
                my_stack.push(first_op * second_op);
            }
            else if (s == "/")
            {
                int second_op = my_stack.top();
                my_stack.pop();
                int first_op = my_stack.top();
                my_stack.pop();
                my_stack.push(first_op / second_op);
            }
            else
            {
                my_stack.push(stoi(s));
            }
        }
        return my_stack.top();
    }
};