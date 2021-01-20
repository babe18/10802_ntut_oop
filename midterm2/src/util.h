#ifndef UTIL_H
#define UTIL_H

#include <vector>

template <class RandomAccessIterator, class Condition>
std::vector<Binary*> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond){
    std::vector<Binary*> bin;
    for (RandomAccessIterator i = begin; i < end; i++)
	    if (cond(*i))
		    bin.push_back(*i);
    return bin;
}

template <class T>
std::vector<T> convertAll(std::vector<Binary*> const & bins){
  std::vector<Binary*> find = findAll(bins.begin(), bins.end(), [](Binary *b){return T::canConvert(*b);});

  std::vector<T> result;
  for(Binary *b : find){
    result.push_back(T(*b));
  }
  return result;
}

#endif
