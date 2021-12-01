/**
 * @file LinkedList.hpp
 * @brief Linked List Interface
 *
 * @class Node lib/LinkedList.hpp "LinkedList.hpp"
 * @class LinkedList lib/LinkedList.hpp "LinkedList.hpp"
 */
#include <iostream>
#include <memory>

/**
 * TODO: move this to the private section of the LinkedList
 * Simple node for LinkedList
 *
 * Store element, whatever the type (primitive/class/struct) is, at this class,
 * which then point to another Node with the same type of the data. Initially,
 * the element could be any value depends on its constructor and the Node will
 * points to nothing but nullptr. This class could be instantiated as follows:
 *
 * @code{.cpp}
 * Node<int> w{};
 * @endcode
 *
 * Upon copy, it will copy the element of the right hand side of Node to itself
 * and then copy all the pointed Node in a traverse way. Copy could be done as
 * follows:
 *
 * @code{.cpp}
 * Node<int> w = v; // note: v is type of Node<int>
 * @endcode
 *
 * @tparam T Primitive type, class or struct
 * @note RAII-class, doesn't need to explicitly manage memory.
 */
template <class T>
struct Node {
  /// Stored data
  T element;
  /// Next Node
  std::shared_ptr<Node<T>> next = nullptr;

  Node() = default;
  Node(const T& element) : element{element} { }
  ~Node() = default;
};

/**
 * Linked List Implementation
 *
 * Dynamically store element, whatever the type is (primitive/class/struct)
 * inside a Node, and then the header pointer will adjusted to point to that
 * Node. Initially, LinkedList will have a size of zero and a header pointer
 * that points to nothing but nullptr. This class could be instantiated as
 * follows:
 *
 * @code{.cpp}
 * LinkedList<int> w{};
 * @endcode
 *
 * Upon copy, it will copy the element of the right hand side of LinkedList to
 * itself and then copy all the pointed Node in a traverse way. Copy could be
 * done as follows:
 *
 * @code{.cpp}
 * LinkedList<int> w = v; // note: v is type of LinkedList<int>
 * @endcode
 *
 * @tparam T Primitive type, class or struct
 * @note RAII-class, doesn't need to explicitly manage memory.
 */
template <class T>
class LinkedList {
  private:
    /// Header of the LinkedList
    std::shared_ptr<Node<T>> head = nullptr;
    /**
     * Retrieve Node from the LinkedList at the given position index
     *
     * This function will find the corresponding Node according to the
     * specified posiiton. If the position specified is not valid, it will
     * simply return a null pointer. However, if the position is valid, it will
     * return a pointer that point to the Node location.
     *
     * @returns pointer to to the Node at the given position index
     */
    std::shared_ptr<Node<T>> find(size_t index) const;
    void ascendingOrderSort();
    void descendingOrderSort();

  public:
    /// Size of the LinkedList
    size_t size = 0;

    LinkedList() = default;
    /**
     * Copy the linked list structure to this LinkedList
     *
     * This could be handy if linked list is needed to be copy. For example:
     *
     * @code{.cpp}
     * LinkedList<T> w = v;
     * @endcode
     *
     * LinkedList<T> w will copy the linked list within LinkedList<T> v.
     *
     * @param rhs Right hand side object of type LinkedList<T>
     * @note Follow RAII guidline
     */
    LinkedList(const LinkedList<T>& rhs);
    /**
     * Assign the LinkedList properly
     *
     * This could be handy if linked list, instead of being copy, is needed to
     * be assigned to an existing object. For example:
     *
     * @code{.cpp}
     * LinkedList<T> w;
     * w = v;
     * @endcode
     *
     * LinkedList<T> w will copy the linked list within LinkedList<T> v.
     *
     * @param rhs Right hand side object of type LinkedList<T>
     * @note Follow RAII guideline
     * @note Follow copy-and-swap idiom.
     * @see void swap(LinkedList<T>& b) noexcept
     */
    LinkedList<T>& operator=(const LinkedList<T>& rhs);
    /**
     * Calling LinkedList builtin swap instead of default std::swap
     *
     * This function will call LinkedList own implementation of swapping
     * mechanism instead of the default one provided by the standard library.
     *
     * @param a This object of type LinkedList
     * @param b Other object of type LinkedList to be swapped with
     * @attention The order of the swap is important
     * @note Follow copy-and-swap idiom.
     * @see void swap(LinkedList<T>& b) noexcept
     */
    template<class U>
      friend void swap(LinkedList<T>& a, LinkedList<T>& b) noexcept;
    /**
     * Swap the link list structure with another LinkedList
     *
     * This function will swap the LinkedList head pointer and its size to
     * other LinkedList specified in the parameter.
     *
     * @param b Other object of type LinkedList<T> to be swapped with
     * @note Follow copy-and-swap idiom.
     */
    void swap(LinkedList<T>& b) noexcept;
    ~LinkedList() = default;

