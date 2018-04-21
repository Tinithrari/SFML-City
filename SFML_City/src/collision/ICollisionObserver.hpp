#pragma once

namespace collision
{
    class ICollisionObservable;
    
    /**
    * @brief An interface for object which checks the collisions of other objects
    */
    class ICollisionObserver
    {
    public:
        
        /**
        * @brief Notify the object of a collision that happened between two objects
        * 
        * @param obs1 The first object which enter in collision
        * @param obs2 The second object which enter in collision
        */
        virtual void notifyCollision(ICollisionObservable *obs1, ICollisionObservable *obs2);
    };
}
