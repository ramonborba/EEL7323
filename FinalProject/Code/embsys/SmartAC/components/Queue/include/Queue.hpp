/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 08/03/2022
 * File: Queue.h
 */
#ifndef QUEUE_H
#define QUEUE_H

#include "Node.hpp"



class Queue
{
private:
    Node* head;
    Node* tail;
public:
    Queue();
    ~Queue();

    void enqueue(uint32_t);
    void dequeue();
    
};

#endif  /* QUEUE_H */