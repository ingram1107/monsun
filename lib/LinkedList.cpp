// LinkedList.cpp
#include "LinkedList.hpp"
#include <iostream>

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
  : size{rhs.size}
{
  if (rhs.isEmpty()) {
    head = nullptr;
  } else {  // TODO: put exception? (failed memory allocation)
    head = std::make_shared<Node<T>>();   // allocate memory
    head->element = rhs.head->element;

    auto newptr = head;
    for (auto orig = rhs.head->next;
         orig != nullptr;
         orig = orig->next) {  // copy the whole link list structure
      newptr->next = std::make_shared<Node<T>>();
      newptr = newptr->next;
      newptr->element = orig->element;
    }
  }
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
  LinkedList<T> copy = rhs;
  copy.swap(*this);
  return *this;
}

template <class T>
void swap(LinkedList<T>& a, LinkedList<T>& b) noexcept
{
  a.swap(b);
}

template <class T>
void LinkedList<T>::swap(LinkedList<T>& b) noexcept
{
  using std::swap;
  swap(head, b.head);
  swap(size, b.size);
}

template <class T>
bool LinkedList<T>::isEmpty() const noexcept
{
  if (!head) { // head == nullptr
    return true;
  }
  return false;
}

template <class T>
bool LinkedList<T>::makeEmpty()
{
  if (isEmpty()) {
    return false;
  }

  while(!isEmpty()) {
    remove((size_t) 1);
  }
  return true;
}

template <class T>
bool LinkedList<T>::insert(T element, size_t index)
{
  size++;
  if (index < 1 || index > size) {
    size--;
    return false;
  }

  // TODO: put exception? (failed memory allocation)
  auto newptr = std::make_shared<Node<T>>(element);

  if (index == 1) {
    newptr->next = head;
    head = newptr;
  } else {
    auto prev = find(index-1);
    newptr->next = prev->next;
    prev->next = newptr;
  }

  return true;
}

template <class T>
std::shared_ptr<Node<T>> LinkedList<T>::find(size_t index) const
{
  if (index < 1 || index > size) {
    return nullptr;
  }

  auto cur = head;
  for (size_t i = 1; i < index; i++) {
    cur = cur->next;
  }

  return cur;
}

template <class T>
const T LinkedList<T>::retrieve(size_t index) const
{
  auto foundptr = find(index);
  if (!foundptr) {  // foundptr == nullptr
    return {};
  } else {
    return foundptr->element;
  }
}

template <class T>
size_t LinkedList<T>::search(T element) const noexcept
{
  auto cur = head;
  for (size_t i = 1; i <= size; i++, cur = cur->next) {
    if (element == cur->element) {
      return i;
    }
  }

  return 0;
}

template <class T>
bool LinkedList<T>::remove(T element)
{
  auto index = search(element);
  if (index) {
    remove(index);
    return true;
  }

  return false;
}

template <class T>
bool LinkedList<T>::remove(size_t index)
{
  if (index < 1 || index > size) {
    return false;
  }

  size--;
  std::shared_ptr<Node<T>> cur;

  if (index == 1) {
    cur = head;
    head = cur->next;
  } else {
    auto prev = find(index-1);
    cur = prev->next;
    prev->next = cur->next;
  }

  return true;
}

template <class T>
void LinkedList<T>::sort(bool isAscending)
{
  if (isAscending)
    ascendingOrderSort();
  else
   descendingOrderSort();
}

template <class T>
void LinkedList<T>::ascendingOrderSort()
{
  for (auto i = 0; i <= size; i++)
    for (auto j = head; j->next != nullptr; j = j->next)
      if (j->element > j->next->element)
        std::swap(j->element, j->next->element);
}

template <class T>
void LinkedList<T>::descendingOrderSort()
{
  for (auto i = 0; i <= size; i++)
    for (auto j = head; j->next != nullptr; j = j->next)
      if (j->element < j->next->element)
        std::swap(j->element, j->next->element);
}
