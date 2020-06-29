#include<bits/stdc++.h>
using namespace std;


/**** 

      This is implementation of Knuth Morris Pratt Algorithm is based on the explanation 
      provided by https://cp-algorithms.com/string/prefix-function.html#toc-tgt-6 . 


****/



// this function will return all the index in the string text at which string pattern is found
// in the form of vector
vector<int> foundPatternIndex(vector<int> lps,string text,string pattern){
      int n=text.size();
      int m=pattern.size();
      int j=0;
      vector<int> fpi;
      for(int i=0;i<n;i++){
            while(j>0 && text[i]!=pattern[j]) j=lps[j-1];
            if(pattern[j]==text[i]) j++;
            if(j==m-1) fpi.push_back(i-j);
      }
      return fpi;
}




// this function will return the longest proper prefix vector for string pattern
vector<int> createLongestProperPrefix(string pattern){
    int n=pattern.size();
    vector<int> lps(n,0);
    for(int i=1;i<n;i++)
    {
        int j=lps[i-1];
        while(j>0 && pattern[j]!=pattern[i]) j=lps[j-1];
        if(pattern[i]==pattern[j]) j++;
        lps[i]=j;
    }
    return lps;
}




// this function will print all the indexex at the which pattern is found in the string text
void printFoundPatternIndex(vector<int> fpi){
     int n=fpi.size();
     for(int i=0;i<n;i++){
         cout<<"string found at position "<<fpi[i]<<" "<<" in the string text."<<endl;
     }
     return ;
}



int main(){
    string text,pattern;
    cin>>text>>pattern;
    // lps is longest proper prefix vector
    vector<int> lps=createLongestProperPrefix(pattern);

    // fpi is found pattern indexes
    vector<int> fpi=foundPatternIndex(lps,text,pattern);

    
    return 0;
}