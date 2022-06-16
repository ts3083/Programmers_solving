#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(string str) {
    int num = stoi(str);
    if (num == 0 || num == 1)
        return false;
    
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    string str_temp;
    set<int> s;
    
    sort(numbers.begin(), numbers.end());
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            str_temp = numbers.substr(0, i);
            if (isPrime(str_temp)) {
                s.insert(stoi(str_temp));
            }
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    return s.size();
}
