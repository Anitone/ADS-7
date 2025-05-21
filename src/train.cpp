// Copyright 2021 NNTU-CS
#include "train.h"

void Train::addCar(bool light) {
  Car* newCar = new Car(light);
  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } 
  else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->next = last;
    newCar->prev = first;
    first->prev = newCar;
  }
}
int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  Car* Current = first;
  if (!Current->light) {
    Current->light = true;
  }
  int length = 0;
  bool found = false;
  while (!found) {
    while (true) {
      Current = Current->next;
      countOp++;
      length++;
      if (Current->light) {
        Current->light= false;
        break;
      }
    }
    int steps = 0;
    while (steps < length) {
      Current = Current->prev;
      countOp++;
      steps++;
    }
    if (!Current->light) {
      found = true;
    } else {
      length = 0;
    }
  }
  return length;
}
void Train::getOpCount() {
  return countOp;
}
