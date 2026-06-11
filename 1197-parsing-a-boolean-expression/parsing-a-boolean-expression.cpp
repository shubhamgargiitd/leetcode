class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {
            if (c == ',') continue;          // separators don't matter
            if (c != ')') {
                st.push(c);                  // t f ! & | ( all just get pushed
            } else {
                // a group just closed: gather its operands
                bool hasTrue = false, hasFalse = false;
                while (st.top() != '(') {
                    char v = st.top(); st.pop();
                    (v == 't' ? hasTrue : hasFalse) = true;
                }
                st.pop();                    // discard '('
                char op = st.top(); st.pop();// the operator

                char res;
                if (op == '!')      res = hasTrue ? 'f' : 't';   // negate the lone operand
                else if (op == '&') res = hasFalse ? 'f' : 't';  // AND: false if any false
                else                res = hasTrue ? 't' : 'f';   // OR: true if any true

                st.push(res);                // result re-enters as an operand
            }
        }
        return st.top() == 't';
    }
};