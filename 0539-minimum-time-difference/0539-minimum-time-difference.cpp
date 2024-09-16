class Solution {
public:
    int convertToMinutes(const string& time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

int findMinDifference(vector<string>& timePoints) {
    // Convert time points to minutes
    vector<int> minutes;
    for (const string& time : timePoints) {
        minutes.push_back(convertToMinutes(time));
    }
    
    // Sort the time points in minutes
    sort(minutes.begin(), minutes.end());
    
    // Initialize minimum difference to a large value
    int min_diff = INT_MAX;
    
    // Check the difference between consecutive time points
    for (int i = 1; i < minutes.size(); ++i) {
        min_diff = min(min_diff, minutes[i] - minutes[i - 1]);
    }
    
    // Check the circular difference (across midnight)
    int circular_diff = 24 * 60 - (minutes.back() - minutes.front());
    min_diff = min(min_diff, circular_diff);
    
    return min_diff;
}

int main() {
    vector<string> timePoints1 = {"23:59", "00:00"};
    vector<string> timePoints2 = {"00:00", "23:59", "00:00"};
    
    cout << "Minimum difference for timePoints1: " << findMinDifference(timePoints1) << " minutes" << endl;
    cout << "Minimum difference for timePoints2: " << findMinDifference(timePoints2) << " minutes" << endl;
    
    return 0;
}
};