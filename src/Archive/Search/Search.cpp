#include <iostream>
#include <vector>

using namespace std;

int LinearSearch(vector<int>& arr, int& key) {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == key) {
      return i;
    }
  }

  return -1;
}

int BinarySearch(vector<int>& arr, int& key, int& low, int& high, int& mid) {
  low = 0;
  high = arr.size() - 1;
  
  while (low <= high) {
    mid = (low + high)/2;

    if (arr[mid] == key) {
      return mid;
    } else if (key < arr[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return -1;
}

int LinearSearchSentinel(vector<int>& arr, int& key) {
  arr.push_back(key);
  int i = 0;

  while (arr[i] != key) {
    i++;
  }

  if (i == arr.size()) {
    return -1;
  } else {
    return i;
  }
}

int RecursiveBinary(vector<int>& arr, int& key, int low, int high) {
  if (low > high) {
    return -1;  // Result not found
  }

  int mid = (low + high)/2;

  if (arr[mid] == key) {
    return mid;
  }

  return key < arr[mid] ? RecursiveBinary(arr, key, low, mid - 1)
                        : RecursiveBinary(arr, key, mid + 1, high);
}

int main() {
  int result;
  int key = 34;

  // Linear Search
  vector<int> arr = { 73, 12, 57, 88, 34, 6, 95, 42, 19, 67 };
  cout << "Linear search:" << endl;
  result = LinearSearch(arr, key);
  if (result == -1)
    cout << "Could not find " << key << " in array" << endl;
  else
    cout << "Key found at index: " << result << endl;
  cout << endl;

  // Binary Search
  int low, high, mid;
  vector<int> values = { 6, 12, 19, 34, 42, 57, 67, 73, 88, 95 };
  result = BinarySearch(values, key, low, high, mid);
  cout << "Binary search:" << endl;
  if (result == -1)
    cout << "Could not find " << key << " in array" << endl;
  else
    cout << "Key found at index: " << result << " (low: " << low << ", mid: " << mid <<", high: " << high << ")" << endl;
  cout << endl;

  // Linear search with sentinel
  cout << "Linear search with sentinel:" << endl;
  result = LinearSearchSentinel(arr, key);
  if (result == -1)
    cout << "Could not find " << key << " in array" << endl;
  else
    cout << "Key found at index: " << result << endl;
  cout << endl;

  // Binary Search (Recursive)
  cout << "Binary search (recursive):" << endl;
  for (int i = 1; i <= 100; i++) {
    low = 0;
    high = values.size() - 1;
    result = RecursiveBinary(values, i, low, high);
    if (result == -1)
    cout << "Could not find " << i << " in array" << endl;
    else
    cout << i << " found at index: " << result << " (low: " << low << ", mid: " << mid <<", high: " << high << ")" << endl;
  }
  cout << endl;
}