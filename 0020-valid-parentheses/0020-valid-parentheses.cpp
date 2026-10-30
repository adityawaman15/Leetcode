class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        

        for(int i = 0; i < s.length();i++){
            char ch = s[i];
            if(st.empty()){
                st.push(ch);
            }
            else{
                char top = st.top();
                if(ch == '{' || ch == '(' || ch == '[' ){
                    st.push(ch);
                }
                else{
                    if((top == '{' && ch == '}')
                        || (top == '(' && ch == ')')
                        || (top == '[' && ch == ']')){
                            st.pop();
                        }
                    else{
                        return false;
                    }
                }

            }
            
        }

        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
        
    }
};