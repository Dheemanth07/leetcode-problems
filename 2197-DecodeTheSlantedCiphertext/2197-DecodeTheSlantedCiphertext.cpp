// Last updated: 6/22/2026, 6:29:26 PM
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (n == 0)
            return "";

        int cols = n / rows;
        string result;

        // Traverse each diagonal starting from the top row
        for (int start_col = 0; start_col < cols; ++start_col) {
            for (int r = 0, c = start_col; r < rows && c < cols; ++r, ++c) {
                result += encodedText[r * cols + c];
            }
        }

        // Remove trailing space padding efficiently
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};