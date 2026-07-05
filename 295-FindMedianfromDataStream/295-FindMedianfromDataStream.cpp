// Last updated: 7/5/2026, 8:02:06 PM
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
13        if (leftMax.size() > rightMin.size() + 1) {
14            rightMin.push(leftMax.top());
15            leftMax.pop();
16        } else if (rightMin.size() > leftMax.size()) {
17            leftMax.push(rightMin.top());
18            rightMin.pop();
19        }
20    }
21
22    double findMedian() {
23        if (leftMax.size() == rightMin.size())
24            return (leftMax.top() + rightMin.top()) / 2.0;
25        else
26            return leftMax.top();
27    }
28};
29
30/**
31 * Your MedianFinder object will be instantiated and called as such:
32 * MedianFinder* obj = new MedianFinder();
33 * obj->addNum(num);
34 * double param_2 = obj->findMedian();
35 */