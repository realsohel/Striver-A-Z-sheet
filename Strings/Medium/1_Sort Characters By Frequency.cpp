#include<bits/stdc++.h>
using namespace std;

#define P pair<char,int>
class Solution {
public:
    string frequencySort(string s) {

        vector<P> vec(123);

        for(char &ch:s){
            int f = vec[ch].second;
            vec[ch]={ch,f+1};
        }

        auto lambda = [&](P &p1, P &p2){
            return p1.second>p2.second;
        };
        sort(vec.begin(),vec.end(),lambda);

        string res="";

        for(int i=0;i<vec.size();i++){
            if(vec[i].second>0){
                char ch=vec[i].first;
                int f = vec[i].second;
                string temp(f, ch);
                res+=temp;
            }
        }

        return res;
    }
};