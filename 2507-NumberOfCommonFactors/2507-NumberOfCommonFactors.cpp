// Last updated: 6/22/2026, 6:29:15 PM
class Solution {
public:
    int commonFactors(int a, int b) {
        int count=0,lim=min(a,b);
        for(auto i=1;i<=lim;i++){
            if(a%i==0 && b%i==0)
                count++;
        }
    return count;

    }
};