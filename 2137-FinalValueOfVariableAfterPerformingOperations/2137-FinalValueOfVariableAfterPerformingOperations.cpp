// Last updated: 6/22/2026, 6:29:28 PM
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        if(operations.empty()) return 0;
        int count=0;
        for (const string& op : operations) {
            if(op=="++X" || op=="X++")
                count++;
            else if(op=="--X" || op=="X--")
                count--;
        }
        return count;
    }
};