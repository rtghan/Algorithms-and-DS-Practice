#include <iostream>
#include <stdio.h>
using namespace std;

int findGCF(int a, int b){ //Stein GCF
  if(a == b) return a;
  if(a == 0) return b;
  if(b == 0) return a;
  
  //use >> 1 as /2
  // << 1 as * 2

  //even
  if(!(a&1)){
    if(b&1) return findGCF(a >> 1, b); //b odd
    else return findGCF(a >> 1, b >> 1) << 1; //b even
  }
  if(!(b&1)) return findGCF(a, b >> 1);
  if(a > b) return findGCF((a - b) >> 1, b);
  return findGCF((b - a) >> 1, a);
} 

void buildTree(int arr[], int segTree[], int elems, int index, bool GCF){
  //in a segment tree, the original arrays elements will start off at index # elements - 1 in the segTree array (unless 1 indexed) because there will be a total of elements - 1 parents, and we need space to store those parents
  for(int i = elems; i < elems << 1; i++) segTree[i] = arr[index+(i-elems)];

  //start calculating the parents, starting from the parent located at index # elements - 2 (unless 1 indexed)
  for(int i = elems - 1; i > 0; i--){
    //the minimum of the children of the parent node (using +0 and + 1 because this segTree will be 1-indexed, would use +1 and +2 if it was 0-indexed)
    if(GCF) segTree[i] = findGCF(segTree[i << 1], segTree[(i << 1)+1]);
    else segTree[i] = min(segTree[i << 1], segTree[(i << 1)+1]);
  }
}

void updateTree(int index, int value, int elems, int segTree[]){
  //update val
  segTree[index] = value;

  //update parents
  for(index; index > 1; index /= 2){
    //bitwise AND operator; odd numbers will end in a 1 bit, meaning odd numbers will evaluate num&1 to be true
    if(index&1) segTree[index >> 1] = min(segTree[index], segTree[index - 1]);
    else segTree[index >> 1] = min(segTree[index], segTree[index + 1]);
  }
}

void updateTreeGCF(int index, int value, int elems, int segTree[]){ //version for GCF updates
  segTree[index] = value;
  for(index; index > 1; index /= 2){
    if(index&1) segTree[index >> 1] = findGCF(segTree[index], segTree[index - 1]);
    else segTree[index >> 1] = findGCF(segTree[index], segTree[index + 1]);
  }
}

int queryTree(int tree[], int lb, int rb, int val, int elems){ //lb -> left bound, rb -> right bound, this functions queries in the range[lb, rb] (including lb, excluding rb)
  
  val = tree[lb + elems - 1]; //set a value that will be part of the search as the default

  for(lb += elems - 1, rb += elems - 1; lb < rb; lb = (lb+1) >> 1, rb = (rb+1) >> 1){
    //keep going until bounds update
    //each increment moves bound(working idx) to its parent (if bound was even) or the node right of its parent
    if(lb&1) val = min(val, tree[lb++]);

    if(rb&1){
      //-- in front means the value used is val - 1, whereas -- after the variable means the value used is the value without modification
      val = min(val, tree[--rb]);
    }
  }
  return val;
}

//for GCF version
int queryTreeGCF(int tree[], int lb, int rb, int val, int elems){
  val = tree[lb + elems - 1]; //set a value that will be part of the search as the default
  for(lb += elems - 1, rb += elems - 1; lb < rb; lb = (lb+1) >> 1, rb = (rb+1) >> 1){
    if(lb&1) val = findGCF(val, tree[lb++]);
    if(rb&1) val = findGCF(val, tree[--rb]);
  }
  return val;
}

int main() {
  int arr[100005], N, operations, inp, a, b, segTree[300000], gcfTree[300000]; //N: elements, M: num operations
  char oparr[100];
  string op;

  //scanf("%d", &N);
  //scanf("%d", &operations);
  scanf("%d %d", &N, &operations);

  //get the values for the array
  for(int i = 1; i <= N; i++){
    //scanf("%d", &inp);
    scanf("%d", &inp);
    arr[i] = inp;
  }

  buildTree(arr, segTree, N, 1, false);
  buildTree(arr, gcfTree, N, 1, true);
  //for(int q: segTree) cout << q << " ";

 
  for(int operation = 0; operation < operations; operation++){
    //take input
    scanf("%s", oparr);
    scanf("%d", &a);
    scanf("%d", &b);
    op = oparr;
    //cin >> op >> a >> b;

    //change value operation
    if(op == "C"){
      arr[a] = b;
      updateTree(a + N - 1, b, N, segTree);
      updateTreeGCF(a + N - 1, b, N, gcfTree);
    }

    //find minimum
    else if(op == "M"){
      //take in the bounds of the search
      //a is low, b is high

      //+1 for right bound (b) beacuse problem asks for query in range [a, b], but code does [a, b), can use 0 as initial value for "val" because it changes it to a preset default in the func
      printf("%d\n", queryTree(segTree, a, b + 1, 0, N));
    }

    //operations related to greatest common factor
    else if(op == "G" || op == "Q"){

      //see line 109
      int gFactor = queryTreeGCF(gcfTree, a, b + 1, 0, N); //hold the factor in a variable

      //in the case of having to check occurences of the GCF in the bounds
      if(op == "Q"){
        int occurences = 0;
        //iterate through the range
        for(int j = a; j <= b; j++){
          //check if they equal
          if(gFactor == segTree[j+N-1]) occurences++;
        }
        printf("%d\n", occurences);
        //cout << occurences << "\n";
      }
      //in the case of not being a Q operation
      else printf("%d\n", gFactor);//cout << gFactor << "\n";
    }
    
  }
}