#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int djSet[10000001], cnt = 0; //disjointed set, holds the parent of each node. array index corresponds to node
queue <int> edgeUsed; //queue to hold all the edges part of the tree

int find(int n){//function to find the source parent of node n
  if(djSet[n] != -1){//when node is not its own parent
    return djSet[n] = find(djSet[n]); //recurse until u find a node with its own parent, set the node n parent to that source parent node
  }
  else{
    return n; //returns this when a node is its own source parent node
    //when the recursion goes all the way back it comes to this at the source node
  } 
}
void connect(int n1, int n2, int edge){ //creates an edge between two nodes only if the edge wouldn't create a loop
  int n1p = find(n1), n2p = find(n2);//using find function, finds the parent of each node
  if(n1p != n2p){//if they have different parents, you can think of it like the nodes are in 2 different "realms", like they are in 2 separate trees. if this is the case, we need to connect them since we are trying to make 1 tree 

    djSet[n1p] = n2; //by setting the parent of one node to the other node, we are basically connecting them
    cnt++; //counter used to count the amount of edges that make up the tree we make
    edgeUsed.push(edge+1); //pushes any edges in the tree into the queue later used for output
  }
  return; //ryan devine says he likes do do this
}
pair<int, pair<int, int> > E[1000001]; //edge array, first int corresponds to weight (even tho in this case it doesnt matter) the next pair corresponds to n1 n2

int main() {
  int N, M, n1, n2; //# nodes, # edges, node 1, node 2
  cin >> N >> M;

  //set all nodes their own parent (-1 represents their own parent)
  for(int i = 0; i < M; i++){
    djSet[i] = -1;
  }

  for(int i = 0; i < M; i++){ //take input, make edge array
    cin >> n1 >> n2;
    E[i] = {i,{n1,n2}};  //im just using i as weight since in this case the edges/nodes are input in order of weight
  }
  for(int i = 0; i < M; i++){//u start off with only the nodes, and no edges. this for loop runs # of edge times, and tries to input edges to form a tree. the connect function makes it so that all the edges that are input will form a tree
    connect(E[i].second.first, E[i].second.second, i);//attempts to connect n1 and n2 of edges with least weight first  
  }
  if(cnt == N-1){ //since only a tree if edges = number of nodes -1 (think a 3 node tree only has 2 edges, a 4 node tree only has 3, etc.)
    while(!edgeUsed.empty()){
      cout << edgeUsed.front() << "\n";
      edgeUsed.pop();
    }
  }
  else{
    cout << "Disconnected Graph";
  }
}