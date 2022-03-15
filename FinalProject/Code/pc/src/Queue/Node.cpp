/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 08/03/2022
 * File: Node.cpp
 */

#include "Node.h"

Node::Node(Datapkt data, Node* nxt)
{
    datapkt = data;
    next = nxt;
}

Datapkt Node::getData()
{
    return datapkt;
}

Node* Node::getNext()
{
    return next;
}

void Node::setData(Datapkt data)
{
    datapkt = data;
}

void Node::setNext(Node* nxt)
{
    next = nxt;
}