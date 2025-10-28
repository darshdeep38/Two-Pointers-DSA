class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0;

        for (int house : houses) {
            // Find the first heater that is not less than the house position
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            int dist1 = (it == heaters.end()) ? INT_MAX : abs(*it - house);
            int dist2 = (it == heaters.begin()) ? INT_MAX : abs(*(it - 1) - house);
            radius = max(radius, min(dist1, dist2));
        }

        return radius;
    }
};
