#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i : nums) {
            if (map.find(i) != map.end()){
                return true;
            }
            map.insert({i, 1});
        }
        return false;
    }
};

int main () {
    vector<int> test1 = {1,2,3,2};
    vector<int> test2 = {1,2,3,4};
    vector<int> test3 = {1,1,1,3,3,4,3,2,4,2};
    Solution solver = Solution();

    cout << "Test 1 - Expected: " << true << " Received: " << solver.containsDuplicate(test1) << endl;
    cout << "Test 2 - Expected: " << false << " Received: " << solver.containsDuplicate(test2) << endl;
    cout << "Test 3 - Expected: " << true << " Received: " << solver.containsDuplicate(test3) << endl;
    return 0;
}