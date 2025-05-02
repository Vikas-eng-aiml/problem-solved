class Solution {
public:
   long long pickGifts(vector<int>& gifts, int k) {
    priority_queue<int> pq(gifts.begin(), gifts.end());

    while (k-- > 0 && !pq.empty()) {
        int maxGift = pq.top();
        pq.pop();
        pq.push((int)sqrt(maxGift));
    }

    long long total = 0; 
    while (!pq.empty()) {
        total += pq.top();
        pq.pop();
    }

    return total;
}
};