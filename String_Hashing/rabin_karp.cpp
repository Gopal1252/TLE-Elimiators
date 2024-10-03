#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        //code after studying from tle
        const int M = 1e9+7;
        int binExp(int a, int b){
            int ans = 1;
            while(b){
                if(b&1){
                    ans = (ans * 1LL * a)%M;
                }
                a = (a * 1LL * a)%M;
                b>>=1;
            }
            return ans;
        }
        int getHash(string &s){
            int ans = 0;
            for(auto & it : s){
                ans = (ans*1LL*31 + (it - 'a' + 1))%M;
            }
            return ans;
        }
        vector <int> search(string pat, string txt)
        {
            int patHash = getHash(pat);
            int n = txt.size();
            vector<int> prefixHash;
            
            int hsh = 0;
            for(auto & it : txt){
                hsh = (hsh*1LL*31 + (it - 'a' + 1))%M;
                prefixHash.push_back(hsh);
            }
            
            vector<int> ans;
            int i = 0;
            int j = pat.size()-1;
            if(prefixHash[j] == patHash) ans.push_back(1);
            int hash = prefixHash[j];
            int power = binExp(31,j-i);
            j++;
            i++;
            while(j<txt.size()){
                hash = (hash - ((txt[i-1]-'a'+1) * 1LL * power)%M + M)%M;
                hash = (hash * 1LL * 31 + (txt[j]-'a'+1))%M;
                if(hash == patHash) ans.push_back(i+1);
                i++;
                j++;
            }
            if(ans.empty()) ans.push_back(-1);
            return ans;
        }
     
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    return 0;
}