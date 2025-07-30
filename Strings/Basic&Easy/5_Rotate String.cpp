#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        return (s + s).find(goal) != string::npos;
    }
};

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
        
//         int n= goal.size();
//         int m= s.size();

//         if(n!=m)
//             return false;

//         string dup=s;
        
//         for(int i=0;i<100;i++){
//             dup+=s;
//             if(dup.find(goal)!=std::string::npos)
//                 return true;
//         }

//         return false;
//     }
// };