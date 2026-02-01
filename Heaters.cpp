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

// another way 

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> res(
            houses.size(),
            INT_MAX); // For each house, what is the minimum distance to any
                      // heater? So ans array is of size of Houses array
                      // EVERY ELEMENT IS INITIALLLY INT_MAX because we'll
                      // update it with smaller values then we'll find the
                      // maximum of those values

        // RHS min distance calculation
        for (int i = 0, h = 0; i < houses.size() && h < heaters.size();) {
            if (houses[i] <= heaters[h]) {
                res[i] = heaters[h] - houses[i];
                i++;
            } else
                h++;
        }

        // LHS min distance calculation
        for (int i = houses.size() - 1, h = heaters.size() - 1;
             i >= 0 && h >= 0;) {
            if (houses[i] >= heaters[h]) {
                res[i] = min(houses[i] - heaters[h], res[i]);
                i--;
            } else
                h--;
        }
        int maxRadius = INT_MIN;
        for (int i = 0; i < res.size(); i++) {
            if (maxRadius < res[i])
                maxRadius = res[i];
        }
        return maxRadius;
    }
};
explain me this code 
