#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

template<typename Iter>
void bubble_sort(Iter itb, Iter ite) {
  Iter it1 = itb;
  Iter it2 = itb;
  ++it2;
  for( ; it2 != ite; ) {
    for( ; it2 != ite; ) {  
      if(*it1 > *it2) {
	swap(*it1, *it2);
      }  
      ++it1;
      ++it2;
    }
    it1 = itb;
    it2 = itb;
    ++it2;
    --ite;
  }
}


template<typename Iter>
void print(Iter it1, Iter it2) {
  Iter it = it1;
  int ind = 0;
  for(; it != it2; ++it) { 
    std::cout << ind << "   " << *it << std::endl; 
    ind++;
  }
}
