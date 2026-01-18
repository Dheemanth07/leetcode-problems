// Last updated: 1/18/2026, 12:22:35 PM
1class MedianFinder {
2    priority_queue<int, vector<int>> leftMax;
3    priority_queue<int, vector<int>, greater<int>> rightMin;
4
5public:
6    MedianFinder() {}
7
8    void addNum(int num) { 
9        if (leftMax.empty() || num < leftMax.top()) 
10            leftMax.push(num);
11        else
12            rightMin.push(num);
13        if(leftMax.size()>rightMin.size()+1){
14            rightMin.push(leftMax.top());
15            leftMax.pop();
16        }
17        else if(rightMin.size()>leftMax.size()){
18            leftMax.push(rightMin.top());
19            rightMin.pop();
20        }
21    }
22
23    double findMedian() {
24        if(leftMax.size()==rightMin.size())
25            return (leftMax.top()+rightMin.top())/2.0;
26        else
27            return leftMax.top();
28    }
29};
30
31/**
32 * Your MedianFinder object will be instantiated and called as such:
33 * MedianFinder* obj = new MedianFinder();
34 * obj->addNum(num);
35 * double param_2 = obj->findMedian();
36 */
