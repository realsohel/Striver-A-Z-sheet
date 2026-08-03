#include <bits/stdc++.h> 
using namespace std;

string memo(int idx1, int idx2, string &text1, string &text2, vector<vector<string>> &dp){
	if(idx1<0 || idx2<0)
		return "";
	
	if(dp[idx1][idx2]!="-1")
		return dp[idx1][idx2];

	if(text1[idx1]==text2[idx2])
		return dp[idx1][idx2] = memo(idx1-1, idx2-1 , text1, text2, dp) + text1[idx1];
	
	string ans1 = memo(idx1-1,idx2,text1, text2, dp);
	string ans2 = memo(idx1,idx2-1,text1, text2, dp);

	if(ans1.size()>ans2.size())
		dp[idx1][idx2] = ans1;
	else
		dp[idx1][idx2] = ans2;
	
	return dp[idx1][idx2];
}

string tabulation(int n, int m, string &text1, string &text2){
        
	vector<vector<string>> dp(n+1, vector<string>(m+1,""));

	for(int i=1;i<=n; i++){
		for(int j=1;j<=m;j++){
			
			if(text1[i-1]==text2[j-1]){
				dp[i][j] = dp[i-1][j-1] + text1[i-1];
			}
			else{
				string ans1 = dp[i-1][j];
				string ans2 =dp[i][j-1];

				if(ans1.size()>ans2.size())
					dp[i][j] = ans1;
				else
					dp[i][j] = ans2;
			}
		}
	}
	
	return dp[n][m];
}

int tabulationInt(int n, int m, string &text1, string &text2, vector<vector<int>> &dp){
        
        // vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i=1;i<=n; i++){
            for(int j=1;j<=m;j++){
                
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }

string findLCS(int n, int m,string &s1, string &s2){

	vector<vector<int>> dp(n+1, vector<int>(m+1,0));

	// return memo(n-1,m-1, s1, s2, dp);
	// return tabulation(n,m, s1, s2);
	
	int len =  tabulationInt(n,m, s1, s2, dp);

	string ans = "";

	for(int i=0;i<len;i++){
		ans+="@";
	}

	int i=n, j=m;
	int idx=len-1;

	while(i>0 and j>0){

		if(s1[i-1]==s2[j-1]){
			ans[idx] = s1[i-1];
			idx--;
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}

	return ans;

}