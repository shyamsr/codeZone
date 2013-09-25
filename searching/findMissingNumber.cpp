#include <iostream>

using namespace std;

/*******************************
* Input : An array of consecutive positive integers
* but with one number missing
* Output : The missing integer
*
*******************************/

int findMissingInt(int *in, int size) {
  int left = 0, right = size-1;
  int mid = 0, offset = in[0];
  while(left < right) {
    mid = (right + left) >> 1;
    if(right - left == 1) {
      if(in[right]-in[left]==1) 
        return in[right]+1;
      else
        return in[left]+1;
    } else if((in[mid]-in[left] != mid - left)) {
      right = mid;
    } else if ((in[right]-in[mid]  != right-mid)){
      left = mid;
    }
  } 
}

int main() {
  int a[] = {1,3,4,5,6,7,8,9,10};
  int b[] = {1,2,4};
  int c[] = {1,3};
  int d[] = {1,2,3,4,5,7,8,9,10};
  int e[] = {1,3,4};
  cout<<findMissingInt(a, 9)<<endl;
  cout<<findMissingInt(b, 3)<<endl;
  cout<<findMissingInt(c, 2)<<endl;
  cout<<findMissingInt(d, 9)<<endl;
  cout<<findMissingInt(e, 3)<<endl;
  return 0;
}

