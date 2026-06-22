// Last updated: 6/22/2026, 6:28:59 PM
class Solution {
public:
    int countKeyChanges(string s) {
        if (s.empty()) return 0;
        int count=0;
        for(auto i=0;i<s.length()-1;i++){
            if(tolower(s[i])!=tolower(s[i+1]))
                count++;
        }
        return count;
    }
};