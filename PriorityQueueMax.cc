#include "PriorityQueueMax.h"
#include <iostream>
#include <ctime>

void PriorityQueueMax::insert(int key)
{
    heap.push_back(key - 1);
    length++;
    heapSize++;
    increaseKey(heapSize-1, key);
}

bool PriorityQueueMax::increaseKey(int id, int newKey)
{
    if (newKey <= heap.at(id)) {
        std::cout << "New key is not greater than the original!" << std::endl;
        return false;
    }

    heap[id] = newKey;

    while ((id > 0) && (heap[parent(id)] < newKey)) {
        int tmp = heap[parent(id)];
        heap[parent(id)] = heap[id];
        heap[id] = tmp;
        id = parent(id);
    }
    
    return true;
}

bool PriorityQueueMax::getMaxKey(int& maxOut)
{
    if (heapSize == 0)
        return false;
    maxOut = heap[0];
    return true;
}

bool PriorityQueueMax::extractMax(int& maxOut)
{
    if (heapSize==0)
        return false;

    maxOut = heap[0];
    heap[0] = heap[heapSize-1];
    heap[heapSize-1] = maxOut;
    
    heapSize--;
    maxHeapify(heap, heapSize, 0);

    heap.pop_back();
    length--;

    return true;
}

void PriorityQueueMax::printHeap()
{
    int nlCount = 1;

    for (int i = 0; i < heap.size(); i++)
    {
        if (i+1 == nlCount) {
            std::cout << std::endl;
            nlCount *= 2;
        }   

        std::cout << heap[i] << ", ";
    }
    std::cout << std::endl;
  
}

void PriorityQueueMax::maxHeapify(std::vector<int>& hp, int size, int id)
{
    while((left(id)<size)||(right(id)<size)) {
        int largestId = id;
        int largestKey = hp[id];
        if ((left(id) < size)&&(largestKey < hp[left(id)])) {

            largestId = left(id);
            largestKey = hp[left(id)];
        }

        if ((right(id)<size)&&(largestKey < hp[right(id)])) {
            largestId = right(id);
            largestKey = hp[largestId];
        }

        if (id != largestId) {
            int tmp = hp[id];
            hp[id] = hp[largestId];
            hp[largestId] = tmp;
        } else
            break;

        id = largestId;
    }
}

void PriorityQueueMax::buildHeap(std::vector<int>& hp)
{
    int id = parent(hp.size()-1);
    for(; id >= 0; id-- )
    {
        maxHeapify(hp, hp.size(), id);
    }
}

void PriorityQueueMax::heapSort(std::vector<int>& vec)
{
    buildHeap(vec);
    for (int i = vec.size() - 1; i >= 1; i--)
    {
        int tmp = vec[0];
        vec[0] = vec[i];
        vec[i] = tmp;
        maxHeapify(vec, i, 0);
    }
}

void printVec(std::vector<int>& vec)
{
    for (auto i : vec)
    {
        std::cout << i << ", ";
    }
}

int main(int argc, char** argv)
{

    srand(time(NULL));
    std::vector<int> t1;
    for (int j = 0; j < 40; j++)
    {
        int key = rand() % 100;
        t1.push_back(key);
    }

    std::cout << "Test1: ";
    printVec(t1);
    std::cout << std::endl;
    std::cout << "HeapSorted: ";
    PriorityQueueMax::heapSort(t1);
    printVec(t1);
    std::cout << std::endl;

    std::vector<int> t2;
    t2.push_back(2);

    std::cout << "Test2: ";
    printVec(t2);
    std::cout << std::endl;
    std::cout << "HeapSorted: ";
    PriorityQueueMax::heapSort(t2);
    printVec(t2);
    std::cout << std::endl;

    std::vector<int> t3;

    std::cout << "Test3: ";
    printVec(t3);
    std::cout << std::endl;
    std::cout << "HeapSorted: ";
    PriorityQueueMax::heapSort(t3);
    printVec(t3);
    std::cout << std::endl;
    std::cout << std::endl;

    PriorityQueueMax pq;

    
    for (int i = 0; i < 40; i++)
    {
        int key = rand()%100;
        pq.insert(key);
    }

    std::cout << "PriorityQueueMax content 40: ";
    pq.printHeap();
    int max = 0;
    pq.getMaxKey(max);
    std::cout << "Max: " << max << std::endl;

    pq.increaseKey(10, 88);
    std::cout << "After increase 10th key to 88: ";
    pq.printHeap();

    std::cout << std::endl;
    std::cout << "Extract them all: " << std::endl;
    for (int i = 0; i < 40; i++)
    {
        int max = -1;
        if (pq.extractMax(max))
            std::cout << max << ", ";
    }
    std::cout << std::endl;

    return 0;
}


