// Last updated: 7/17/2026, 2:02:07 PM
class Solution {
public:
    string reorganizeString(string s) {
        // 1. Count frequencies
        unordered_map<char, int> counts;
        for (char c : s)
            counts[c]++;

        // 2. Max-Heap to store pairs of {count, character}
        priority_queue<pair<int, char>> maxHeap;
        for (auto& pair : counts)
            maxHeap.push({pair.second, pair.first});

        string result = "";

        // 3. The "On-Deck Circle": A single variable to act as our n=1
        // cooldown! We initialize it with a dummy count of -1.
        pair<int, char> prev = {-1, '#'};

        while (!maxHeap.empty()) {
            // Get the most frequent available character
            auto current = maxHeap.top();
            maxHeap.pop();

            // Add it to our string and decrement its required count
            result += current.second;
            current.first--;

            // If the PREVIOUS character is rested and still needs to be placed,
            // put it back onto the bench (the Max-Heap)!
            if (prev.first > 0)
                maxHeap.push(prev);

            // The CURRENT character just swung. Send it to the On-Deck Circle
            // to rest.
            prev = current;
        }

        // If we finished the heap, but our result isn't the length of the
        // original string, it means a character got stuck in the 'prev'
        // variable with nowhere to go!
        if (result.length() != s.length())
            return "";

        return result;
    }
};