#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double calculateDistance(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

int sumNaturalNumbers(int N) {
    return (N * (N + 1)) / 2;
}

int main() {
    int N;
    cout << "Enter the number of points: ";
    cin >> N;

    vector<pair<int, int>> points(N);
    cout << "Enter the coordinates (x, y) of each point:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double totalDistance = 0.0;
    for (int i = 0; i < N - 1; i++) {
        totalDistance += calculateDistance(points[i], points[i + 1]);
    }

    int sum = sumNaturalNumbers(N);

    cout << "Total Distance: " << totalDistance << endl;
    cout << "Sum of first " << N << " natural numbers: " << sum << endl;

    return 0;
}