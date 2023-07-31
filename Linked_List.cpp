
#include <iostream>
#include <algorithm>
#include <string>


struct State {
    std::string name;
    std::string arrow;
};

class LinkedList {

private:
    struct Node {
        State state;
        Node* next;

        Node() {
            next = nullptr;
        }

        Node(State aState) {
            state = aState;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size = 0;

public :
    LinkedList();
    ~LinkedList();
    void oddOrEven();
    void Append(State state);
    void Prepend(State state);
    void PrintList();
    int Size();
};

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
};

LinkedList::~LinkedList() {
    Node* currentNode = head;
    Node* tmp;

    while (currentNode != nullptr) {
        tmp = currentNode;
        currentNode = currentNode->next;
        delete tmp;
        
    }
}

void LinkedList::Append(State state) {
    Node* new_node = new Node(state);

    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    }else {
        tail->next = new_node;
        tail = new_node;
    }
    size += 1;
};


void LinkedList::Prepend(State state) {
    Node* new_node = new Node(state);

    if (head != nullptr) {
        new_node->next = head;

    }
    head = new_node;
    size += 1;
};

void LinkedList::PrintList() {
    Node* current_node = head;

    while (current_node != nullptr) {
        std::cout << current_node->state.name << " " << current_node->state.arrow << " ";
        current_node = current_node->next;
    }
};


int LinkedList::Size() {
    return size;
};

void LinkedList::oddOrEven() {
    Node* current_node = head;
    int counter = 0;
    while (current_node != nullptr) {
        counter += 1;
        current_node = current_node->next;
    }
    if (counter % 2 == 0) {
        std::cout << " The linked list is even" << std::endl;;
    }
    else {
        std::cout << "The linked list is odd" << std::endl;;
    }
};

void menu() {
    std::cout << "\n";
    std::cout << "1. Add a state to the end of the list. " << std::endl;
    std::cout << "2. Add a state to the beginning of the list. " << std::endl;
    std::cout << "3. Display all states. " << std::endl;
    std::cout << "4. Check if State list is odd or even. " << std::endl;
    std::cout << "9. Exit program. " << std::endl;
};

int menuValidation(int choice) {
    while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4) && (choice != 9)) {
        std::cout << choice << " is not a valid option." << std::endl;
        std::cin >> choice;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Only Integers '1, 2, 3, or 9' are valid options" << std::endl;
            std::cin >> choice;
        }
    }
   
    return choice;
}

int main()
{
    
    LinkedList stateList;
    State state;
    std::string stateName;
    int choice;
    int i = stateList.Size();

    int menuChoice;
    do {
        menu();
        std::cin >> menuChoice;
        menuChoice = menuValidation(menuChoice);

        switch (menuChoice) {

        case 1:
            std::cout << "Enter a state name: \n";
            std::cin >> state.name;
            state.arrow = "->";
            stateList.Append(state);            
            break;

        case 2:
            std::cout << "Enter a state name: \n";
            std::cin >> state.name;
            state.arrow = "->";
            stateList.Prepend(state);
            break;

        case 3:
            stateList.PrintList();
            break;

        case 4:
            std::cout << "The linked list has: " << stateList.Size() << " node(s)." << std::endl;
            stateList.oddOrEven();
            break;
        }
    } 
    while (menuChoice != 9);

    return 0;
}


