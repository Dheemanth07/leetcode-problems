// Last updated: 6/22/2026, 6:29:02 PM
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> v;
        int i=0;
        for(auto s:words){
            for(auto c:s)
                if(x==c){
                    v.push_back(i);
                    break;
                }
            i++;
        }
        return v;
    }
};