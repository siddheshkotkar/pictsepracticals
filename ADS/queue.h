#ifndef QUEUE_
#define QUEUE_

class linkedList;

class queue {
    int front, rear;
    int n;
    linkedList** list;

   public:
    queue(int n);
    void push(linkedList* node);
    bool isEmpty();
    void display();
    linkedList* pop();
    ~queue();
};

#endif /* QUEUE_ */
