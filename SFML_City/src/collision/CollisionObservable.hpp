#pragma once

/**
* @brief Namespace which contains elements for collision management
*/
namespace collision
{
    class CollisionObserver;
    
    /**
    * @brief Entity which manage collision and fire an event to object who observe it
    */
    class CollisionObservable
    {
    public:
        
        /**
        * @brief Add a collision observer to the list of entity to notify
        * 
        * @param co A CollisionObserver
        */
        virtual void addCollisionObserver(CollisionObserver& co) = 0;
        
        /**
        * @brief Remove a collision observer to the list of entity to notify
        * 
        * @param co A CollisionObserver
        */
        virtual void removeCollisionObserver(CollisionObserver& co) = 0;
        
        /**
        * @brief Notify the collision observers
        */
        virtual void notifyCollisionObserver() = 0;
    };
}
