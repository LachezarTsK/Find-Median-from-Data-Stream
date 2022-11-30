
import java.util.Comparator;
import java.util.PriorityQueue;

public class MedianFinder {

    PriorityQueue<Integer> smallerNumbers;
    PriorityQueue<Integer> largerNumbers;

    public MedianFinder() {
        smallerNumbers = new PriorityQueue<>(Comparator.reverseOrder());
        largerNumbers = new PriorityQueue<>();
    }

    public void addNum(int num) {
        smallerNumbers.add(num);
        largerNumbers.add(smallerNumbers.poll());
        if (largerNumbers.size() > smallerNumbers.size()) {
            smallerNumbers.add(largerNumbers.poll());
        }
    }

    public double findMedian() {
        if (largerNumbers.size() < smallerNumbers.size()) {
            return smallerNumbers.peek();
        }
        return (smallerNumbers.peek() + largerNumbers.peek()) * 0.5;
    }
}
