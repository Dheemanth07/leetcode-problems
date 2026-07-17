// Last updated: 7/17/2026, 2:02:14 PM
class Solution {
public:
    string toLowerCase(string s) {
        for(char &c:s)
            if(isupper(c))
                c=tolower(c);
        return s;
    }
};