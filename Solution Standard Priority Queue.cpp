
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
    
    priority_queue<int> smallerNumbers;
    /*
     greater<> instead of greater<int>
     Applying transparent operator for Standard Library containers that accept a comparator type 
     can be more performant compared to using a non-transparent operator.
    */
    priority_queue<int, vector<int>, greater<>> largerNumbers;

public:
    void addNum(int num) {
        smallerNumbers.push(num);
        int value = smallerNumbers.top();
        smallerNumbers.pop();
        largerNumbers.push(value);

        if (largerNumbers.size() > smallerNumbers.size()) {
            value = largerNumbers.top();
            largerNumbers.pop();
            smallerNumbers.push(value);
        }
    }

    double findMedian() const {
        if (largerNumbers.size() < smallerNumbers.size()) {
            return smallerNumbers.top();
        }
        return (smallerNumbers.top() + largerNumbers.top()) * 0.5;
    }
};
