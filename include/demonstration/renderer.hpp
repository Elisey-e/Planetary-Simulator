#pragma once

//------------------------
// Refers to github.com/IvanLikhodievskiy
//------------------------

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>
#include <planet.hpp>
#include <memory>

using std::cin, std::cout, std::endl;

using tick_t = int;

// Released functionality for Val_Type = double

namespace Simulator {
    template <typename Val_Type>
    class Renderer final
    {
        // Graphics::Screen object;
        sf::RenderWindow window;

        tick_t fps = 50;    // Частота обновления экрана

        std::vector<std::unique_ptr<Planet<Val_Type>>> & planets;

        public:
            // Constructor, gets name of a data base, opens the input stream of the data base
            Renderer(std::vector<std::unique_ptr<Planet<Val_Type>>> & pl) : planets(pl), window(sf::VideoMode(1000, 500), "Planet Sinulator")
            {
                std::srand(std::time(nullptr));
            }

            // Returns the frame rate
            tick_t get_fps()
            {
                return fps;
            }
            
            // Returns the pointer to the graphics window
            sf::RenderWindow *getWindow()
            {
                return &window;
            }

            // Sets size and position of the planet and returns it
            sf::CircleShape setPlanet(auto obj) // Planet -> auto
            {
                sf::CircleShape circle;

                std::vector<Val_Type> data = obj.get_data();

                circle.setRadius(100 / (1 + exp(-data[4])));
                circle.setOrigin(circle.getRadius(), circle.getRadius());
                
                circle.setFillColor(sf::Color(std::rand(), std::rand(), std::rand()));

                return circle;
            }

            // Creates drwable object
            void drawPlanet(auto obj, sf::CircleShape circle, sf::RenderWindow *window) // Planet -> auto
            {
                sf::Vector2u size = (*window).getSize();
                unsigned int width = size.x;
                unsigned int height = size.y;
                std::vector<Val_Type> data = obj.get_data();
                circle.setPosition((size.x / 2) + data[0], (size.y / 2) - data[1]);

                (*window).draw(circle);
            }

            // Updates the window
            void update() // Changed from bool to void
            {
                int n = planets.size();

                window.clear();

                for (int i = 0; i < n; i++)
                {
                    drawPlanet(planets[i], setPlanet(planets[i]), &window);
                }

                window.display();
            }

            // Закрытие графического окна
            void close()
            {
                window.close();
            };
    };
}
