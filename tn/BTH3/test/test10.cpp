#include <iostream>
#include <vector>

int n, h; // Assume n and h are defined globally
std::vector<int> x; // Global array to store the binary sequence

void out() {
    // Function to output the current sequence
    for (int i = 1; i <= n; ++i) {
        std::cout << x[i];
    }
    std::cout << std::endl;
}

void Try(int pos, int count) {
    for (int i = 0; i <= 1; i++) {
        x[pos] = i;
        int new_count = count;
        if (x[pos] == 1) {
            new_count = count + 1;
        }
        if (pos == n) {
            if (new_count == h) out();
        } else {
            Try(pos + 1, new_count);
        }
    }
}

int main() {
    // Initialize n and h
    n = 4; // Example value
    h = 2; // Example value
    x.resize(n + 1); // Resizing vector to store n elements, +1 for 1-based indexing

    Try(1, 0); // Start with position 1 and count 0

    return 0;
}
