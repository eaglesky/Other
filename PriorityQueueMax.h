#include <vector>

class PriorityQueueMax {
public:
    PriorityQueueMax():length(0), heapSize(0){}
    void insert(int key);
    bool increaseKey(int id, int newKey);
    bool getMaxKey(int& maxOut) ;
    bool extractMax(int& maxOut);
    void printHeap();
    int size() { return heapSize; }
    int key(int id) {return heap.at(id);}

    static int parent(int id) {return (id - 1)/2;}
    static int left(int id) {return 2*id + 1;}
    static int right(int id) {return 2*id + 2;}


    static void maxHeapify(std::vector<int>& hp, int size, int id);
    static void buildHeap(std::vector<int>& hp);
    static void heapSort(std::vector<int>& vec);

private:
    std::vector<int> heap;
    int length;
    int heapSize;
};


