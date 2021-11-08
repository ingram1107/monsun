/**
 * @file LinkedList.hpp
 * @brief Linked List Interface
 *
 * @class Node lib/LinkedList.hpp "LinkedList.hpp"
 * @class LinkedList lib/LinkedList.hpp "LinkedList.hpp"
 */
#pragma once
#include "Customer.hpp"
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
    /// Size of the LinkedList
    size_t size = 0;
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
     * Sort the LinkedList using <sorting algorithm implementation> in <order>
     *
     * @todo To review whether this should be decoupled from the LinkedList or
     *    not
     */
    void sort(bool isAscending);
};

template class LinkedList<Customer>;
template class LinkedList<int>;
