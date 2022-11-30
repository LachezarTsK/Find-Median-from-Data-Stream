
#include <queue>
#include <vector>
using namespace std;

template<typename T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type>>
class CustomizedPriorityQueue : public priority_queue<T, Container, Compare> {
    
public:
    T poll() {
        T value = priority_queue<T, Container, Compare>::top();
        priority_queue<T, Container, Compare>::pop();
        return value;
    }
};

class MedianFinder {
    
    CustomizedPriorityQueue<int> smallerNumbers;
    /*
     greater<> instead of greater<int>
     Applying transparent operator for Standard Library containers that accept a comparator type 
     can be more performant compared to using a non-transparent operator.
     Although it is a customized priority queue, it is a wrapper class over std::priority_queue 
     and uses all its functionalities.
    */
    CustomizedPriorityQueue<int, vector<int>, greater<>> largerNumbers;

public:
    void addNum(int num) {
        smallerNumbers.push(num);
        largerNumbers.push(smallerNumbers.poll());
        if (largerNumbers.size() > smallerNumbers.size()) {
            smallerNumbers.push(largerNumbers.poll());
        }
    }

    double findMedian() const {
        if (largerNumbers.size() < smallerNumbers.size()) {
            return smallerNumbers.top();
        }
        return (smallerNumbers.top() + largerNumbers.top()) * 0.5;
    }
};
