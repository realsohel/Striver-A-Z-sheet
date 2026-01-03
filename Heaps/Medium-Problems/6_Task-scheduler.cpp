#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) { 
        int sz = tasks.size(); 
        vector<int> freq(26,0);
        priority_queue<int> pq;
        int time=0;

        for(char &x:tasks){
            freq[x - 'A']++;
        }

        for(int &x:freq){
            if(x>0)
                pq.push(x);
        }

        while(!pq.empty()){
            vector<int> tmp;

            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    tmp.push_back(freq);
                }
            }
            
            for(int &fr:tmp){
                if(fr>0)
                    pq.push(fr);
            }

            if(pq.empty())
                time+=tmp.size();
            else
                time+=n+1;
        }

        return time;
    }
};