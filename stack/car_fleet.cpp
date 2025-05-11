class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<int>st;
        vector<int>ans(temps.size(),0);
        for(int i =0;i<temps.size();i++){
            if(st.empty() || temps[st.top()] > temps[i]){
                st.push(i);
                continue;
            }
            while(!st.empty() && temps[st.top()] < temps[i]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};