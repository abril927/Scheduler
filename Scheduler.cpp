#include "Arduino.h"
#include "Scheduler.h"

// Task constructors
Task::Task() {
  TimeLeft = 0;
  Callback = NULL;
}

Task::Task(int timeLeft, void (*callback)()) {
  TimeLeft = timeLeft;
  Callback = callback;
}

// Scheduler
Scheduler::Scheduler() {
  for (int i = 0; i < SCHEDULER_MAX_TASKS; i++) {
    _Tasks[i] = Task();
  }
}

void Scheduler::Tick() {
  int delta = 1; // TODO: Look into making delta dynamic, so that Scheduler is actually accurate to realtime.
  for (int i = 0; i < SCHEDULER_MAX_TASKS; i++) {
    if (_Tasks[i].Callback != NULL) {
      _Tasks[i].TimeLeft -= delta;
      if (_Tasks[i].TimeLeft <= 0) {
        _Tasks[i].Callback();
        _Tasks[i].Callback = NULL; // FIXME: The task is only marked as inactive *after* the callback is executed, meaning if you just have one task that repeats itself, you actually need 2 slots...?
      }
    }
  }
}

bool Scheduler::Add(Task task) {
  // Find an empty/inactive task we can replace
  int found = -1;
  for (int i = 0; i < SCHEDULER_MAX_TASKS; i++) {
    if (_Tasks[i].Callback == NULL) {
      found = i;
      break;
    }
  }
  // ...and replace it
  if (found != -1) {
    _Tasks[found] = task;
    return true;
  } else {
    return false;
  }
}