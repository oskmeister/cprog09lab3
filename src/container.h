/** @file container.h */

#ifndef CONTAINER_H
#define CONTAINER_H

namespace dnd {

/**
 * @brief A container class.
 *
 * A container can contain objects. It has a maximum volumeand a maximum weight of the objects held by the container.
 * We can put objects into the container, remove them, and we also have the possibilty to see what objects are currently being held in the container.
 *
 */
class Container {
private:
    /**
     *  The max weight.
     */
    int max_weight;

    /**
     *  Capacity. Number of items that can be held.
     */
    int capacity;

    /**
     * Storage data structure. A vector is used.
     */
    std::vector<Item *> contents;

    /**
     *  Default constructor.
     */
    Container(void);

public:
    /**
     *  Returns max weight.
     *
     *  @return Item weight
     */
    int max_weight(void) const;

    /**
     * Returns item capacity, in other words the number of items that can be held by this container.
     *
     * @return Capacity
     */
    int capacity(void) const;

    /**
     *  Add an item to the container.
     *
     * @return true if object could be added, otherwise false.
     */
    bool add(Item * item);

    /**
     *  Remove an item from the container.
     *
     *  @return true if object was removed, otherwise false if the object wasn't there.
     */
    bool remove(Item * item);

    /**
     * Lists the objects of the container.
     *
     *  @return An iterator over objects held.
     */
    vector<Item *>::const_iterator items() const;

    /**
     * Main constructor
     *
     * @param[in] max_weight Item max weight
     * @param[in] capacity Item capacity
     */
    Container(int max_weight,int capacity);

    /**
     *  Destructor.
     */
    virtual ~Container(void) = 0;
}

} // namespace dnd

#endif // CONTAINER_H
