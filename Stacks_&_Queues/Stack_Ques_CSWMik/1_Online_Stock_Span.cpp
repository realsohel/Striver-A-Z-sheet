#include <bits/stdc++.h>
using namespace std;


class StockSpanner {
public:
    stack<pair<int,int>> stk;
    StockSpanner() {
    }
    
    int next(int price) {
        if(stk.empty()){
            stk.push({price,1});
            return 1;
        }
        int span =1;

        while(!stk.empty() and price>=stk.top().first){
            span+= stk.top().second;
            stk.pop();
        }
        stk.push({price,span});

        return stk.top().second;
    }
};