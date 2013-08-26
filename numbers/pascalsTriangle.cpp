#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

/*
@author Shyam

PascalsTriangle class provides methods for 
 calculating numbers in a Pascals Triangle 
 calculating Fibonacci series
 calculating Factorial

*/

typedef std::vector<long double>  triangle_row;
typedef std::vector<triangle_row> triangle_data_structure;
typedef unsigned int level_type;
typedef long max_size;

class pascalsTriangle {
  triangle_data_structure triangle;
  
  protected:
    map<level_type, max_size> fact_map;

    max_size calcFact(max_size n);

  public:
    max_size getValue(level_type m, level_type n);
    void getPascalsTriangle(triangle_data_structure& t, level_type level);
    void getPascalsTriangleRow(triangle_row& r, level_type level); 

};

max_size pascalsTriangle::calcFact(max_size n) {
  map<level_type, max_size>::iterator iter;
  max_size ret=1, i;
  if (n==1 || n==0) {
    return 1;
  }
  if( (iter = fact_map.find(n)) != fact_map.end()) {
    return iter->second;
  }
  ret = n * this->calcFact(n-1);
  fact_map.insert(pair<level_type, max_size>(n, ret));
  return ret;
}
/*
use m! /(n! * (m-n)!)
Factorial calculation simplify using DP
*/
max_size pascalsTriangle::getValue(level_type m, level_type n) {
  return this->calcFact(m) / (this->calcFact(n) * this->calcFact(m-n));
}


void pascalsTriangle::getPascalsTriangleRow(triangle_row& r, level_type level) {
  int num_elements = level+1, i;

  for(i=0;i<num_elements;i++) {
    r.push_back(this->getValue(level, i));
  }
}
/* program to test PascalsTriangle class */
int main (int argc, char** argv) {
  pascalsTriangle t;
  cout<<t.getValue(4,2)<<endl;

  triangle_row temp;
  t.getPascalsTriangleRow(temp, 10);
  for(triangle_row::iterator it = temp.begin(); it != temp.end(); it++) {
    cout<<" "<<*it<<" ";
  }
  cout<<endl;
  return 0;
}
