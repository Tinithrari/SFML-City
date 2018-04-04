#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Application
{
private:
    RenderWindow _window;
    CircleShape      _shape;
    
    static const String WINDOW_TITLE;
    
    void processEvent()
    {
        Event e;
        
        while (_window.pollEvent(e))
        {
          if (e.type == Event::Closed)
          {
            _window.close();  
          }
        }
    }
    
    void update()
    {
        
    }
    
    void render()
    {
        _window.clear();
        _window.draw(_shape);
        _window.display();
    }
    
public:
    Application() : _window(VideoMode(200, 200), Application::WINDOW_TITLE), _shape(100, 50)
    {
        _shape.setFillColor(Color::Green);
    }
    
    ~Application()
    {}
    
    void run()
    {
        while(_window.isOpen())
        {
          processEvent();
          update();
          render();
        }
    }
};

const String Application::WINDOW_TITLE("SFML works!");
