class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        vector<int>left(n);
        vector<int>right(n);

        // find the previous element
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            if(st.empty()){
                left[i]=-1;
            }else{
                left[i]=st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        // find the next smaller
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            if(st.empty()){
                right[i]=n;
            }else{
                right[i]=st.top();
            }
            st.push(i);
        }

        // calculate the max area
        int maxArea=0;
        for(int i=0;i<n;i++){
            int height=heights[i];
            int width=right[i]-left[i]-1;

            int area=height*width;
            maxArea=max(maxArea,area);
        }

        return maxArea;
    }
};