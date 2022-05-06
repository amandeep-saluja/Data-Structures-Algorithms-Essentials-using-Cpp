
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T d)
    {
        data = d;
        next = NULL;
    }
};

template <typename T>
class Stack
{
public:
    Node<T> *head;
    Stack() {
        head = NULL;
    }

    void push(T data) {
        Node<T> *n = new Node<T>(data);
        n->next = head;
        head = n;
    }

    bool isEmpty() {
        return head == NULL;
    }

    T top() {
        return head->data;
    }

    void pop() {
        if(head!=NULL) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};