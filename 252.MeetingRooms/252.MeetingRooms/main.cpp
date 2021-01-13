#include <iostream>
#include <vector>

using namespace std;

bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs[0] < rhs[0];
        });
        
        int buffer = -1;
        for (const auto& el : intervals) {
            if (buffer > el[0]) {
                return false;
            }
            buffer = el[1];
        }
        return true;
    }

int main() {
    vector<vector<int>> input1 = {{0,30},{5,10},{15,20}};
    vector<vector<int>> input2 = {{7,10},{2,4}};
    
    cout << boolalpha << (canAttendMeetings(input1) == false) << endl;
    cout << boolalpha << (canAttendMeetings(input2) == true) << endl;
    return 0;
}
