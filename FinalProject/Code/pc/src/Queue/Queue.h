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
    void dequeue();
    void enqueue();
    void dateSearch();
    void printTotalTime();
};

