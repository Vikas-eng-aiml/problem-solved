class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       queue<int> q;
    int n = tickets.size();
    for (int i = 0; i < n; i++) {
        q.push(i);
    }
    int time = 0;
    while (tickets[k] != 0) {
        int front = q.front();
        q.pop();
        tickets[front]--;
        time++; 
        if (tickets[front] > 0) {
            q.push(front);
        }
    }
    return time;
    }
};