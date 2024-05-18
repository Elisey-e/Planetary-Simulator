#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
#include <cmath>

using std::cin, std::cout, std::endl;

// Released functionality for Val_Type = double

namespace Simulator {
    template <typename Val_Type>
    class Planet{
        std::string name;
        std::vector<Val_Type> properties;   // Рассчитывать на 5 double параметра, пусть пока все параметры в СИ: x, y, v_x, v_y, масса M

        public:
            explicit Planet(std::string nm, std::vector<Val_Type> pr) : name(nm),  properties(pr) {}

            std::vector<Val_Type> get_data() const noexcept {return properties;}

            std::string get_name() const noexcept {return name;}

            bool isMouseOver(sf:: RenderWindow &window)
            {
                float mouseX = sf::Mouse::getPosition(window).x;
                float mouseY = sf::Mouse::getPosition(window).y;

                double R = 100 / (1 + exp(-properties[4]));

                sf::Vector2u size = window.getSize();

                unsigned int width = size.x;
                unsigned int height = size.y;

                if ((((mouseX - ((size.x / 2) + properties[0])) * (mouseX - ((size.x / 2) + properties[0]))) +
                    ((mouseY - ((size.y / 2) - properties[1])) * (mouseY - ((size.y / 2) - properties[1])))) < (R * R))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            
            virtual ~Planet() {}
    };
}