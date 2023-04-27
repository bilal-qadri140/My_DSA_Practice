//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int ans = 0;
	    vector<int> hashPat(26,0); // for count of pat
	    vector<int> hashTxt(26,0); // for count of txt
	    
	    for(int i = 0; i < pat.size(); i++)
	        hashPat[pat[i]-'a']++; //count frequency of pat chars
	    int i = 0, j = 0;
	    int n = txt.size();
	    int k = pat.size();
	    while(j < n)
	    {
	        hashTxt[txt[j] - 'a']++; // count frequency of txt
	        
	        if(j - i + 1 == k) // check if hit the window
	        {
	            if(hashTxt == hashPat)
	                ans++;
	            hashTxt[txt[i]-'a']--; //maintain window
	            i++;
	        }
	        j++;
	    }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends