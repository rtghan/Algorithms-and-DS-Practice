#include <iostream>
using namespace std;

int djSet[100001];

int find(int n){ //find and return root parent node of node n
  if(djSet[n] != n){ //if its not its own parent then find the parent of the parent node
    return djSet[n] = find(djSet[n]);
  }
  else{ //when a node is its own parent (also returns this as root node)
    return n;
  }
}

void connect(int a, int b){
  int ap = find(a), bp = find(b);
  if(ap != bp){
    djSet[bp] = ap; //connects node by setting ones parent to the other node
  }
  return;
}

int main() {
  int N, Q, n1, n2;
  char o;
  cin >> N >> Q;

  for(int i = 1; i <= N; i++){
    djSet[i] = i;
  }

  for(int i = 0; i < Q; i++){
    cin >> o >> n1 >> n2;
    if(o == 'A'){
      connect(n1,n2);
    }
    if(o == 'Q'){
      if(find(n1) == find(n2)){
        //cout << find(n1) << " " << find(n2);
        cout << "Y" << "\n";
      }
      else{
        //cout << find(n1) << " " << find(n2);
        cout << "N" << "\n";
      }
    }
  }
}
