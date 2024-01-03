#ifndef _COROUTINE_H_
#define _COROUTINE_H_

#include <atomic>
#include <cassert>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <ucontext.h>
#include <unistd.h>

namespace corc {

class Fiber : public std::enable_shared_from_this<Fiber> {
public:
  enum State { READY, RUNNING, TERM };

private:
  Fiber();

public:
  Fiber(std::function<void()> cb, size_t stacksize = 0,
        bool run_in_scheduler = true);
  ~Fiber();

  void reset(std::function<void()> cb);

  void resume();

  void yield();

  uint64_t getId() const { return m_id; }
  State getState() const { return m_state; }

public:
  static void SetThis(Fiber *f);

  static std::shared_ptr<Fiber> GetThis();

  static void SetSchedulerFiber(Fiber *f);

  static uint64_t GetFiberId();

  static void MainFunc();

private:
  uint64_t m_id = 0;

  uint32_t m_stacksize = 0;

  State m_state = READY;

  ucontext_t m_ctx;

  void *m_stack = nullptr;

  std::function<void()> m_cb;

  bool m_runInScheduler;

public:
  std::mutex m_mutex;
};

} // namespace corc

#endif
