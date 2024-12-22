#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int longestKSubstr(string &str, int k) 
    {
        unordered_map<char, int> mp;
        int i = 0;
        int maximum_window_size = 0;
        
        
        for(int j = 0; j < str.size(); j++)
        {
            // insert character in window
            if(mp.find(str[j]) == mp.end())
                mp[str[j]] = 1;
            else
                mp[str[j]]++;
            
            // check if window size is not exceeded k. If exceeded, then remove characters from left side.
            while(mp.size() > k)
            {
                mp[str[i]]--;
                if(mp[str[i]] == 0)
                    mp.erase(str[i]);
                i++;
            }
            
            // check and update maximum window size count.
            if(mp.size() == k)
            {
                int window_size = j-i+1;
                if(window_size > maximum_window_size)
                    maximum_window_size = window_size;
            }
        }
        
        if(maximum_window_size)
            return maximum_window_size;
        return -1;
    }