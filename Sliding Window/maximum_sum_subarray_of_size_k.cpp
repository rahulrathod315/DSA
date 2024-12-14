#include<iostream>
#include<vector>

using namespace std;

int subarraySizeK(vector<int> &nums, int k)
{
    if(k > nums.size()) // invalid k provided
        return -1;

    int window_sum = 0, maximum_sum = INT_MIN;
    int i = 0;

    for(int j = 0; j < nums.size(); j++)
    {
        window_sum += nums[j];

        if(j-i+1 < k)   // window size is less than k
            continue;

        maximum_sum = max(window_sum, maximum_sum);
        window_sum -= nums[i++];
    }
    return maximum_sum;
}