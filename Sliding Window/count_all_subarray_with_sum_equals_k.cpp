/*
NOTE : This Implementation is only valid if array(nums) contains non negative numbers.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int count = 0;
        int window_sum = 0;
        int i = 0;

        for(int j = 0; j < nums.size(); j++)
        {
            window_sum += nums[j];          // add element to the window.

            if(window_sum == k)             // if sum of all the elemts in window equals k
            {
                count++;                    // increment the count.
                continue;
            }

            while(window_sum > k)           // if sum of all the elements in the window exceeds k, then start shrinking.
                window_sum -= nums[i++];
            
            if(window_sum == k && i <= j)   // if sum of all the elements in the window is equals k and pointer i is still less than or equal to pointer j
                count++;                    // then increment the count.
        }
        return count;
    }
};