#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <cmath>
#include <cstdlib>

using namespace std;

class SpecialNumber {
	
	long double num;
	
  public:
	SpecialNumber (long double _num) {
		num = _num;
	}
  
  void setNum(long double _num) {
    num = _num;
  }

  /*
    ascii to long double
  */
  long double atold(const char* s);
  /* 
    a number is happy if the sume of the digits equal 1 recursively 
  */
	bool is_happy();
  bool is_prime();
  bool is_fibonacci();
};


long double SpecialNumber::atold(const char* s) {
  if(s==NULL) return -1;
  int len = strlen(s);
  long double ret = 0;
  for(int i=0;i<len;i++) {
    char digit_char = s[i];
    int digit = digit_char - 48;
    ret = (ret*10) + digit;
  }
  return ret;
}

bool is_happy_helper(set<long double> &num_set, long double n) {

	long double sum = 0, divisor = 10;
	while(n!=0) {
    sum+= (int)(fmod(n, divisor));
    n =  (n / divisor);
  }
	if (sum == 1)
		return true;

	pair<std::set<long double>::iterator,bool> ret;

	ret = num_set.insert(sum);
	if(ret.second == false) { //n exists in set and therefore a loop
		return false;
	}
	return is_happy_helper(num_set, sum);
}


bool SpecialNumber::is_happy() {
	set<long double> num_set;
	return (is_happy_helper(num_set, num));
}


/* 
  program to check functionality of SpecialNumber class
*/
int main (int argc, char** argv) {

  SpecialNumber n(0);

  for(int i=2;i<=argc;i++) {
    long double num = n.atold(argv[i-1]);
	  n.setNum(num);
	  cout << n.atold(argv[i-1])<< (n.is_happy()?" is a happy number\n":" is not a happy number\n");
  }
	return 0;
}

