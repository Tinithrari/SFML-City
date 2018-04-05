#pragma once

/**
* @brief Namespace which contains elements for collision management
*/
namespace collision
{
    class CollisionObservable;
    
    /**
    * @brief A virtual class to observe collision event from collision observable entity
    */
    class CollisionListener
    {
    public:
        
        /**
        * @brief Method call when a collision happen
        * 
        * @param cl The collision Observable which fired the event
        */
        virtual void notifyCollisionListener(CollisionObservable &cl) = 0;
    };
}
