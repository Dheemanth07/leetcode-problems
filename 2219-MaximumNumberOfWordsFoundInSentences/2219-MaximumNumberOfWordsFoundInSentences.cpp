// Last updated: 6/22/2026, 6:29:23 PM
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxw=0;
        for(const string& s:sentences){
            int wordcount=count(s.begin(),s.end(),' ')+1;
            maxw=max(maxw,wordcount);
        }
        return maxw;
    }
};