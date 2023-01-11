// problem link --> https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long long> stk;

        for (auto it : tokens)
            if (it == "+" || it == "-" || it == "*" || it == "/")
            {
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                if (it == "+")
                    stk.push(first + second);
                if (it == "-")
                    stk.push(first - second);
                if (it == "*")
                    stk.push(1ll * first * second);
                if (it == "/")
                    stk.push(first / second);
            }
            else
            {
                stk.push(stoi(it));
            }

        return stk.top();
    }
};