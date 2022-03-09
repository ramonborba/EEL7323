/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 08/03/2022
 * File: Queue.h
 */

#include "Node.h"


class Queue
{
private:
    Node* head;
    Node* tail;
public:
    Queue();
    ~Queue();

    void enqueue(datapkt_t);
    void dequeue();
    
    void dateSearch(int, int);                          // Displays Log information between dates
    void printTotalTime();                              // Displays total time the AC was powered
};

