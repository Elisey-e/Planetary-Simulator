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

class Textbox {
    sf::Text text;
    sf::RectangleShape box;

    public:
        Textbox(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
        {
            text.setString(t);
            text.setFillColor(textColor);
            text.setCharacterSize(charSize);

            box.setSize(size);
            box.setFillColor(bgColor);
        }

        void setText (std::string t)
        {
            text.setString(t);
        }

        void setFont (sf::Font &font)
        {
            text.setFont(font);
        }

        void setBackColor(sf::Color color)
        {
            box.setFillColor(color);
        }

        void setTextColor(sf::Color color)
        {
            text.setFillColor(color);
        }

        void setPosition(sf::Vector2f pos)
        {
            box.setPosition(pos);

            text.setPosition({pos.x, pos.y});
        }

        void drawTo(sf::RenderWindow &window)
        {
            window.draw(box);
            window.draw(text);
        }
};

class Textbox {
    sf::Text text;
    sf::RectangleShape box;

    public:
        Textbox(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
        {
            text.setString(t);
            text.setFillColor(textColor);
            text.setCharacterSize(charSize);

            box.setSize(size);
            box.setFillColor(bgColor);
        }

        void setText (std::string t)
        {
            text.setString(t);
        }

        void setFont (sf::Font &font)
        {
            text.setFont(font);
        }

        void setBackColor(sf::Color color)
        {
            box.setFillColor(color);
        }

        void setTextColor(sf::Color color)
        {
            text.setFillColor(color);
        }

        void setPosition(sf::Vector2f pos)
        {
            box.setPosition(pos);

            text.setPosition({pos.x, pos.y});
        }

        void drawTo(sf::RenderWindow &window)
        {
            window.draw(box);
            window.draw(text);
        }
};

namespace Simulator {
    template <typename Val_Type>
    class Renderer final
    {
        // Graphics::Screen object;
        sf::RenderWindow window;

        // Textbox with info
        Textbox box;

        tick_t fps = 50;    // Frame rate
        // Textbox with info
        Textbox box;

        tick_t fps = 50;    // Frame rate

        std::vector<Planet<Val_Type>> planets;

        public:
            // Constructor, gets name of a data base, opens the input stream of the data base
            Renderer(std::vector<Planet<Val_Type>> pl) : planets(pl), window(sf::VideoMode(1000, 500), "Planet Sinulator"), 
                box("Name:\nMass:", {150, 50}, 20, sf::Color(220, 220, 220), sf::Color::Black)
            {
                // Initialization of the window
                window.setFramerateLimit(fps);

                // Seeding generator
                // Initialization of the window
                window.setFramerateLimit(fps);

                // Seeding generator
                std::srand(std::time(nullptr));
                
                // Downloading the font
                sf::Font arial;
                arial.loadFromFile("ARIAL.TTF");

                // Initializing the textbox
                box.setPosition({850, 0});
                box.setFont(arial);
                
                // Downloading the font
                sf::Font arial;
                arial.loadFromFile("ARIAL.TTF");

                // Initializing the textbox
                box.setPosition({850, 0});
                box.setFont(arial);
            }

            // Returns the frame rate
            tick_t get_fps()
            {
                return fps;
            }
            
            // Returns the pointer to the graphics window
            sf::RenderWindow &getWindow()
            sf::RenderWindow &getWindow()
            {
                return window;
                return window;
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
            void drawPlanet(auto obj, sf::CircleShape circle, sf::RenderWindow &window) // Planet -> auto
            void drawPlanet(auto obj, sf::CircleShape circle, sf::RenderWindow &window) // Planet -> auto
            {
                sf::Vector2u size = window.getSize();
                sf::Vector2u size = window.getSize();
                unsigned int width = size.x;
                unsigned int height = size.y;
                std::vector<Val_Type> data = obj.get_data();
                circle.setPosition((size.x / 2) + data[0], (size.y / 2) - data[1]);

                window.draw(circle);
                window.draw(circle);
            }

            // Updates the window
            void update() // Changed from bool to void
            {
                int n = planets.size();

                // Clearing the window
                // Clearing the window
                window.clear();

                // Drawing the planets
                // Drawing the planets
                for (int i = 0; i < n; i++)
                {
                    drawPlanet(planets[i], setPlanet(planets[i]), window);
                }

                sf::Event event;

                // Listening for events for updating the textbox
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        window.close();
                    }
                    if (event.type == sf::Event::MouseMoved)
                    {
                        for (int i = 0; i < n; i++)
                        {
                            if (planets[i].isMouseOver(window))
                            {
                                box.setText("Name: " + planets[i].get_name() + "\n" + "Mass: " + std::to_string(planets[i].get_data()[4]));
                            }
                            else
                            {
                                box.setText("Name:\nMass:");
                            }
                        }
                    }
                }

                // Drawing the textbox
                box.drawTo(window);

                // Displaying graphics
                window.display();
            }

            // Closing the graphics window
            // Closing the graphics window
            void close()
            {
                window.close();
            };
    };
}
