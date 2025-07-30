#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;

        vector<int> chk(26,0);

        for(char x:s){
            chk[x-'a']++;
        }

        for(char x:t){
            chk[x-'a']--;
        }

        bool allZero = all_of(chk.begin(),chk.end(),[](int e){
            return e==0;
        });

        return allZero;
    }


    // bool isAnagram(string s, string t) {
    //     if(s.size()!=t.size())
    //         return false;

    //     sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());

    //     return s==t;
    // }
};