#include <vector>;
#include <iostream>;
#include <algorithm>;
using namespace std;

class Solution {
    private:
    inline int getValue(char c) {
        switch(c){
            case '1': return 1;
            case '2': return 2;
            case '3': return 3;
            case '4': return 4;
            case '5': return 5;
            case '6': return 6;
            case '7': return 7;
            case '8': return 8;
            case '9': return 9;
            default : return 0;
        }
    }

public:
    int myAtoi(string s) {
        int n= s.length();
        int ans=0;
        int c=0;
        int d=0;
        int e=0;

        for(int i=0; i<n; i++){
            if((s[i])>='0' && (s[i])<='9'){
                if(ans!=0){
                    c++;
                }
                if (d != 1 && (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && getValue(s[i]) > 7))){
                    ans=(INT_MAX);
                    break;
                }
                if (d == 1 && (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && getValue(s[i]) > 7))){
                    return INT_MIN;
                }
                ans= (ans*10)+ getValue(s[i]);
                e++;
            }else if(((s[i] == '-') || (s[i] == '+')) && d==0 && e==0){
                if((s[i] == '-')){
                    d++;
                }else{
                    d--;
                }
            }else if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]=='.')){
                break;
            }else if (!(s[i] >= '0' && s[i] <= '9') && (d != 0 || e != 0)) {
                break;
            }
        }

        if(d==1){
            ans= (ans*(-1));
        }
        return ans;
    }
};

int main() {
    Solution s;
    string str = "   -42";
    cout << s.myAtoi(str);
}