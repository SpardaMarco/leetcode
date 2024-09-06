using namespace std;

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

class Solution {
   public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        vector<int> mult(num1.size() + num2.size(), 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                int digit = (num1[i] - '0') * (num2[j] - '0');
                mult[i + j] += digit;
                mult[i + j + 1] += mult[i + j] / 10;
                mult[i + j] %= 10;
            }
        }

        stringstream ss;
        int i = mult.size() - 1;
        while (mult[i] == 0) {
            --i;
        }
        while (i >= 0) {
            ss << mult[i--];
        }
        return ss.str();
    }
};