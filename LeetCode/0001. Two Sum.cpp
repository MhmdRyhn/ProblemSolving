class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> store;
        for(int i=0; i<nums.size(); i++) {
            int remaining = target - nums[i];
            if(store.find(remaining) != store.end() and store[remaining] != i)
                return {store[remaining], i};
            store[nums[i]] = i;
        }
        return {};
    }
};

