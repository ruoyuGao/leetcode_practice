# leetcode_practice

## Longest Valid Parentheses
### count left and right
维护左右计数器，相等的时候计数，但是右边大于左边的时候清零，但是速度其实超级慢虽然看起来复杂度不高
'''C
class Solution {
public:
    int longestValidParentheses(string s) {
       int left=0,right=0,maxlength=0;
       for(const char& c:s){
           if(c=='(')left++;
           else right++;
           if(left==right){
               maxlength=max(maxlength,right*2);
           }else if(right>=left){
               left=right=0;
           }
       }
        left=right=0;
        for(int i=s.length()-1;i>=0;i--){
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * left);
            } else if (left >= right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
};
'''
### stack
push -1 in stack, meet left parentheses,push it index, meet right parenthese pop. maxlen is the difference between i and top of stack
'''C
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> test;
        int maxlen=0;
        test.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')test.push(i);
            else{
                test.pop();
                if(test.empty()){
                    test.push(i);
                }else{
                    maxlen=max(maxlen,i-test.top());
                }
            }
        }
        return maxlen;       
    }
};
'''
