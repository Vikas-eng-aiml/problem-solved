class StockPrice {
private:
    unordered_map<int, int> timePriceMap; 
    map<int, int> priceFreqMap;          
    int latestTime = 0;

public:
    StockPrice() {}

    void update(int timestamp, int price) {

        if (timePriceMap.count(timestamp)) {
            int oldPrice = timePriceMap[timestamp];
            priceFreqMap[oldPrice]--;
            if (priceFreqMap[oldPrice] == 0) {
                priceFreqMap.erase(oldPrice);
            }
        }

        timePriceMap[timestamp] = price;
        priceFreqMap[price]++;
        latestTime = max(latestTime, timestamp);
    }

    int current() {
        return timePriceMap[latestTime];
    }

    int maximum() {
        return priceFreqMap.rbegin()->first;  
    }

    int minimum() {
        return priceFreqMap.begin()->first;  
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */