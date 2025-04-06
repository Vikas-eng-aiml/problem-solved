class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        q.push(i);
    }

    vector<int> result(n);
    sort(deck.begin(), deck.end());

    for (int card : deck) {
        int index = q.front();
        q.pop();
        result[index] = card;

        if (!q.empty()) {
            q.push(q.front());
            q.pop();
        }
    }

    return result;

    }
};