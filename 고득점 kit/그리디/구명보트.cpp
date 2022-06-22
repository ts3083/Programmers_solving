#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> people, int limit) {
    int count = 0;
    int n = people.size();
    sort(people.begin(), people.end(), compare);
    
    int i = 0, j = n - 1;
    while (i <= j) {
        if (people[i] + people[j] > limit) {
            count++;
            i++;
        }
        else {
            count++;
            i++;
            j--;
        }
    }  
    
    return count;
}
