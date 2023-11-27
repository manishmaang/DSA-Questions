#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; // length of the binary string
    int k; // number of ones in the binary string

    cout << "Enter the length of the binary string: ";
    cin >> n;

    cout << "Enter the number of ones in the binary string: ";
    cin >> k;

    // Create a vector to represent the binary string
    vector<int> binaryString(n, 1);

    // Place the ones in the binary string
    for (int i = n - 1; i >= n - k; --i) {
        binaryString[i] = 0;
    }

    // Shuffle the binary string to minimize consecutive zeros
    random_shuffle(binaryString.begin(), binaryString.end());

    // Find the length of the least consecutive zeros
    int minZeroLength = n; // Initialize with the maximum possible value
    int currentZeroLength = 0;

    for (int i = 0; i < n; ++i) {
        if (binaryString[i] == 0) {
            currentZeroLength++;
        } else {
            minZeroLength = min(minZeroLength, currentZeroLength);
            currentZeroLength = 0;
        }
    }

    // Check for the last block of zeros
    minZeroLength = min(minZeroLength, currentZeroLength);

    // Print the result
    cout << "Length of the least consecutive zeros: " << minZeroLength << endl;

    return 0;
}
