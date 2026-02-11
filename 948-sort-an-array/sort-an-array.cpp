class Solution {
public:
    vector<int> sortArray(vector<int>& arr) {
        if (arr.empty()) return {};

        int max_val = *std::max_element(arr.begin(), arr.end());
        int min_val = *std::min_element(arr.begin(), arr.end());
        int range = max_val - min_val + 1;

        std::vector<int> count(range, 0);
        std::vector<int> output(arr.size());

        for (int val : arr) {
            count[val - min_val]++;
        }

        for (int i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            int val = arr[i];
            int pos = count[val - min_val] - 1;
            output[pos] = val;
            count[val - min_val]--;
        }
        return output;
    }
};