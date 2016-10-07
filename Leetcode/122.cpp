#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int pre;
        bool isBuy = false;
        for(int i=1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                if(!isBuy){
                    isBuy = true;
                    pre = prices[i-1];
                }
            }
            else if(prices[i] <= prices[i-1]){
                if(isBuy){
                    isBuy = false;
                    profit += prices[i-1] - pre;
                }
            }
            if(i == prices.size()-1 && isBuy)
            {
                profit += prices[i] - pre;
            }
        }
        return profit;
    }
};

int main(){
    Solution s;
    vector<int> ivec{4,3,2,1,3,5,2,8,4,9,10,50,30,12,45};
    cout << s.maxProfit(ivec) << endl;
}
