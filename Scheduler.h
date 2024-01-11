#ifndef Scheduler_h
#define Scheduler_h

#ifndef SCHEDULER_MAX_TASKS
  // You can define this macro yourself before importing Scheduler to change how many tasks can be active at one time.
  #define SCHEDULER_MAX_TASKS 5
#endif

class Task {
  public:
    Task(); // This generates a Task where Callback is null. It's here so that an array can be initialized with empty tasks.
    Task(int timeLeft, void (*callback)());
    int TimeLeft;
    void (*Callback)(); // A task where Callback is null is considered inactive and will not be ticked.
};

class Scheduler {
  public:
    Scheduler();
    void Tick();
    bool Add(Task task);
  private:
    Task _Tasks[SCHEDULER_MAX_TASKS];
};

#endif