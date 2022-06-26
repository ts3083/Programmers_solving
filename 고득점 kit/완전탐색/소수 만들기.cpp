#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool is_prime(int num) {
    if (num == 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int count = 0, sum = 0;
    int n = nums.size();
    vector<int> temp(n, 0);
    temp[0] = 1;
    temp[1] = 1;
    temp[2] = 1;

    do {
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (temp[i] == 1) {
                sum += nums[i]; 
            }
        }
        if (is_prime(sum)) {
            count++;
        }
    } while (prev_permutation(temp.begin(), temp.end()));

    return count;
}
