
//const {PriorityQueue} = require('@datastructures-js/priority-queue');

class MedianFinder {

    smallerNumbers = new MaxPriorityQueue({compare: (x, y) => y - x});
    largerNumbers = new MinPriorityQueue({compare: (x, y) => x - y});

    /** 
     * @param {number} num
     * @return {void}
     */
    addNum(num) {
        this.smallerNumbers.enqueue(num);
        this.largerNumbers.enqueue(this.smallerNumbers.dequeue());
        if (this.largerNumbers.size() > this.smallerNumbers.size()) {
            this.smallerNumbers.enqueue(this.largerNumbers.dequeue());
        }
    }

    /**
     * @return {number}
     */
    findMedian() {
        if (this.largerNumbers.size() < this.smallerNumbers.size()) {
            return this.smallerNumbers.front();
        }
        return (this.smallerNumbers.front() + this.largerNumbers.front()) * 0.5;
    }
}
