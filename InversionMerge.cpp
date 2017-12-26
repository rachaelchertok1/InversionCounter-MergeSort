//Rachael Chertok
//Analysis of Algorithms-HW 1, Question 4b

#include <iostream>
using namespace std;

int inversions=0;

int InversionMerge(int *A, int p, int q, int r){
  int i=p, j=q+1;
  if(i<=q && j <=r){
    while(i<=q && j <=r){
      if (A[i]<A[j]){
        i++;
      }
      else{
        inversions++;
        j++;
      }
    }
  }

  else if(i<=q){
    while(i<=q){
      if(A[i+1]< A[i]){
        inversions++;
      }
      i++;
    }
  }

  else if(j<=r){
    while(j<=r){
      if(A[j+1]< A[j]){
        inversions;
      }
      j++;
    }
  }

  return inversions;
}

int countInversions(int *A, int p, int r){
  if(p<r){
    int q=(p+r)/2;
    countInversions(A, p, q);
    countInversions(A, q+1, r);
    inversions=InversionMerge(A, p, q, r);
  }
  return inversions;
}

int main(){
  int A[]={3, 2, 1, 4, 1};
  int p=0, r=4;
  cout << "The number of inversions is " << countInversions(A, p, r) << endl;
  system("pause");
  return 0;
}
