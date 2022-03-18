/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 08/03/2022
 * File: Node.h
 */

#ifndef NODE_H
#define NODE_H

#include <stdint.h>

class Node
{
protected:
    uint32_t datapkt;                      // Data packet information
    Node* next;                             // Pointer to next node

public:
    Node(uint32_t datapkt, Node* next);          
    
    uint32_t getData();
    Node* getNext();
    void setData(uint32_t data);
    void setNext(Node* nxt);
};

#endif  /* NODE_H */