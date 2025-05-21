// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
  if (!first) {
    return;
  }
  Car* current = first;
  Car* nextCar;
  do {
    nextCar = current->next;
    delete current;
    current = nextCar;
  } while (current != first);
  first = nullptr;
}

void Train::addCar(bool light) {
  Car* newCar = new Car;
  newCar->light = light;
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
  if (first == nullptr) {
    countOp = 0;
    return 0;
  }
  int length = 1;
  const Car* current = first -> next;
  bool disabledLight = !first->light;
  while (current != first) {
    if (!current->light) {
      disabledLight = true;
    }
    length +=1;
    current = current->next;
  }
  if (disabledLight) {
    countOp = length * 2;
  } else {
    countOp = length * (length + 1);
  }
  return length;
}
int Train::getOpCount() {
  return countOp;
}
