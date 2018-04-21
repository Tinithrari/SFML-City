#pragma once

namespace collision
{
    class ICollisionObserver;
    
    /**
    * @brief An interface for objects which manage collision and need to be observed
    */
    class ICollisionObservable
    {
    public:
        
        /**
        * @brief Add a collision observer to the list of object to notify
        * 
        * @param obs A pointer on the object to notify
        */
        virtual void addCollisionObserver(ICollisionObserver *obs) = 0;
        
        /**
        * @brief Remove a collision observer from the list of object to notify
        * 
        * @param obs A pointer on the object to remove from the list
        */
        virtual void removeCollisionObserver(ICollisionObserver *obs) = 0;
        
        /**
        * @brief Notify all the collision observers for a collision
        * 
        * @param other The other object which entered in collision with the current one
        */
        virtual void notifyCollisionObservers(ICollisionObserver *other) = 0;
    }
}
