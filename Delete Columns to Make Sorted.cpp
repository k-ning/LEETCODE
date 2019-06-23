int minDeletionSize(vector<string>& A) {
        int array_length = A.size();
        int str_length = A[0].length();
        vector<int> temp;
        int diff;
        
        for (int j = 0; j < str_length; j++) {
                for (int i = 1; i < array_length; i++) {
                        diff = A[i][j] - A[i - 1][j];
                
                        if (diff < 0) {
                                temp.push_back(j);
                                break;
                        }
                }
        }
        return temp.size();
}

int main() {
        return;
} 