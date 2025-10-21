#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
  uint64_t time;
  Wire* wire;
  char state;
};

typedef struct EventLess {

  bool operator()(const Event* a, const Event* b) const {
    return a->time < b->time;
    // returns true if a has a larger time than b, smaller times on top (min-heap)
  }

  //write the operator() required to make this a functor that compares Events by time
} EventLess;
	
#endif
