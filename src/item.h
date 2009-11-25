/** @file item.h */

#ifndef ITEM_H
#define ITEM_H

namespace dnd {

/**
 * @brief An item class.
 *
 * An item is an object that represents an item in the game. 
 *
 */
class Item {
private:
    /**
     *  The item weight.
     */
    int weight;

    /**
     *  Default constructor.
     */
    Item(void);

public:
    /**
     *  Returns item weight.
     *
     *  @return Item weight
     */
    int weight(void) const;

    /**
     * Main constructor
     *
     * @param[in] weight Item weight.
     */
    Item(int weight);

    /**
     *  Destructor.
     */
    virtual ~Item(void) = 0;
}

} // namespace dnd

#endif // CALENDAR_H
