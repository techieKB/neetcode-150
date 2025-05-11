class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);  // {position, timeToTarget}

        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], time};
        }
        stack<double>st;
        sort(cars.rbegin(),cars.rend());
        for(int i=0;i<cars.size();i++){
            if(st.empty() || st.top() < cars[i].second){
                st.push(cars[i].second);
            }
        }
        return st.size();
    }
};