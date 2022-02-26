class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        auto calcArea = [] (vector<int>& i, vector<int> j, vector<int> k){
        return 0.5 * abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1] - i[0] * k[1] - j[0] * i[1] - k[0] * j[1]);
    };

        double max_;
        for(int i = 0; i < points.size() - 2; i++){
            for(int j = i + 1; j < points.size() - 1; j++){
                for(int k = j + 1; k < points.size(); k++){
                    double area = calcArea(points[i], points[j], points[k]);
                    max_ = max(max_, area);
                }
            }
        }
        return max_;
    }
};