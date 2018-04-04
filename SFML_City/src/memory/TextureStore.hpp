#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <stdexcept>

using namespace std;
using namespace sf;

/**
 * @brief Namespace which contains memory management elements
 * 
 */
namespace memory
{
    /**
     * Singleton for Texture storage
     */
    class TextureStore
    {
    private:
        
        static TextureStore      *storage;
        map<string, Texture*>     _store;
        
        /**
         * Default constructor
         */
        TextureStore()
        {
        }
        
    public:
        /**
         * Destructor
         */
        ~TextureStore()
        {
            for (auto it : _store)
            {
                delete it.second;
            }
        }
        
        /**
        * @brief Get a texture from the storage
        * 
        * @param ref p_ref: The string that refer to the image (path)
        * @return sf::Texture* The pointer on the wanted texture
        */
        Texture* getTexture(string ref)
        {
            auto it = _store.find(ref);
            if (it == _store.end())
            {
                Texture* tex = new Texture();
                
                if (! tex->loadFromFile(ref))
                {
                    throw(invalid_argument("The texture " + res + " cannot be loaded"));
                }
                _store.insert(ref, tex);
                it = _store.find(ref);
            }
            
            return it;
        }
        
        /**
        * @brief Get the texture store
        * 
        * @return memory::TextureStore* A pointer on the texture store
        */
        static TextureStore* get()
        {
            if (TextureStore::storage == nullptr)
            {
                storage = new TextureStore();
            }
            
            return storage;
        }
    };
    
    TextureStore TextureStore::storage(nullptr);
}
