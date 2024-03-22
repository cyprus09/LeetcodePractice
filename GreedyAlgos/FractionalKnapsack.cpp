#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

double maximumValue(vector<pair<int, int>> &items, int n, int w) {

  vector<pair<double, pair<int, int>>> valuePerWeight;
  for (int i = 0; i < n; i++) {
    double ratio = static_cast<double>(items[i].second) / items[i].first;
    valuePerWeight.push_back({ratio, {items[i].first, items[i].second}});
  }

  sort(valuePerWeight.rbegin(), valuePerWeight.rend());

  int currentWeight = 0;
  double currentValue = 0.0;

  for (int i = 0; i < n; i++) {
    if (currentWeight + valuePerWeight[i].second.first <= w) {
      currentWeight += valuePerWeight[i].second.first;
      currentValue += valuePerWeight[i].second.second;
    } else {
      double remainingWeight = w - currentWeight;
      currentValue += remainingWeight * valuePerWeight[i].first;
      break;
    }
  }

  return currentValue;
}