class Solution {
public:
    // https://leetcode.com/problems/valid-parentheses/
    // use a stack to check open and close brackets
    bool isValid(string str) {
        stack<char> s;
        map<char,char> m({{')','('},{']','['},{'}','{'}});
        for(char c:str){
            if(c == '(' || c == '{' || c == '[')
                s.push(c);
            else if(c == ')' || c == '}' || c == ']')
                if(!s.empty() && s.top() == m[c])
                    s.pop();
                else
                    return false;
        }
        return s.empty();
    }
};
