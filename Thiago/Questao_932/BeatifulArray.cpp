#include <bits/stdc++.h>

using namespace std;
class Solution {
    public:

    vector<int> generateBeautifulArray(int N) {
        if (N == 1) {
            return {1};
        }
        
        vector<int> odd = generateBeautifulArray((N + 1) / 2);
        vector<int> even = generateBeautifulArray(N / 2);
        
        vector<int> result;
        
        for (const auto& i : odd) {
            result.push_back(i * 2 - 1);
        }
        
        for (const auto& i : even) {
            result.push_back(i * 2);
        }
        
        return result;
    }

    
};

int main(){
        int N;
        vector<int> result;
        scanf("%d", &N);
        Solution a;
        result = a.generateBeautifulArray(N);

        printf("[");
        for(int i =0;i<N;i++){
            if(i == (N-1)){
                std::cout << result[i];
                break;
            }
            std::cout << result[i] << ","; 
        }
        printf("]");
        return 0;
}

