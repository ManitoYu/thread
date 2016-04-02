#include <iostream>
#include <unistd.h>
#include "Thread.h"
#include <boost/bind.hpp>

using namespace std;

void print(const char* str) {
  cout << "yucong" << endl;
}

int main() {
  Thread *t1 = new Thread(boost::bind(print, "yucong"));
  t1->start();
  Thread *t2 = new Thread(boost::bind(print, "yucong"));
  t2->start();

  Thread *t3 = new Thread(boost::bind(print, "yucong"));
  t3->start();

  t1->join();
  t2->join();
  t3->join();

  return 0;
}
