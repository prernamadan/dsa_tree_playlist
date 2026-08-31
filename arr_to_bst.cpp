class Solution {
public:
    TreeNode* helper(vector<int>& nums, int st, int end)
    {
        if(end < st)
        return NULL;

        int mid= (st + end)/2;
        TreeNode* root= new Node (nums[mid]);
        root-> left= helper(nums, mid+1 , mid-1);
        root-> right=helper(nums, st , end);

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return helper(nums, 0, nums.size()-1);
    }
};
