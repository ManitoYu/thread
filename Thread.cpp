#include "Thread.h"
#include <iostream>

using namespace std;

Thread::Thread(const Task& func): func(func) {
  cout << "Thread" << endl;
}

Thread::~Thread() {
  cout << "~Thread" << endl;
}

void Thread::start() {
  pthread_create(&tid, NULL, ThreadRoutine, this);
}

void Thread::join() {
  pthread_join(tid, NULL);
}

void* Thread::ThreadRoutine(void* arg) {
  Thread *thread = static_cast<Thread*>(arg);
  thread->run();
  delete thread;
  thread = NULL;
}

void Thread::run() {
  func();
}