    /**
     * Check if the LinkedList is empty
     *
     * This function will check whether the LinkedList is empty or not by
     * looking at the header. If the header is a null pointer, then this
     * LinkedList is empty. Otherwise, it should be not empty.
     *
     * @retval true If the LinkedList is empty
     * @retval false If the LinkedList is not empty
     */
    bool isEmpty() const noexcept;
    /**
     * Make the LinkedList empty
     *
     * This function will emptied the LinkedList if the LinkedList itself is
     * not empty. It is done by removing the Node inside the LinkedList one by
     * one. However, if the LinkedList is empty, this function will not do
     * anything.
     *
     * @retval true If the LinkedList is not empty
     * @retval false If the LinkedList is empty already
     */
    bool makeEmpty();
    /**
     * Insert element into the LinkedList at the given position index
     *
     * This function will insert the element at the front of the header or any
     * location that is cosidered valid, which should always not larger than
     * the LinkedList's size. Upon every insertion, a Node will be dynamically
     * allocated to store the inserted element and the size of the LinkedList
     * will be incremented.
     *
     * @param element Thing to be inserted into LinkedList
     * @param index Position of Node to be inserted
     * @retval true If the element has been successfully inserted in LinkedList
     * @retval false If position index is invalid or failed to allocate memory
     */
    bool insert(T element, size_t index);
    /**
     * Retrieve element from the LinkedList at the given position index
     *
     * This function will traverse until the the specified position index on
     * the LinkedList if the position index is valid. Then, it will simply
     * return the stored element. If the position index is not valid, an empty
     * object with the same type to the stored element will be returned.
     *
     * @param index Position of Node to be retrieved
     * @returns Element reside at the Node position at the given index
     */
    const T retrieve(size_t index) const;
    /**
     * Search whether the element is present in the LinkedList
     *
     * This function will search through the LinkedList to see whether the
     * element specified is reside in it. If the element has been found, it
     * will return the position index of it immediately.
     *
     * @param element Thing to be searched
     * @returns Zero or the position index of the found element in the
     *    LinkedList
     * @retval 0 If the element is not found
     * @retval >0 If the element found
     */
    size_t search(T element) const noexcept;
    /**
     * Remove element from the LinkedList if it is present
     *
     * This function will remove stored element according to the specified
     * value. If the element specified is not found, remove operation will be
     * unsuccessful and will not remove anything in the LinkedList. If the
     * operation is succeeded, the found element will be removed from the
     * LinkedList.
     *
     * @param element Thing to be removed
     * @retval true If the element is present in the LinkedList
     * @retval false If the element is not present in the LinkedList
     */
    bool remove(T element);
    /**
     * Remove element from the LinkedList at the given position index
     *
     * This function will remove storead element according to the specified
     * position. Same as insertion, the position specified should be valid
     * which means that the passed value should always be smaller or equal to
     * the size of LinkedList. If the position specified is invalid, remove
     * operation will be unsuccessful and will not remove anything in the
     * LinkedList. If the operation is succeeded, the element at the position
     * given will be removed from the LinkedList.
     *
     * @param index Position of the Node to be removed
     * @retval true If the element is present in the LinkedList
     * @retval false If the element is not present in the LinkedList
     */
    bool remove(size_t index);
    /**
     * Sort the LinkedList using bubble sort in either ascending or descending
     * order
     *
     * This function will sort the LinkedList accords to what user desired. If
     * the value of isAscending is true, then it will run ascendingOrderSort
     * under the hook. Otherwise, descendingOrderSort will be used to sort the
     * items in the LinkedList.
     *
     * @param isAscending Boolean option to sort the list in ascending order
     * @attention All objects that wise to be sorted should implement operator<
     *    and operator>
     * @see void ascendingOrderSort()
     * @see void descendingOrderSort()
     * @see https://en.wikipedia.org/wiki/Bubble_sort
     */
    void sort(bool isAscending);
};

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
