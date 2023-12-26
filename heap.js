class Heap {
    constructor(x, size = 1e5) {
        this.priorityQueue = [];
        this.childrenPower = Math.pow(2, x);
        this.size = size;
    }

    heapify(parent = 0) {
        let prevLargest = parent;
        let current = this.childrenPower * parent + 1; // Initialize with the first child
        let counter = 1; // counter increments till the number of children => '2^x'

        while (counter <= this.childrenPower && current < this.priorityQueue.length) {
            if (this.priorityQueue[current] > this.priorityQueue[prevLargest]) {
                prevLargest = current;
            }
            current = this.childrenPower * parent + (++counter);
        }

        if (parent !== prevLargest) {
            [this.priorityQueue[parent], this.priorityQueue[prevLargest]] = [this.priorityQueue[prevLargest], this.priorityQueue[parent]];
            this.heapify(prevLargest);
        }
    }

    insert(value) {
        this.priorityQueue.push(value);
        let idx = this.priorityQueue.length - 1;
        let parent = Math.floor((idx - 1) / this.childrenPower);

        while (idx > 0 && this.priorityQueue[idx] > this.priorityQueue[parent]) {
            [this.priorityQueue[idx], this.priorityQueue[parent]] = [this.priorityQueue[parent], this.priorityQueue[idx]];
            idx = parent;
            parent = Math.floor((parent - 1) / this.childrenPower);
        }
    }

    top() {
        return this.priorityQueue[0];
    }

    pop() {
        if (this.priorityQueue.length > 0) {
            const top = this.priorityQueue[0];
            const sz = this.priorityQueue.length;
            [this.priorityQueue[0], this.priorityQueue[sz - 1]] = [this.priorityQueue[sz - 1], this.priorityQueue[0]];
            this.priorityQueue.pop(); // to discard the last element, i.e., the popped max
            this.heapify(0);
            return top;
        }
    }

    size() {
        return this.priorityQueue.length;
    }

    empty() {
        return this.priorityQueue.length === 0;
    }
}

// Example usage:
const pq = new Heap(2); // Adjust the childrenPower as needed
pq.insert(10);
pq.insert(20);
pq.insert(0);
pq.insert(110);
pq.insert(5);
console.log("Maximum element till now:", pq.top());
pq.insert(1000);
pq.insert(1);
// console.log("Size of max heap:", pq.size());
while (!pq.empty()) {
    console.log(pq.pop());
}
