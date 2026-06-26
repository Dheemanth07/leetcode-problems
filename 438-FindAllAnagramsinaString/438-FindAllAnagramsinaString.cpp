// Last updated: 6/26/2026, 10:34:24 AM
1class Solution {
2public:
3    vector<int> findAnagrams(string s, string p) {
4        int n1 = s.length();
5        int n2 = p.length();
6
7        // Edge case: If the pattern is longer than the text, an anagram is
8        // impossible. We compare the lengths (n2 > n1), NOT the strings
9        // lexicographically!
10        if (n2 > n1)
11            return {};
12
13        // Create two frequency arrays of size 26 for lowercase English letters.
14        // freq1 tracks our current window in 's'. freq2 is our target blueprint
15        // from 'p'.
16        vector<int> freq1(26, 0);
17        vector<int> freq2(26, 0);
18        vector<int> res;
19
20        // ==========================================
21        // PHASE 1: Populate Blueprint and Initial Window
22        // ==========================================
23        for (int i = 0; i < n2; i++) {
24            freq1[s[i] - 'a']++; // Build the first window of size n2
25            freq2[p[i] - 'a']++; // Build the static blueprint
26        }
27
28        // ==========================================
29        // PHASE 2: Check the First Window (Index 0)
30        // ==========================================
31        // In C++, comparing two vectors of the same size checks their elements.
32        // Because the size is always 26, this is mathematically an O(1)
33        // operation!
34        if (freq1 == freq2)
35            res.push_back(0);
36
37        // ==========================================
38        // PHASE 3: The Glide (Sliding Window)
39        // ==========================================
40        int left = 0;
41
42        // The 'right' pointer starts exactly where our initial window left off.
43        for (int right = n2; right < n1; right++) {
44
45            // 1. Add the incoming character on the right to our window
46            freq1[s[right] - 'a']++;
47
48            // 2. Remove the outgoing character on the left from our window
49            freq1[s[left] - 'a']--;
50
51            // 3. Move the left boundary of our window forward by 1
52            left++;
53
54            // 4. Check if our newly shifted window is an exact match!
55            if (freq1 == freq2)
56                res.push_back(left);
57        }
58
59        return res;
60    }
61};