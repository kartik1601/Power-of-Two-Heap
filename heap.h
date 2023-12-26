#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

// template <typename T>

class Heap{
private:
    vector<long long> priority_queue;
    int childrenPower=2;
    /*  for a binary heap     -> parent => i :: children => 2*i+1 and 2*i+2 
        for a quaternary heap -> parent => i :: children => 4*i+1, 4*i+2, 4*i+3 and 4*i+4
        for a 2^x-ary heap    -> parent => i :: children => (2^x)+i , where i ∈ {1,2,3.....,2^x}
    */

public:
    Heap(int x,int size=1e5){
        if(x>=0){ // ensure it is a valid children count, otherwise keep '2' as default
            childrenPower = pow(2,x);
        }
        priority_queue.reserve(size);
    }

    void heapify(int parent=0){
        int prevLargest = parent;
        int current = childrenPower * parent + 1; // Initialize with the first child
        int counter = 1; // counter increments till the number of children => '2^x'

        while (counter <= childrenPower && current < priority_queue.size()) {
            if (priority_queue[current] > priority_queue[prevLargest]) {
                prevLargest = current;
            }
            current = childrenPower * parent + (++counter);
        }

        if (parent != prevLargest) {
            swap(priority_queue[parent], priority_queue[prevLargest]);
            heapify(prevLargest);
        }
    }


    void insert(int value){
        priority_queue.push_back(value);
        int idx = priority_queue.size()-1;
        int parent = (idx-1)/childrenPower;

        while(idx>0 && priority_queue[idx] > priority_queue[parent]){
            swap(priority_queue[idx],priority_queue[parent]);
            idx = parent;
            parent = (parent-1)/childrenPower;
        }
    }

    int top(){
        return priority_queue[0];
    }

    void pop(){
        if(!priority_queue.empty()){
            int top=priority_queue[0];
            int sz = priority_queue.size();
            swap(priority_queue[0],priority_queue[sz-1]);
            priority_queue.pop_back(); // to discard the last element, i.e., the popped max
            heapify(0);
        }
    }

    int size(){
        return priority_queue.size();
    }

    bool empty(){
        return priority_queue.size()==0;
    }
};
