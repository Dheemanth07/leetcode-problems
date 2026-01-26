// Last updated: 1/26/2026, 6:29:08 PM
1class Solution {
2public:
3    vector<int> findErrorNums(vector<int>& nums) {
4        if (nums.empty())
5            return {};
6        int n=nums.size();
7        vector<int> v;
8        unordered_set<int>st;
9        for(int num:nums){
10            if(st.count(num)!=0){
11                v.push_back(num);
12                continue;
13            }
14            st.insert(num);
15        }
16
17        int osum=(n*(n+1))/2;
18        int ssum=0;
19        for(int num:st)
20            ssum+=num;
21        v.push_back(osum-ssum);
22        return v;
23    }
24};