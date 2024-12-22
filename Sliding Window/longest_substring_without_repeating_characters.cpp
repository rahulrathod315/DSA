#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int lengthOfLongestSubstring(string str) 
{
    unordered_map<char, int> mp;

    int i = 0;
    int window_size = 0;
    int maximum_window = 0;

    for(int j = 0; j < str.length(); j++)
    {
        // Inserting character to the window.
        if(mp.find(str[j]) == mp.end())
            mp[str[j]] = 1;
        else
            mp[str[j]]++;

        window_size++;

        // Checking if window doesn't contain any duplicate character. If contains any duplicate character, then remove it.
        while(mp.size() < window_size)
        {
            mp[str[i]]--;
            if(mp[str[i]] == 0)
                mp.erase(str[i]);
            window_size--;
            i++;
        }

        // Check and update the maximum window count.
        if(window_size > maximum_window)
            maximum_window = window_size;
    }
    return maximum_window;
}