
    #include<iostream>
    #include<vector>
    #include<map>

    using namespace std;
    
    vector<int> findAnagrams(string s, string p) 
    {
        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;
        vector<int> result;
        int i = 0;

        // Count frequency of each character in pattern p

        for(auto ch : p)
        {
            if(mp.find(ch) == mp.end())
                mp[ch] = 1;
            else
                mp[ch]++;
        }

        
        for(int j = 0; j < s.length(); j++)
        {
            if(mp2.find(s[j]) == mp2.end()) // Increment the frequency if character is already present.
                    mp2[s[j]] = 1;
            else                            // Set frequency to 1 if encounter new word.
                mp2[s[j]]++;

            if(j-i+1 < p.length())          // Window size is not sufficient (less than length of pattern string p)
                continue;                   // then continue
            
            if(mp == mp2)                   // If frequency of window and pattern p matches, then push index of i to result.
                result.push_back(i);

            mp2[s[i]]--;                    // Removing the frequency from left pointer (i).

            if(mp2[s[i]] == 0)              // erase the key from map if frequency of the character after removing from the window is zero.
                mp2.erase(s[i]);

            i++;                           // Increment the left pointer (i)
        }
        
        return result;
    }