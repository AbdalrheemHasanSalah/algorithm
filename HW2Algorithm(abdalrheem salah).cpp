#include <iostream>
#include <queue>

#include<fstream>


//the sourse file should have outher text file to input matrix 

# define SIZE 100
void enqueue(int insert_item2);
void dequeue();
void show();
int front();
int inp_arr[SIZE];
int Rear = -1;
int Front = -1;

class matrix {
    int n;
    int** p;

public:
    // Constructor
    matrix(int a) {
        n = a; 
        p = new int* [n];
        for (int i = 0; i < n; i++) {
            p[i] = new int[n](); 
        }
    }

    // Destructor
    ~matrix() {
        int i = 0;
        while(i<n) {
            delete[] p[i];
            i++;
        }
        delete[] p;
    }

    // Initialize the test graph matrix
    void initialize() {
     
        std::fstream f;
        f.open("matrix.txt");
        int node = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                while (!(f >> p[i][j])) {
                    
                            
                            }
                    }
                }

       
    }

    // Print the graph matrix
    void print() {
     
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << p[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Count the number of edges in the graph
    int count_edges() {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i][j] == 1)
                    count++;
            }
        }
        return count;
    }

    // Return the outdegree of node r
    int outdegree(int r) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (p[r][j] == 1)
                count++;
        }
        return count;
    }

    // Return the indegree of node c
    int indegree(int c) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (p[i][c] == 1)
                count++;
        }
        return count;
    }

    // Return 1 if edge (r,c) is found
    int find_edge(int r, int c) {
        return p[r][c];
    }


    void topological_sort() {

       
         int* indeg = new int[n];


         for (int i = 0; i <n ; i++) {
             indeg[i] = indegree(i);
             if (indeg[i] == 0) {
                 enqueue(i);

             }
         }

         std::cout << "Topological Sort: ";
         while (Front!=n) {
             int node = front();
              dequeue();

             std:: cout << node << " ";

             for (int j = 0; j < n; j++) {
                 if (p[node][j] == 1) {
                     indeg[j]--;
                     if (indeg[j] == 0) {
                         enqueue(j);

                     }
                 }
             }
         }
        
    }
};

int main() {

    matrix graph(5);

    graph.initialize();
    int row;
    int column;
    std::cout << "row is(findcount outdegree) : ";
    std::cin >> row;
    std::cout << "outdegree count "; 
    std::cout<< graph.outdegree(row);


    std::cout << std::endl;
    std::cout << "row is : ";

    std::cin >> row;
    std::cout << "column is : ";

    std::cin >> column;
    std::cout << "find_edge ";
    std::cout<<  graph.find_edge(row,column);

    std::cout << std::endl;
    std::cout << "count_edges ";

   std::cout<<graph.count_edges();

   std::cout << std::endl;

    std::cout << "Graph Matrix:" << std::endl;
    graph.print();

   
    graph.topological_sort();

  std:: cout << std::endl;
   

    return 0;
}
void enqueue(int insert_item2)
{
    int insert_item= insert_item2;
    if (Rear == SIZE - 1)
        printf("Overflow \n");
    else
    {
        if (Front == -1)

            Front = 0;
       // printf("Element to be inserted in the Queue\n : ");
       // scanf("%d", &insert_item);
        Rear = Rear + 1;
       inp_arr[Rear] = insert_item;
    }
}

void dequeue()
{
    if (Front == -1 || Front > Rear)
    {
       // printf("Underflow \n");
        return;
    }
    else
    {
        //printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
        Front = Front + 1;
    }
}

int front() {
    if (Front == -1) {
        std::cerr << "Queue is empty!" << std::endl;
        return -1; // Error value
    }
    return inp_arr[Front];
}

void show()
{

    if (Front == -1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}