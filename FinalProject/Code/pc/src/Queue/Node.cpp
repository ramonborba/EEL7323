/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 08/03/2022
 * File: Node.cpp
 */

#include "Node.h"

Node::Node(datapkt_t data, Node* nxt)
{
    datapkt = data;
    next = nxt;
}

datapkt_t Node::getData()
{
    return datapkt;
}

Node* Node::getNext()
{
    return next;
}

void Node::setData(datapkt_t data)
{
    datapkt = data;
}

void Node::setNext(Node* nxt)
{
    next = nxt;
}