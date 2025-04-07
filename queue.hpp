#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;

namespace graph {
    class Queue {
    private:
        struct Node {
            int data;
            Node* next;
        };
        Node *front, *rear;
        int size;
    
    public:
        Queue() : front(nullptr), rear(nullptr), size(0) {}
        ~Queue(){
            this->clear();
        }
        void push(int value){
            Node* temp = new Node{value, nullptr};
            if (rear) rear->next = temp;
            else front = temp;
            rear = temp;
            this->size++;
        }
        int pop() {
            if (empty()) throw;
            Node* temp = front;
            int val = temp->data;
            front = front->next;
            if (!front) rear = nullptr;
            delete temp;
            this->size--;
            return val;
        }
        bool empty() const {
            return front == nullptr;
        }

        void clear(){
            while (!empty()) pop();
        }

        int getSize() const {
            return this->size;
        }

        int getFront() {
            return this->front->data;
        }

        void print(){
            for (Node* p = this->front; p != NULL; p = p->next){
                cout << p->data << " ";
            }
            cout << endl;
        }
    };
}

#endif // QUEUE_HPP
