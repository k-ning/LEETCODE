int lastStoneWeight(vector<int>& stones) {
        
        int size = stones.size();
        if (size == 0)
                return 0;
        
        while (size != 1 && size != 0) {
                sort(stones.begin(), stones.end());
                int x = stones[size - 2];
                int y = stones[size - 1];
            
                if (x == y) {
                        stones.pop_back();
                        stones.pop_back();
                } else if (x != y) {
                        y = y - x;
                        stones[size - 1] = y;
                        vector<int>::iterator itc = stones.end() - 2;
                        stones.erase(itc);
                }
                size = stones.size();
        }
        if (size == 0) {
                return 0;
        } else
                return stones[0];
}

int lastStoneWeight_1(vector<int>& stones) {
        int size = stones.size();
        int x = 0;
        int y = 0;
        vector<int>::iterator itc;
        if (size == 0)
                return 0;
        
        while (size != 1 && size != 0) {
                itc = max_element(stones.begin(), stones.end());
                x = *itc;
                stones.erase(itc);
            
                itc = max_element(stones.begin(), stones.end());
                y = *itc;
            
                if (x == y) {
                        stones.erase(itc);
                } else if (x != y) {
                        x = x - y;
                        *itc = x;
                }
                size = stones.size();
        }
        if (size == 0) {
                return 0;
        } else
                return stones[0];
}

int main() {
    return 0;
}
