#include <iostream>

class Node {
public:
    int key;
    Node* p;
    Node() : key(0), p(nullptr) {}
};

class Stack {
private:
    Node* top;
    int size;
    int capacity;
public:
    Stack() : top(nullptr), size(0), capacity(10) {}
    Stack(int cap) : top(nullptr), size(0), capacity(cap) {}

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->p;
            delete temp;
        }
    }
    bool is_empty() {
        return top == nullptr;
    }

    bool is_full() {
        return size == capacity;
    }

    void copy_stack(Stack& new_stack) {
        Node* temp = top;
        while (temp != nullptr) {
            Node* new_node = new Node();
            new_node->key = temp->key;
            new_node->p = new_stack.top;
            new_stack.top = new_node;
            temp = temp->p;
        }
    }

    void push(int value) {
        if (is_full()) {
            std::cout << "Stack is full" << std::endl;
            return;
        }
        Node* new_node = new Node();
        new_node->key = value;
        new_node->p = top;
        top = new_node;
        size++;
    }

    void pop() {
        if (is_empty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        Node* temp = top;
        top = top->p;
        std::cout << "Popped value: " << temp->key << std::endl;
        delete temp;
        size--;
    }

    void remove() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->p;
            delete temp;
        }
        size = 0;
    }

    void print_length() {
        std::cout << "Stack length: " << size << std::endl;
    }

    void print_stack() {
        Node* temp = top;
        std::cout << "Stack: ";
        while (temp != nullptr) {
            std::cout << temp->key << " ";
            temp = temp->p;
        }
        std::cout << std::endl;
    }
    void print_menu() {
        std::cout << "Select an operation:" << std::endl;
        std::cout << "1. Push an element" << std::endl;
        std::cout << "2. Pop an element" << std::endl;
        std::cout << "3. Print the stack" << std::endl;
        std::cout << "4. Get the stack length" << std::endl;
        std::cout << "5. Exit" << std::endl;
    }

    // Функция для обработки выбора пользователя
    void process_operation() {
        int choice;
        do {
            print_menu();
            std::cin >> choice;
            switch (choice) {
            case 1:
                int value;
                std::cout << "Enter the value to push: ";
                std::cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                print_stack();
                break;
            case 4:
                print_length();
                break;
            case 5:
                Stack newStack;
                copyStack(newStack);
                std::cout << "Stack copied to new object." << std::endl;
                break;
            case 6:
                std::cout << "Exiting the program" << std::endl;
                exit(0);
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } while (choice != 5);
    }
};

int main() {
    Stack my_stack(5);
    my_stack.process_operation();
    return 0;
}
