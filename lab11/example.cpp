#include <iostream>
#include <map>
 
using namespace std;

 
int main(void) {

  // hash and hash iterator
  std::map<std::pair<int, int>, int> h;
  std::map<std::pair<int, int>, int>::iterator it;

  // insert (10, 10)
  std::pair<int,int> pt1 = std::make_pair(10, 10);
  std::pair<std::pair<int,int>, int> new_e = std::make_pair(pt1, 10 + 10);
  h.insert(new_e);

  it = h.find(std::make_pair<int, int>(10, 10));	
  if (it != h.end())
    std::cout << "(10, 10) exists and its coordinate sum is " << it->second << endl;
  else
    std::cout << "(10, 10) doesn't exist)"<<endl;

  it = h.find(std::make_pair<int, int>(10, 11);	
  if (it != h.end())
    std::cout << "(10, 11) exists and its coordinate sum is " << it->second << endl;
  else
    std::cout << "(10, 11) doesn't exist)"<<endl;

  return 0;

}
