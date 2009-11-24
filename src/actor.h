/** @file actor.h */

#ifndef ACTOR_H
#define ACTOR_H

class dnd::Actor;

#include <vector>

#include "item.h"
#include "scene.h"
#include "weapon.h"

namespace dnd
{

/**
 * A class representing an actor in the game.
 *
 * An actor travels between rooms and can hold and wield items. Some actors
 * are also able to fight other actors.
 */
class Actor
{
protected:
    /**
     * The items currently held by the actor.
     */
    std::vector<Item *> inventory;
    
    /**
     * The item currently wielded by the actor.
     */
    Weapon *wielded;

    /**
     * The current location of the player.
     */
    Scene *scene;

    /**
     * The number of health points of the actor.
     * Normal range: [0, 100] where 0 means that the actor is dead.
     */
    int health;

    /**
     * True iff the actor is human.
     */
    bool human;

    /**
     * True iff the actor can fight.
     */
    bool fightable;

    /**
     * A pointer to the actor this actor is currently fighting. NULL if the
     * actor is not currently fighting.
     */
    Actor *opponent;

public:
    /**
     * The error codes the various methods may throw.
     */
    enum Errors {
        NO_SUCH_ITEM,
        NO_ROOM,
        TOO_HEAVY,
        ALREADY_FIGHTING,
        NOT_IN_FIGHT,
        CANNOT_FIGHT
    };

    /**
     * Default constructor.
     *
     * Initializes all values to default values.
     */
    Actor(void);

    /**
     * Make the destructor pure virtual to force inheritance.
     */
    virtual ~Actor(void) = 0; 

    /**
     * @return An iterator to the first element in the items list.
     */
    typename std::vector<Item *>::const_iterator
        inventory_begin(void) const;

    /**
     * @return The number of elements in the inventory.
     */
    size_t inventory_size(void) const;

    /**
     * @return the weapon wielded, or NULL if no weapon is wielded.
     */
    const Weapon *get_wielded(void) const;

    /**
     * @return The type of actor, i.e "Dragon".
     */
    virtual const std::string & get_type(void) const = 0;

    /**
     * @return The name of the actor.
     */
    virtual const std::string & get_name(void) const = 0;

    /**
     * @return The current location of the actor.
     */
    const Scene *get_scene(void) const;

    /**
     * Move the player to another scene.
     *
     * The current as well as the given scene is acknowledged about the move.
     *
     * @param scene The scene to move to.
     */
    void move(Scene *scene);

    /**
     * @return The number of health points of the actor.
     */
    int get_health(void) const;

    /**
     * Set the number of health points of the actor.
     *
     * @param health The new health.
     */
    void set_health(int health);

    /**
     * The maximum weight the actor can hold.
     */
    virtual int max_weight(void) const = 0;

    /**
     * Add an item to the list of owned items.
     * 
     * @throws NO_ROOM if there is no room to store the item in the actor.
     * @throws TOO_HEAVY if the accumulated carried weight of the items of
     *  the actor would be too heavy for the actor to carry.
     * @param item The item to take.
     */
    void add_item(Item *item);

    /**
     * Remove an item from the list of owned items.
     *
     * @throws NO_SUCH_ITEM if the actor does not hold such an item.
     * @param item The item to remove.
     */
    void remove_item(Item *item);

    /**
     * Given a question, returns an answer to the question. The subclasses
     * may return the same answer for every question asked.
     *
     * @param question The question to ask the actor.
     * @return a respond to the given question.
     */
    virtual const std::string & get_respond(const std::string & question) = 0;

    /**
     * Wield the item given.
     *
     * @throws NO_SUCH_ITEM if the actor does not hold such an item.
     * @param weapon The weapon to wield.
     */
    void wield(Weapon *weapon);

    /**
     * Unwields any currently wielded weapon.
     */
    void unwield(void);

    /**
     * @return true iff the actor is human.
     */
    bool is_human(void) const;

    /**
     * Set the type of the actor. Human/Computer.
     *
     * @param human True iff the actor is controlled by a human.
     */
    void set_human(bool human);

    /**
     * @return true iff the actor can fight / is fightable.
     */
    bool can_fight(void) const;

    /**
     * Initiates fight with the given opponent. 
     *
     * @throws ALREADY_FIGHTING if either the actor or the opponent is already
     *  in a fight.
     * @throws CANNOT_FIGHT if one of the actors are not fightable.
     * @param opponent The opponent to fight.
     */
    void fight(Actor *opponent);

    /**
     * @return the opponent of the actor.
     */
    Actor *get_opponent(void);

    /**
     * @return true iff the actor is in a fight.
     */
    bool is_fighting(void) const;

    /**
     * Try to flee from the fight.
     *
     * @throws NOT_IN_FIGHT if the actor is not in a fight.
     * @return true iff successful.
     */
    bool flee(void);
};

}

#endif // ACTOR_H
