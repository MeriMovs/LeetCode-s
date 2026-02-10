class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3] = {0, 0, 0};
        for(auto el : nums){ arr[el]++; }
        int ind1 = arr[0];
        int ind2 = arr[0] + arr[1];
        for(int i = 0; i < ind1; ++i) {
            nums[i] = 0;
        }
        for(int i = ind1; i < ind2; ++i) {
            nums[i] = 1;
        }
        for(int i = ind2; i < nums.size(); ++i) {
            nums[i] = 2;
        }
    }
};