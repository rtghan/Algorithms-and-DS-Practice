#include <iostream>
#include<stdio.h>
#include <math.h>
using namespace std;

bool isP[1000000];
bool checkPrime(int n){
  if(isP[n]) return true;
  else if (n == 2 || n == 3 || n == 5 || n == 7) return isP[n] = true;
  else if (n == 1 || n == 4 || n == 6) return isP[n] = false;
  else if (n % 2 == 0 || n % 3 == 0) return isP[n] = false;
  else {
    for(int i = 2; i < sqrt(n)+1; i++){
      if(n % i == 0){
        return isP[n] = false;
      }
    }
    return isP[n] = true;
  } 
}

int main() {
  int tCases, n, a, b, c;
  scanf("%d",&tCases);
  for(int i = 0; i < tCases; i++){
    bool twoPrime = true;
    
    scanf("%d",&n);

    

    if(n % 2 == 0){
      c = 1;
      while(twoPrime){
        if(checkPrime(n-c) && checkPrime(n+c)){

          a = n + c;
          b = n - c;
          if((a+b)/2 == n){

            twoPrime = false;
          }
          
        }
        c += 2;
      }
    }
    else{
      c = 2;
      while(twoPrime){
        if(checkPrime(n-c) && checkPrime(n+c)){
          a = n + c;
          b = n - c;
          if((a+b)/2 == n)twoPrime = false;
        }
        c += 2;
      }
    }
    // cout << "\n";
    cout << a << " " << b << "\n";
  }
}