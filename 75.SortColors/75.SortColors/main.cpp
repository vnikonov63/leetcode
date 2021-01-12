#include <iostream>
#include <vector>
#include <algorithm>
#include <ostream>

using namespace std;

// This is the fancy Dutch Flag problem technique

ostream& operator << (ostream& os, vector<int> v) {
    for (int i =0; i < v.size(); ++i) {
        os << v[i] << " ";
    }
    return os;
}


void sortColors(vector<int>& nums) {
    int afterzero = 0;
        int current = 0;
        int beforetwo = static_cast<int>(nums.size()) - 1;
    
        int step = 0;
        
        while (current <= beforetwo) {
            cout << "At step " << step << " the vector is " << nums << endl;
            if (nums[current] == 0) {
                swap(nums[afterzero], nums[current]);
                current++;
                afterzero++;
            } else if (nums[current] == 1) {
                current++;
            } else {
                swap(nums[beforetwo], nums[current]);
                --beforetwo;
            }
            step++;
        }
    
}

int main() {
    vector<int> myVector = {2, 0, 2, 1, 1, 0};
    cout << "Before: " << myVector << endl;
    sortColors(myVector);
    cout << "After: " << myVector << endl;
    return 0;
}
