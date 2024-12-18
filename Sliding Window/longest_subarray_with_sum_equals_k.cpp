#include<iostream>
#include<vector>

using namespace std;

int lenOfLongestSubarr(vector<int>& arr, int k) 
{
    int i = 0;
    int w_sum = 0;
    int w_size = 0;
    int max_window = 0;
    
    for(int j = 0; j < arr.size(); j++)
    {
        w_sum += arr[j];
        w_size++;
        
        if(w_sum == k && w_size > max_window)
        {
            max_window = w_size;
        }
        
        while(w_sum > k && i <= j)
        {
            w_sum -= arr[i++];
            w_size--;
        }
    }
    return max_window;
}