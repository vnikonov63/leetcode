#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    for (int i = 0; i < intervals.size(); ++i) {
        if (intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
        }
    }
    return {{}};
}

int main() {
    vector<vector<int>> test1Left = {{1, 3}, {6, 9}};
    vector<int> test1Right = {2, 5};
    
    vector<vector<int>> test1Result = {{1, 5},{6, 9}};
    return 0;
}
