class Solution {
public:
    bool backspaceCompare(string s, string t) {
           stack<char> A, B;

  
    for (char c : s) {
        if (c == '#') {
            if (!A.empty()) A.pop();
        } else {
            A.push(c);
        }
    }

    for (char c : t) {
        if (c == '#') {
            if (!B.empty()) B.pop();
        } else {
            B.push(c);
        }
    }

    return A == B;
    }
};