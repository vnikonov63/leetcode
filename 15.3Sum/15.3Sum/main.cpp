#include <iostream>
#include <set>
#include <vector>

#include "test_runner.h"

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) {
        return {};
    }
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    
    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            int j = i + 1;
            int k = static_cast<int>(nums.size()) - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    result.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j-1]) {
                        j++;
                    }
                }
            }
        }
    }
    
    return result;
}

vector<vector<int>> threeSumSet(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        set<vector<int>> result = {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1;
            int k = static_cast<int>(nums.size()) - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    result.insert({nums[i], nums[j], nums[k]});
                    k--;
                }
            }
        }
        return {result.begin(), result.end()};
    }

void Test() {
    vector<int> input1 = {-1,0,1,2,-1,-4};
    
    vector<vector<int>> expected1 = {{-1,-1,2},{-1,0,1}};
    
    ASSERT_EQUAL(threeSumSet(input1), expected1);
    ASSERT_EQUAL(threeSum(input1), expected1);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
    
    return 0;
}
