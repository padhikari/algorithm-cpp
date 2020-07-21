#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define MAX_SIZE 6
int front = -1, rear = -1;
int queue[MAX_SIZE];

bool isEmpty();
bool isFull();
void enqueue(int data);
int dequeue();

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    int data =dequeue();
    enqueue(7);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}

bool isEmpty(){
    if(front == -1)
        return true;
    return false;
}
bool isFull(){
    if((rear+1) % MAX_SIZE == front)
        return true;
    return false;
}
void enqueue(int data){
    if(isFull()){
        printf("Queue is full\n");
        return;
    }
    else if(isEmpty()){
        front++;
    }
    rear = (rear+1)%MAX_SIZE;
    queue[rear] = data;
    printf("Front = %d, Rear = %d, data = %d",front, rear, data);
    printf("\n");
}
int dequeue(){
    if(isEmpty()){
        printf("The queue is empty\n");
        return INT_MIN;
    }
    int temp = queue[front];
    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1)%MAX_SIZE;
    }
    printf("Front = %d, Rear = %d, data = %d",front, rear, temp);
    printf("\n");
    return temp;
}