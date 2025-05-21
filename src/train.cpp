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
  if (!first) {
    return 0;
  }
  countOp = 0;
  int length = 1;
  Car* Current = first;
  while (true) {
    Current = Current->next;
    countOp++;
    if (Current == first) {
      break;
    }
    length++;
  }
  return length;
}
void Train::getOpCount() {
  return countOp;
}
