#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct DeviationInfo {
    int number;
    double deviation;
};

double vedicSqrt(int n) {
    int A = (int)sqrt(n);     // Nearest smaller or equal integer
    int B = n - A * A;
    return A + (B / (2.0 * A));  // Approximation
}

int main() {
    vector<DeviationInfo> deviations;

    for (int n = 1; n <= 1000; ++n) {
        double actual = sqrt(n);
        double approx = vedicSqrt(n);
        double percentDeviation = fabs(actual - approx) / actual * 100;

        if (percentDeviation > 1.0) {
            deviations.push_back({n, percentDeviation});
        }
    }

    // Sort in decreasing order
    sort(deviations.begin(), deviations.end(), [](const DeviationInfo& a, const DeviationInfo& b) {
        return a.deviation > b.deviation;
    });

    for (const auto& item : deviations) {
        cout << "Number: " << item.number
             << ", Deviation: " << item.deviation << "%" << endl;
    }

    return 0;
}
