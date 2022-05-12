#include<iostream>
#include "list.h"
#include "queue.h"
#include "stack.h"
using namespace std;

Node::Node(string data, linkedList* ref) {
    this->data = data;
    this->next = NULL;
    this->ref = ref;
}

void Node::insert(string data, linkedList* ref) {
    Node* temp = this;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(data, ref);
}

linkedList::linkedList() {}
linkedList::linkedList(string data) {
    this->root = NULL;
    this->data = data;
    this->visited = false;
}
void linkedList::insertAdjacent(queue* q) {
    Node* temp = root;
    while (temp != NULL) {
        if (!temp->ref->visited) {
            temp->ref->visited = true;
            q->push(temp->ref);
        }
        temp = temp->next;
    }
}

bool linkedList::insertAdjacent(stack* s) {
    Node* temp = root;
    bool allvisited = true;
    while (temp != NULL) {
        if (!temp->ref->visited) {
            allvisited = false;
            temp->ref->visited = true;
            s->push(temp->ref);
            cout << temp->ref->getData() << endl;
            break;
        }
        temp = temp->next;
    }
    return !allvisited;
}

string linkedList::getData() {
    return this->data;
}
void linkedList::insert(string data, linkedList* ref) {
    if (root) {
        root->insert(data, ref);
    } else {
        root = new Node(data, ref);
    }
}

void linkedList::del(string data) {
    if (root) {
        root = root->del(data);
    }
}

bool linkedList::search(string data) {
    if (root) {
        return root->search(data);
    }
    return false;
}

void linkedList::display() {
    if (root) {
        root->display();
    }
}

queue::queue(int n) {
    this->n = n;
    this->list = new linkedList*[n];
    this->front = -1;
    this->rear = -1;
}

void queue::push(linkedList* node) {
    if (rear == -1) {
        front++;
    }
    list[++rear] = node;
}

void queue::display() {
    cout << "Queue contents are : " << endl;
    for (int i = front; i < rear; i++) {
        list[i]->getData();
    }
}

linkedList* queue::pop() {
    if (front == rear) {
        rear = -1;
        linkedList* temp = list[front];
        front = -1;
        return temp;
    }
    return list[front++];
}

queue::~queue() {
    delete[] list;
}

stack::stack(int n) {
    list = new linkedList*[n];
    top = -1;
}
void stack::push(linkedList* node) {
    list[++top] = node;
}

bool stack::isEmpty() {
    return top == -1;
}
linkedList* stack::pop() {
    return list[top--];
}

linkedList* stack::peek() {
    return list[top];
}

stack::~stack() {
    delete[] list;
}

class Graph {
    linkedList* adjacency_list;
    stack* dfs_stack;
    queue* bfs_queue;
    int v;
    void resetVisited() {
        for (int i = 0; i < this->v; i++) {
            adjacency_list[i].visited = false;
        }
    }

   public:
    Graph(int n) {
        this->v = n;
        this->adjacency_list = new linkedList[n];
        this->dfs_stack = new stack(n);
        this->bfs_queue = new queue(n);
    }
    void initialize() {
        string data;
        linkedList* temp;
        for (int i = 0; i < this->v; i++) {
            cout << "Enter the landmark name of node " << i + 1 << " : ";
            cin >> data;
            adjacency_list[i] = linkedList(data);
        }
        for (int i = 0; i < this->v; i++) {
            cout << "Enter the landmarks which are connected to " << adjacency_list[i].getData() << " : ";
            while (true) {
                cin >> data;  // Extra Computation
                for (int j = 0; j < this->v; j++) {
                    if (data == adjacency_list[j].getData()) {
                        temp = adjacency_list + j;
                        break;
                    }
                }
                adjacency_list[i].insert(data, temp);
                if (cin.peek() == '\n') {
                    break;
                }
            }
        }
    }
    void display() {
        for (int i = 0; i < this->v; i++) {
            cout << "|" << adjacency_list[i].getData() << "|";
            adjacency_list[i].display();
        }
    }

    void bfs_search() {
        linkedList* temp;
        for (int i = 0; i < v; i++) {
            if (!adjacency_list[i].visited) {
                adjacency_list[i].visited = true;
                bfs_queue->push(adjacency_list + i);
            }
            temp = bfs_queue->pop();
            temp->insertAdjacent(bfs_queue);
            cout << temp->getData() << endl;
        }
        resetVisited();
    }

    void dfs_search() {
        linkedList* temp;
        if (!adjacency_list[0].visited) {
            adjacency_list[0].visited = true;
            dfs_stack->push(adjacency_list);
            cout << adjacency_list[0].getData()<<endl;
        }
        while (!dfs_stack->isEmpty()) {
            temp = dfs_stack->peek();
            if (!temp->insertAdjacent(dfs_stack)) {
                temp = dfs_stack->pop();
            }
        }
        resetVisited();
    }

    ~Graph() {
        delete[] adjacency_list;
        delete bfs_queue;
        delete dfs_stack;
    }
};

int main() {
    int n;
    cout << "Enter the number of vertices in graph : ";
    cin >> n;
    Graph g(n);
    g.initialize();
    g.display();
    cout << "BFS of graph is defined as : ";
    g.bfs_search();
    cout << "DFS of graph is defined as : ";
    g.dfs_search();
    return 0;
}
