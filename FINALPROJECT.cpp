#include <iostream>
#include <vector>
using namespace std;

// store adjacency list
struct Node {
    int val, cost;
    Node* next;
};
// Data structure to store graph edges
struct Edge {
    int src, dest, weight;
};
class Graph {
private:
    int N;  // nodes
    Node* getAdjListNode(int value, int weight, Node* head) {
        Node* newNode = new Node;
        newNode->val = value;
        newNode->cost = weight;
        newNode->next = head;
        return newNode;
    }

public:
    Node** head;
    Graph(Edge edges[], int n, int N) {
        head = new Node*[N](); 
        this->N = N;
        for (int i = 0; i < N; ++i)
            head[i] = nullptr;

        // add edges
        for (unsigned i = 0; i < n; i++) {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;

            head[src] = getAdjListNode(dest, weight, head[src]);

            head[dest] = getAdjListNode(src, weight, head[dest]);
        }
    }

    ~Graph() {
        for (int i = 0; i < N; i++)
            delete[] head[i];
        delete[] head;
    }

    void printList(Node* ptr, int i) {
        while (ptr != nullptr) {
            cout << "(" << i << ", " << ptr->val << ", " << ptr->cost << ") ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int V) {
    for (int v = 1; v < V; ++v) {
        cout << "The roads connected to " << v << " are: ";
        for (auto x : adj[v]) {
            cout << "-> " << x;
        }
        cout << endl;
    }
}
// Main function
int main() {
    int choice = 0;
    cout << "Welcome! and this is Inland Empire Solar Sales Travel. Choose an option (1-4) to view what you are looking for!:\n";
    cout << "1. Trips\n";
    cout << "2. Short route\n";
    cout << "3. Adjacencies\n";
    cout << "4. Matrix\n";
    cin >> choice;

    while (choice < 1 || choice > 4) {
        cout << "Not a correct option please select(1-4):\n";
        cin >> choice;
    }

    switch (choice) {
    case 1: {
        cout << "Routes From Cities:\n1. Riverside 2. Hemet 3. Moreno Valley 4. Perris\n";

        Edge edges[] = {
            {1, 2, 33}, {1, 3, 16}, {1, 4, 24}, {2, 3, 26},
            {3, 4, 18}, {4, 2, 30}
        };
        int N = 5;
        int n = sizeof(edges) / sizeof(edges[0]);
        Graph graph(edges, n, N);

        for (int i = 1; i < N; i++) {
            cout << i;
            graph.printList(graph.head[i], i);
        }
        break;
    }

    case 2: {
        cout << "Locations:\n1. Riverside 2. Helmet 3. Moreno Valley 4. Perris\n";
        cout << "Based on graphs \n";

        Edge edges[] = {
            {1, 2, 33}, {1, 3, 16}, {1, 4, 24}, {2, 3, 26},
            {3, 4, 18}, {4, 2, 30}
        };
        int numOfVertices = 5;
        int n = sizeof(edges) / sizeof(edges[0]);
        Graph graph(edges, n, numOfVertices);

        for (int i = 1; i < numOfVertices; i++) {
            graph.printList(graph.head[i], i);
        }

        cout << "\n The matrix displays there are a potential of\n"
             << "6 routes that can be used for the trip.\n"
             << "(1,2,3,4) = 77\n(1,2,4,3) = 81\n(1,4,2,3) = 80\n(1,4,3,2) = 68\n"
             << "(1,3,2,4) = 72\nWith the lowest cost path being (1,3,4,2) = 64 miles\n";
        break;
    }

    case 3: {
        int v = 5;
        vector<int> arr[v];
        addEdge(arr, 1, 2);
        addEdge(arr, 1, 3);
        addEdge(arr, 1, 4);
        addEdge(arr, 3, 4);
        addEdge(arr, 3, 2);
        addEdge(arr, 4, 2);

        printGraph(arr, v);
        break;
    }
    case 4: {
        cout << "Cities: 1. Riverside 2. Helmet 3. Moreno Valley 4. Perris\n";
        cout << "Here is Matrixw with included weights.\n";
        Edge edges[] = {
            {1, 2, 33}, {1, 3, 16}, {1, 4, 24}, {2, 3, 26},
            {3, 4, 18}, {4, 2, 30}
        };
        int numOfVertices = 5;
        int n = sizeof(edges) / sizeof(edges[0]);
        Graph graph(edges, n, numOfVertices);

        for (int i = 1; i < numOfVertices; i++) {
            graph.printList(graph.head[i], i);
        }
        break;
    }
    default:
        cout << "Choice is not valid";
    }
    return 0;
}
