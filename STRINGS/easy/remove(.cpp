#include <iostream>
#include <string>
#include <algorithm>
class Solution {
public:
    std::string removeOuterParentheses(std::string s) {
        std::string a="";
        int c=0;

        for(char i:s){
            if(i=='('){
                if(c>0){
                    a+=i;
                }
                c++;
            }else if(i==')'){
                c--;
                if(c>0){
                    a+=i;
                }
            }
        }
        return a;
    }
};
int main() {
    Solution solver;

    std::string s = "(()())(())";
    std::string result = solver.removeOuterParentheses(s);

    std::cout << "String after removing outer parentheses: " << result << std::endl;

    return 0;
}