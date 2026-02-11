class Solution {
public:
    void counting_sort_by_digit(std::vector<int>& arr, int exp) {
        int n = arr.size();
        std::vector<int> output(n);
        std::vector<int> count(10, 0);

        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        arr = output;
    }

    void radix_sort(std::vector<int>& arr) {
        if (arr.empty())
            return;

        int max_val = *std::max_element(arr.begin(), arr.end());

        for (long exp = 1; max_val / exp > 0; exp *= 10) {
            counting_sort_by_digit(arr, exp);
        }
    }

    int maximumGap(vector<int>& nums) {
        radix_sort(nums);
        int max_diff = 0;

        for (int i = 0; i < nums.size()-1; ++i) {
            int tmp = nums[i+1] - nums[i];
            max_diff = tmp > max_diff ? tmp : max_diff;
        }

        return max_diff;
    }
};