class Solution {
public:
    struct Node{
        char character;
        int position;
    };
    string removeDuplicates(string s, int k) {
        stack<Node> st;
        st.push({s[0], 1});
        for(int i = 1; i < s.size(); i++){
            if(st.empty()){
                st.push({s[i], 1});
            }
            else{
                if(s[i] == st.top().character){
                    st.push({s[i], st.top().position + 1});
                    if(st.top().position == k){
                        while(!st.empty() and st.top().character == s[i]){
                            st.pop();
                        }
                    }
                }
                else{
                    st.push({s[i], 1});
                }
            }
        }
        string new_string;
        while(!st.empty()){
            new_string += st.top().character;
            st.pop();
        }
        reverse(new_string.begin(), new_string.end());
        return new_string;
    }
};