/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 08/03/2022
 * File: Node.h
 */

#include "datapkt.h"

class Node
{
protected:
    datapkt_t datapkt;                      // Data packet information
    Node* next;                             // Pointer to next node

public:
    Node(datapkt_t datapkt, Node* next);          
    
    datapkt_t getData();
    Node* getNext();
    void setData(datapkt_t data);
    void setNext(Node* nxt);
};