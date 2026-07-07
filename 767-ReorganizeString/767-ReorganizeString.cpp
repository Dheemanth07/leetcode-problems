// Last updated: 7/7/2026, 11:59:05 AM
1class Solution {
2public:
3    string reorganizeString(string s) {
4        // 1. Count frequencies
5        unordered_map<char, int> counts;
6        for (char c : s)
7            counts[c]++;
8
9        // 2. Max-Heap to store pairs of {count, character}
10        priority_queue<pair<int, char>> maxHeap;
11        for (auto& pair : counts)
12            maxHeap.push({pair.second, pair.first});
13
14        string result = "";
15
16        // 3. The "On-Deck Circle": A single variable to act as our n=1
17        // cooldown! We initialize it with a dummy count of -1.
18        pair<int, char> prev = {-1, '#'};
19
20        while (!maxHeap.empty()) {
21            // Get the most frequent available character
22            auto current = maxHeap.top();
23            maxHeap.pop();
24
25            // Add it to our string and decrement its required count
26            result += current.second;
27            current.first--;
28
29            // If the PREVIOUS character is rested and still needs to be placed,
30            // put it back onto the bench (the Max-Heap)!
31            if (prev.first > 0)
32                maxHeap.push(prev);
33
34            // The CURRENT character just swung. Send it to the On-Deck Circle
35            // to rest.
36            prev = current;
37        }
38
39        // If we finished the heap, but our result isn't the length of the
40        // original string, it means a character got stuck in the 'prev'
41        // variable with nowhere to go!
42        if (result.length() != s.length())
43            return "";
44
45        return result;
46    }
47};