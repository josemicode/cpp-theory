#include "maps.h"

// Ransom Note
bool canConstruct(string ransomNote, string magazine){
    unordered_map<char, int> num_chars;
    for(char c : magazine){
        num_chars[c]++;
    }
    
    for(char c : ransomNote){
        if(num_chars[c] == 0){
            return false;
        }
        num_chars[c]--;
    }
    
    return true;
}