//Delete a node from a singly-linked list, ↴ given only a variable pointing to that node
#include<iostream>
#include<stdexcept>

class LinkedList{
    public:
        int data;
        LinkedList * next;
        LinkedList(int value):
        data(value),next(nullptr)
        {}
};

void delete_node(LinkedList * nodeToDelete){
    LinkedList * nextNode = nodeToDelete->next;
    if(nextNode){
        nodeToDelete->data = nextNode->data;
        nodeToDelete->next = nextNode->next;
        delete(nextNode);
    }
    else{
        throw std::invalid_argument("Can not delete with this technique");
    }
}

int main(){
    LinkedList * a = new LinkedList(1);
    LinkedList * b = new LinkedList(2);
    LinkedList * c = new LinkedList(3);
    a->next = b;
    b->next = c;
    delete_node(b);
    return 0;
}