#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> FirstNegativeInteger(vector<int>& arr, int k) 
{
    /*
    This function returns first negative number in every window of size k.
    */

    vector<int> result;     // To store first negative number in every window of size k.
    queue<int> q;           // Place all the negative numbers in queue.
    int i = 0;              // left pointer
    
    for(int j = 0; j < arr.size(); j++)
    {
        if(arr[j] < 0)      // Encountered negative number.
            q.push(j);
            
        if(j-i+1 < k)        // Window size is smaller than k.
            continue;
            
        if(q.empty())                               // window doesn't contain any negative number.
            result.push_back(0);
        else                                        // insert first negative number of current window in result.
            result.push_back(arr[q.front()]);

        i++;

        if(!q.empty() && q.front() < i)             // If first negative number of queue is outside of window, then remove it from queue.
            q.pop();
    }
    return result;
}