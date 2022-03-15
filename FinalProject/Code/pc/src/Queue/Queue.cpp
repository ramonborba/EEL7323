/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 08/03/2022
 * File: Queue.cpp
 */
#include <iostream>
#include "Queue.h"


Queue::Queue ()
{
    head = 0;
    tail = 0;
}

Queue::~Queue()
{
    Node* aux;
    while (head)
    {
        aux = head;
        head = head->getNext();
        delete aux;
    }
}

void Queue::enqueue(Datapkt data)
{
    if (!tail)                                                  // Check if tail is not set (first node)
    {
        tail = new Node(data, nullptr);
    }
    else                                                        // Create new node and insert after current tail
    {
        Node* aux = new Node(data, nullptr);
        tail->setNext(aux);
        tail = aux;
    }

    if (!head)                                                  // Set the head if it's not set (first node)
    {
        head = tail;
    }
}

void Queue::dequeue()
{
    Node* aux = head;
    head = head->getNext();                                     // Point the head to the next node and delete current node
    delete aux;
    std::cout << "Dequeueing..." << std::endl;
}

void Queue::dateSearch(int min, int max)
{
    int val = 0;
    Node* scan = head;
    
    if (scan == nullptr)
    {
        std::cout << "Sem nodos na fila" << std::endl;
    }
    else
    {
        while (scan != nullptr)
        {
            val = scan->getData().pktn;                              // Placeholder search algorithm
            if ((val >= min) && (val <= max))
            {
                std::cout << std::endl;
                std::cout << "Pkt number: "<< scan->getData().pktn << std::endl;
                std::cout << "Value: " << scan->getData().val << std::endl;
                std::cout << "Msg: " << scan->getData().msg << std::endl;
            }
            scan = scan->getNext();
        }
    }
    return;
}

void Queue::printTotalTime()
{
    Node* scan = head;
    int val = 0;
    if (scan == nullptr)
    {
        std::cout << "Sem nodos na fila" << std::endl;
    }
    else
    {
        while (scan != nullptr)
        {
            val += scan->getData().val;                              // Placeholder adding algorithm
            scan = scan->getNext();
        }
        std::cout << "Total: " << val << std::endl;
    }
}