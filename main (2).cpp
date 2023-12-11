#include <iostream>
#include <vector>
using namespace std; 
  
  struct Node 
  {
  int val, weight;
  Node *next;
  };
 
  struct Edge
  {
  int src, dest, weight; 
  };

  class Graph 
  {
  Node *getAdjListNode(int value, int weight, Node *head)
  {
    Node *newNode = new Node;
    newNode -> val = value;
    newNode -> next = head;
    newNode -> weight = weight; 
   return newNode;
    }
  int N; 
  
public:
  Node **head;
  // The constructor
  Graph(Edge edges[], int n, int N)
  {
    head = new Node*[N]();
    this -> N = N;
    // To initialize the head pointed for all vertices 
    for (int i = 0; i < N; i++)
      head [i] = nullptr;

    for (unsigned i = 0; i < n; i++) {
      int src = edges[i].src;
      int dest = edges[i].dest;
      int weight = edges[i].weight;
      Node* newNode = getAdjListNode(dest, weight, head[src]);
      head[src] = newNode;
      newNode = getAdjListNode(src, weight, head[dest]);
      head[dest] = newNode;
        }
  }
    //Destructor 
   ~ Graph()
     {
       for (int i = 0; i < N; i++)
         delete[] head[i];

         delete[] head;
     }

  void printList (Node *ptr, int i)
  {
    while (ptr != nullptr)
      {
        cout << "->" << ptr -> val;
        ptr = ptr->next;
      }
    cout << endl;
  }
};

void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int V)
{
  for (int v = 1; v < V; ++v)
    {
      cout << "Shortest round trip" << v << " : ";
      for (auto x : adj[v])
        cout << "-> " << x;
         cout << endl;
    }
}
  void printGraph1(vector<int> adj[], int V)
  {
    for (int v = 1; v < V; ++v)
      {
        cout << "Cheapest round trip" << v << " : ";
        for (auto x : adj[v])
          cout << "-> " << x;
           cout << endl;
      }
  }
    int main() {
      int choice = 0;
      while (choice != 5) {
        cout << "Welcome to the program, please select one of the following options:" << endl;
        cout << "1. Possible Routes: " << endl;
        cout << "2. Connections to Other Cities" << endl; 
        cout << "3. Shortest Round Trip" << endl;
        cout << "4. Map" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

         
      
        if (choice  < 1 || choice > 5 )
          cout << "Invalid choice, please try again" << endl;
        
        if (choice == 1) {
          cout << "Possible Routes: " << endl << "1.Riverside, 2.Moreno, 3.Hemet, 4.Perris" << endl;
        }

      if (choice == 2)
      {
        cout << "Locations: " << endl << "1.Riverside, 2.Moreno, 3.Hemet, 4.Perris" << endl;
        int V = 5;
        vector<int> adj[V];
        addEdge(adj, 1, 4);
        addEdge(adj, 1, 3);
        addEdge(adj, 1, 2);
        printGraph1(adj, V);

        cin >> choice;
      
      }

        if (choice == 3)
        {
          cout << "1. Riverside, 2. Moreno, 3. Hemet, 4. Perris" << endl;
          int V = 5;
          vector<int> adj[V];
          addEdge(adj, 1, 2);
          addEdge(adj, 1, 3);
          addEdge(adj, 1, 4);
          addEdge(adj, 3, 4);
          addEdge(adj, 3, 2);
          addEdge(adj, 4, 2);
          printGraph(adj, V);

          cin >> choice;
        }

        if (choice == 4) {
          cout << "Cities:" << endl << "1.Riverside, 2.Moreno, 3.Hemet, 4.Perris" << endl;
          Edge edges[] = {
          {1, 2, 16}, {1, 3, 33}, {1, 4, 24},
          {2, 3, 26}, {3, 4, 30}, {4, 2, 18}
         };
             int N = 5;
          int n = sizeof(edges) / sizeof(edges[0]);
          Graph graph(edges, n, N);
          for (int i = 1; i < N; i++) 
           
        cin >> choice;
        }

        if (choice == 5)
           cout << "Thank you for using the program" << endl;
        
        }
      
    
      return 0;
    }
