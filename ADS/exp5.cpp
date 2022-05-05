#include <iostream>
#include <string>

using namespace std;

class Node {
    string word;
    string meaning;
    Node* next;

   public:
    Node(string word, string meaning) {
        this->word = word;
        this->meaning = meaning;
        this->next = NULL;
    }
    void insert(string word, string meaning) {
        Node* temp = this;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new Node(word, meaning);
    }

    Node* del(string word) {
        Node* temp;
        if (this->word == word) {
            temp = this->next;
            delete this;
            return temp;
        } else {
            temp = this;
            while (temp->next != NULL && temp->next->word != word) {
                temp = temp->next;
            }
            Node* tobeDel = temp->next;
            temp->next = temp->next->next;
            delete tobeDel;
            return this;
        }
    }

    string search(string word) {
        Node* temp = this;
        while (temp && temp->word != word) {
            temp = temp->next;
        }
        if (temp) {
            return temp->meaning;
        } else {
            return "";
        }
    }

    void display() {
        Node* temp = this;
        while (temp) {
            cout << temp->word << " : " << temp->meaning << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class linkedList {
    Node* root;

   public:
    linkedList() { root = NULL; }
    void insert(string word, string meaning) {
        if (root) {
            root->insert(word, meaning);
        } else {
            root = new Node(word, meaning);
        }
    }

    void del(string word) {
        if (root) {
            root = root->del(word);
        }
    }

    string search(string word) {
        if (root) {
            return root->search(word);
        }
        return "";
    }

    void display() {
        if (root) {
            root->display();
        }
    }
};

class HashTable {
    linkedList** records;
    int size;

    int calculateHash(string word) {
//        int hash = 0;
//        for (int i = 0; i < word.length(); i++) {
//            hash += (word[i] * (i + 1));
//        }
//        return hash % size;
			int length=word.length();
			return length%size;
    }

   public:
    HashTable(int n) {
        this->size = n;
        this->records = new linkedList*[n];
        for (int i = 0; i < this->size; i++) {
            this->records[i] = NULL;
        }
    }

    void insert(string word, string meaning) {
        int index = calculateHash(word);
        if (records[index] == NULL) {
            records[index] = new linkedList();
        }
        records[index]->insert(word, meaning);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (records[i]) {
                records[i]->display();
            } else {
                cout << "0" << endl;
            }
        }	
    }

    ~HashTable() { delete[] records; }

    string search(string word) {
        int index = calculateHash(word);
        if (records[index] == NULL) {
            return "";
        } else {
            return records[index]->search(word);
        }
    }

    void del(string word) {
        int index = calculateHash(word);
        if (records[index]) {
            records[index]->del(word);
        }
    }
};

int main() {
    string word, meaning;
    HashTable directory(10);
    int choice = 1;	
    while (choice) {
        cout << "Enter 1 to insert" << endl;
        cout << "Enter 2 to search" << endl;
        cout << "Enter 3 to display" << endl;
        cout << "Enter 4 to delete" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "Enter the word that you want to insert : ";
            cin >> word;
            cout << "Enter the meaning of word : ";
            cin >> meaning;
            directory.insert(word, meaning);
        } else if (choice == 2) {
            cout << "Enter the word that you want to search for its meaning : ";
            cin >> word;
            string meaning = directory.search(word);
            if (meaning == "") {
                cout << "Meaning not found" << endl;
            } else {
                cout << meaning << " found" << endl;
            }
        } else if (choice == 3) {
            cout << "HashTable is :" << endl;
            directory.display();
        } else if (choice == 4) {
            cout << "Enter the word that you want to delete : " << endl;
            cin >> word;
            directory.del(word);
        }
    }
    return 0;
}
