class Solution {
public:
    bool backspaceCompare(string s, string t) {
           stack<char> A, B;
 for (int i=0;i<s.size();i++) {
        if (s[i] == '#') {
            if (!A.empty()) 
            A.pop();
        } else {
            A.push(s[i]);
        }
    }

    for (int j=0;j<t.size();j++) {
        if (t[j] == '#') {
            if (!B.empty()) 
            B.pop();
        } else {
            B.push(t[j]);
        }
    }

    return A == B;
    }
};