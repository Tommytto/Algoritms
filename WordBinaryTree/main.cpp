using namespace std;

#include <iostream>
#include <fstream>

template <typename T>
struct Node
{
    const T name;
    Node * left;
    Node * right;
    Node * parent;
    Node(T name): name(name) {}
};

template <typename T>
struct Tree
{
    Node<T> * top;
    void insert(Node<T> * node) {
        Node<T> * parentNode = top;
        Node<T> * tempParentNode = top;

        while (true) {
            if (tempParentNode) {
                parentNode = tempParentNode;
                if (node->name < parentNode->name) {
                    tempParentNode = parentNode->left;
                } else if (node->name > parentNode->name) {
                    tempParentNode = parentNode->right;
                } else {
                    break;
                }
            } else {
                if (node->name < parentNode->name) {
                    parentNode->left = node;
                    node->parent = parentNode;
                } else {
                    parentNode->right = node;
                    node->parent = parentNode;
                }
                break;
            }
        }
    };

    Node<T> * search(const T toSearch) {
        Node<T> * parentNode = top;
        Node<T> * tempParentNode = top;

        while (true) {
            if (tempParentNode) {
                parentNode = tempParentNode;
                if (toSearch < parentNode->name) {
                    tempParentNode = parentNode->left;
                } else if (toSearch > parentNode->name) {
                    tempParentNode = parentNode->right;
                } else {
                    return parentNode;
                }
            } else return nullptr;
        }
    };

    void straightRun(Node<T> * node) {
        if (node) {
            cout << node->name << endl;
            if (node->left) {
                straightRun(node->left);
            }
            if (node->right) {
                straightRun(node->right);
            }
        }
    }

    void backRun(Node<T> * node) {
            if (node->left) {
                backRun(node->left);
            }
            if (node->right) {
                backRun(node->right);
            }
            cout << node->name << endl;
    }
};

template <typename T>
struct ListNode
{
    const T name;
    ListNode * next;
    ListNode(T name): name(name) {}
};

template <typename T>
struct List
{
    ListNode<T> * first;
    void insert(ListNode<T> * node) {
        ListNode<T> * prevCurrNode = first;
        ListNode<T> * currNode = first;

        while(true) {
            if (currNode) {
                if (node->name > currNode->name) {
                    prevCurrNode = currNode;
                    currNode = currNode->next;
                } else if (node->name < currNode->name) {
                    if (first->name == currNode->name) {
                        ListNode<T> * tempNode = first;
                        first = node;
                        first->next = tempNode;
                    } else {
                        ListNode<T> * tempNode = prevCurrNode->next;
                        prevCurrNode->next = node;
                        node->next = tempNode;
                    }
                    break;
                } else break;
            } else {
                prevCurrNode->next = node;
                break;
            }
        }
    };

    ListNode<T> * search(const T toSearch) {
        ListNode<T> * currNode = first;

        while (true) {
            if (currNode) {
                if (currNode->name == toSearch) {
                    return currNode;
                } else {
                    currNode = currNode->next;
                }
            } else return nullptr;
        }
    };
};

int main() {
    Tree<string> * tree = new Tree<string>();
    List<string> * list = new List<string>();

    ifstream fin("text.txt");
    string word;

    while (!fin.eof()) {
        fin >> word;

        if (!tree->top) {
            tree->top = new Node<string>(word);
        } else {
            tree->insert(new Node<string>(word));
        }

        if (!list->first) {
            list->first = new ListNode<string>(word);
        } else {
            list->insert(new ListNode<string>(word));
        }
    }
    fin.close();

    const string toSearch = "Tennessee";

    int startTime = clock();
    Node<string> * searchNode = tree->search(toSearch);
    int stopTime = clock();
    int searchTreeTime = stopTime - startTime;

    if (searchNode) {
        cout << searchNode->name << endl;
        if (searchNode->left) {
            cout << "Left kid name: ";
            cout << searchNode->left->name << endl;
        } else {
            cout << "There is not left kid" << endl;
        }

        if (searchNode->right) {
            cout << "Right kid name: ";
            cout << searchNode->right->name << endl;
        } else {
            cout << "There is not right kid" << endl;
        }
    } else {
        cout << "Sorry, string \"" << toSearch << "\" not founded" << endl;
    }
    cout << "Tree search: " << searchTreeTime << endl;


    cout << "-----------------" << endl;

    startTime = clock();
    ListNode<string> * searchListNode = list->search(toSearch);
    stopTime = clock();

    int listSearchTime = stopTime - startTime;

    if (searchListNode) {
        cout << searchListNode->name << endl;
        if (searchListNode->next) {
            cout << "Next item name: ";
            cout << searchListNode->next->name << endl;
        } else {
            cout << "There is not next item";
        }
    } else {
        cout << "Sorry, string \"" << toSearch << "\" not founded" << endl;
    }
    cout << "List search: " << listSearchTime << endl;

    cout << "-----------------" << endl;
    cout << "Straight run: ";
    tree->straightRun(tree->top);
    cout << "\n" << "Back run: ";
    tree->backRun(tree->top);
    return 0;
}