class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if (s1.size() > s2.size()) return false;
    
    vector<int> s1_count(26, 0), s2_count(26, 0);
    
    for (char c : s1) {
        s1_count[c - 'a']++;
    }
    
    int left = 0;
    for (int right = 0; right < s2.size(); right++) {
        s2_count[s2[right] - 'a']++;
        
        if (right - left + 1 > s1.size()) {
            s2_count[s2[left] - 'a']--;
            left++;
        }
    
        if (s1_count == s2_count) return true;
    }
    
    return false;
    }
};