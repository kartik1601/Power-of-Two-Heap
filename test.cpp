#include"heap.h"

using namespace std;

int main(){
    Heap pq(1,10);
    pq.insert(10);
    pq.insert(20);
    pq.insert(0);
    pq.insert(110);
    pq.insert(5);
    cout << "Maximum element till now: " << pq.top() << endl;
    pq.insert(1000);
    pq.insert(1);
    cout << "Size of max heap: " << pq.size() << endl;
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}