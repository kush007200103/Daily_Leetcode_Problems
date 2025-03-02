class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            // Merge nums2 into nums1
            nums1.insert(nums1.end(), nums2.begin(), nums2.end());
            
            // Resultant vector to hold the merged and summed arrays
            vector<vector<int>> ans;
            
            // Sort the array based on the first element of each sub-array
            sort(nums1.begin(), nums1.end());
            
            // Iterate through the merged and sorted array
            for (int i = 0; i < nums1.size(); i++) {
                if (!ans.empty() && ans.back()[0] == nums1[i][0]) {
                    // If the key already exists in the result, sum the values
                    ans.back()[1] += nums1[i][1];
                } else {
                    // If the key doesn't exist, push a new entry into the result
                    ans.push_back(nums1[i]);
                }
            }
            
            return ans;
        }
    };
    