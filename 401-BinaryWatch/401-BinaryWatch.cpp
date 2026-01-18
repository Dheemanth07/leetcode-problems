// Last updated: 1/18/2026, 6:52:42 PM
1class Solution {
2public:
3    vector<string> readBinaryWatch(int turnedOn) {
4        vector<string>res;
5        for(int hour=0;hour<12;hour++){
6            for(int minute=0;minute<60;minute++){
7                int setBits=__builtin_popcount(hour) + __builtin_popcount(minute);
8                if(setBits==turnedOn){
9                    string time=to_string(hour)+":";
10                    if(minute<10)
11                        time+="0";
12                    time+=to_string(minute);
13                    res.push_back(time);
14                }
15            }
16        }
17        return res;
18    }
19};