#pragma once

/**
 * @file StackAllocator.hpp
 * @brief Gestionnaire de memoire base sur la pile
 * @author Xavier Heugue
 * @version 1.0
 */

#include <cstdint>
#include <cmath>
#include <stdexcept>
#include <iostream>

using namespace std;

using u64 = uint64_t;

/**
 * @namespace memory
 *
 * Espace de nommage pour la gestion de la memoire
 */
namespace memory
{
    /**
     * @class StackAllocator
     *
     * Allocateur de memoire base sur la structure de donnees de la pile
     */
    class StackAllocator
    {
    private:
        u64* _top; /*<! Pointeur sur le haut de la pile */
        u64* _memory; /*<! Pointeur sur le bloc de memoire allouee */
        size_t _size; /*<! Taille du bloc de memoire */
    public:
        /**
         * Constructeur par defaut
         */
        StackAllocator(unsigned int size): _size(size)
        {
            _memory = new u64[size];
            _top = _memory;
        }

        /**
         * Destructeur
         */
        ~StackAllocator()
        {
            delete[] _memory;
        }

        /**
         * Alloue un bloc memoire dans la pile
         *
         * @brief Alloue un bloc memoire dans la pile
         * @param size taille du bloc alloue
         * @return L'adresse sur le bloc alloue de la pile
         */
        u64 *allocate(size_t size)
        {
            if (_top + size > _memory + _size)
                throw overflow_error("Impossible d'allouer plus de ressources");

            u64 *memoryBloc = _top;
            _top += (int) ceil(size / sizeof(u64)) + 1;

            return memoryBloc;
        }

        /**
         * Desalloue le bloc de memoire de la pile, si il n'est pas au sommet de la pile, rien n'est effectue
         *
         * @brief Desalloue le bloc de memoire
         * @param ptr Le pointeur sur le bloc de memoire
         * @param size La taille du bloc de memoire
         */
        void deallocate(u64 *ptr, size_t size)
        {
            if (ptr == nullptr)
                throw invalid_argument("le pointeur ne doit pas etre nul");

            if ((ptr + (int)ceil(size / sizeof(u64)))== _top)
                _top = ptr;
        }
        
        /**
         * Nettoie le contenu de la pile
         * @brief Nettoie le contenu de la pile
         */
        inline void clear() { _top = _memory; }
    };
}
