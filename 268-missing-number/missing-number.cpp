class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int tmp = 0;
        int tmp2 = 0;
        for(int i = 0; i < nums.size(); ++i) {
            tmp += i;
            tmp2 += nums[i];
        }
        tmp += nums.size();
        return tmp-tmp2;
    }
};