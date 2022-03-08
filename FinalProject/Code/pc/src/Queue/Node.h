/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 08/03/2022
 * File: Node.h
 */



class Node
{
protected:
    int datapkt;                            // placeholder for embedded system data packet(TBD)
    Node* next;                             // Pointer to next node

public:
    Node(int datapkt, Node* next);          
    ~Node();

    int getData();
    Node* getNext();
    void setData(int data);
    void setNext(Node* nxt);
};