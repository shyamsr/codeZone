#include <iostream>
#include <string>
#include <map>
/*
Remove duplicates in a string 

@author

Shyam

*/
using namespace std;

void remove_duplicates(string& str_dup) {

	map<char, int> str;
	
	string::iterator i;

	pair<map<char,int>::iterator,bool> ret;
	for(i=str_dup.begin(); i!=str_dup.end(); ++i) {
		ret = str.insert(pair<char,int> (*i, 0));
		str[*i] ++;
		if(ret.second == false) {
			str_dup.erase(i);
			i--;
		}
	}

/*
 	for(i=str_dup.begin(); i!=str_dup.end(); ++i) {
		cout<<*i<<" "<<str[*i]<<endl;
	}
*/

	return;
}

int main() {

	string str("This is a sample string");
	cout<<str<<endl;
  remove_duplicates(str);
	cout<<str<<endl;

  return 0;
}
