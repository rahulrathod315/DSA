#include<iostream> 
#include<vector>

using namespace std;

/*
- dq.front() is the biggest element in window.
- if arr[j] > dq.front() --> make dq empty and insert element. since we have found new maximum, old maximum will be of no use.
- if arr[j] <= dq.front() --> remove all the elements smaller than the current element arr[j] from right side and insert it. 
*/

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    int i = 0;
    vector<int> result;
    deque<int> dq;

    for(int j = 0; j < nums.size(); j++)
    {
        if(nums[j] > dq.front())    // new maximum element found.
        {
            dq.clear();             // clear the deque.
            dq.push_front(nums[j]);    // insert newly found maximum in the queue.
        }
        else
        {
            while(dq.back() < nums[j])  // remove all the elements smaller than the current element.
                dq.pop_back();
            dq.push_back(nums[j]);  // insert element in the queue.
        }
        
        if(j-i+1 < k)   // if we haven't hit the window size yet, then continue.
            continue;

        result.push_back(dq.front());   // insert the maximum element in the result vector.

        if(dq.front() == nums[i])   // remove the maximum if it is out from the window.
            dq.pop_front();

        i++;    // increment the left pointer to slide the window.
    }   
    return result; 
}