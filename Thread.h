#ifndef _THREAD_H_
#define _THREAD_H_

#include <pthread.h>
#include <boost/function.hpp>

class Thread {
public:
  typedef boost::function<void ()> Task;
  explicit Thread(const Task& func); // 单参数阻止隐式的构造，只能显示构造
  ~Thread();

  void start();
  void join();

private:
  pthread_t tid;
  static void* ThreadRoutine(void* arg);
  void run();
  Task func;
};

#endif // _THREAD_H_
