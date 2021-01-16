#include <iostream>
#include <vector>

#include "test_runner.h"

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v (2, 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    v[0] = i;
                    v[1] = j;
                    return v;
                }
            }
        }
        return v;
    }

void Test() {
    vector<int> v = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> answer = {0, 1};
    
    ASSERT_EQUAL(twoSum(v, target),answer);
    
}

int main() {
    TestRunner tr;
      RUN_TEST(tr, Test);
    return 0;
}
