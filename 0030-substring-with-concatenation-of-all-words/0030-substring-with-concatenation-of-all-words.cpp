#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        
        if(s.empty() || words.empty()) return result;
        
        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        
        unordered_map<string, int> wordMap;
        
        // Store frequency of words
        for(string word : words)
            wordMap[word]++;
        
        // Try each possible offset
        for(int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> tempMap;
            
            for(int j = i; j + wordLen <= s.length(); j += wordLen) {
                string word = s.substr(j, wordLen);
                
                if(wordMap.count(word)) {
                    tempMap[word]++;
                    count++;
                    
                    // If word frequency exceeds required
                    while(tempMap[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        tempMap[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                    
                    if(count == wordCount)
                        result.push_back(left);
                }
                else {
                    tempMap.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        
        return result;
    }
};
