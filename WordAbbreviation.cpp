#include<iostream>
#include<string.h>
using namespace std;
//word abbreviation
void solve(string s, int i, string str1){
    
    if(i == s.size()){
        cout<<str1<<endl;
        return;
    }

    str1.push_back(s[i]);

    solve(s,i+1,str1);

    str1.pop_back();

    int count = 1;

    if(!str1.empty()){
        if(isdigit(str1.back()))
        {
            count+=(int)(str1.back()-'0');
            str1.pop_back();
        }
    }

    char ans = (char)(count + '0');
    str1.push_back(ans);

    solve(s,i+1,str1);
}

int main(){

    string s = "ABC";
    
    string str1;
    solve(s,0,str1);
    return 0;
}
