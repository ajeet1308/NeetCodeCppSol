class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // TC: O(n), SC:O(1)
        // Floyd's Cycle Detection Algorithm
        // So here let's map indexes with values and go with the flow starting from 0
        // e.g : 
        // nums[0]->nums[1]->nums[3]->nums[2]->nums[4]->nums[2] => 1->3->2->4->2
        // For more info: https://www.youtube.com/watch?v=wjYnzkAhcNk
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
/***********************************************************************************/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // TC: O(nlogn), SC:O(1)
        // bitwise method
        int ans = 0, n = nums.size()-1; // Since their is already n+1 elements, here n represents actual unique elements;
        for(int i=0;i<32;i++) {
            int setBitsOriginal = 0, setBitsExpected = 0;
            // Here their n+1 elements out of which n are unique and one is duplicate of one of the n elements
            // This means no of setbits in (1..n) on jth position should match with setbits of nums[1...n+1] jth positions
            // If anyhow on jth position originalBits > expectedBits this means that jth position setbit is missing in (1..n) it means that is our extra added duplicate jth position setbit which is incremeting originalSetbits
            for(int j=0;j<n+1;j++) {
                if (j & (1<<i)) setBitsExpected++;
                if (nums[j] & (1<<i)) setBitsOriginal++;
            }
            if (setBitsOriginal > setBitsExpected) {
                // This means 'ans' is an duplicate and it's jth bit has made count of originalSetBits greater than acutalSetBits
                ans = ans | (1<<i);
            }
        }
        return ans;
    }
};
