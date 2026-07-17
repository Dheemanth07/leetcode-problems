// Last updated: 7/17/2026, 2:02:22 PM
class Solution {
public:
    int calPoints(vector<string>& operations) {
       vector<int> v;
        
        for (const string& op : operations) {
            if (op == "+") // Sum of last two elements
                v.push_back(v[v.size() - 1] +  v[v.size() - 2]);
            else if (op == "D") // Double the last element
                v.push_back(2 * v.back());
            else if (op == "C")  // Remove last element
                v.pop_back();
            else  // Convert string to integer and add to vector
                v.push_back(stoi(op));
        }

        // Sum up all elements in vector
        int sum = 0;
        for (int num : v)
            sum += num;       
        return sum;
    }
};