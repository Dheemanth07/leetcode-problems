// Last updated: 5/7/2026, 8:18:32 AM
1class Solution {
2public:
3    vector<int> asteroidCollision(vector<int>& asteroids) {
4        vector<int> stack; // We can use a vector as a stack for easier return
5                           // formatting
6
7        for (int incoming : asteroids) {
8            bool destroyed = false;
9
10            // We only care about collisions if:
11            // 1. We have an incoming left-mover (incoming < 0)
12            // 2. The stack has survivors
13            // 3. The top survivor is a right-mover (stack.back() > 0)
14            while (incoming < 0 && !stack.empty() && stack.back() > 0) {
15                if (abs(incoming) > stack.back()) {
16                    // Incoming is bigger. Top of stack explodes.
17                    // We DO NOT set destroyed = true yet, because the incoming
18                    // asteroid keeps moving and might hit the next thing!
19                    stack.pop_back();
20                    continue;
21                } else if (abs(incoming) == stack.back()) {
22                    // Mutual destruction. Top of stack explodes.
23                    stack.pop_back();
24                    destroyed = true; // Incoming also explodes!
25                    break;
26                } else {
27                    // Top of stack is bigger. Incoming explodes immediately.
28                    destroyed = true;
29                    break;
30                }
31            }
32
33            // If the incoming asteroid survived all possible collisions,
34            // it joins the survivors on the stack!
35            if (!destroyed) {
36                stack.push_back(incoming);
37            }
38        }
39
40        return stack;
41    }
42};