 class MyCircularQueue {
public:
int *arr;
int size;
int qfront;
int rear;
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        rear = qfront = -1;
    }
     bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        else if(qfront==-1){
            qfront = rear = 0;
        }
        else{
            rear = (rear+1) %size;
        }
        arr[rear] = value;
        return true;
    }
    bool deQueue() {
        if(qfront == -1){
            return false;
        }
        if(qfront == rear){
            qfront = rear = -1;
        }
        else{
            qfront = (qfront +1) % size;
        }
        return true;
    }
    
    int Front() {
        if(qfront == -1){
            return -1;
        }
        return arr[qfront];
    }
    int Rear() {
        if(qfront==-1){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        return qfront == -1;
    }
    
    bool isFull() {
        return (qfront==0 && rear == size-1) || (qfront == rear+1);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */