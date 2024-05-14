#pragma once

//------------------------
// Refers to github.com/IvanLikhodievskiy
//------------------------

#include <iostream>
#include <vector>
#include <planet.hpp>
#include <memory>

using std::cin, std::cout, std::endl;

using tick_t = int;

// Released functionality for Val_Type = double

namespace Simulator {
    template <typename Val_Type>
    class Renderer final{
        // Graphics::Screen object;
        sf::RenderWindow window;

        tick_t fps = 50;    // Частота обновления экрана

        std::vector<std::unique_ptr<Planet<Val_Type>>> & planets;

        public:
            Renderer(std::vector<std::unique_ptr<Planet<Val_Type>>> & pl) : planets(pl), window(sf::VideoMode(1000, 500), "Planet Sinulator") {// Конструктор, принимает название базы данных, открывает входной поток от БД

                // Создает объект типа Screen (из библиотеки с графикой)

            }

            tick_t get_fps(){
                return fps;
            }
            
            sf::RenderWindow *getWindow()
            {
                return &window;
            }

            sf::CircleShape setPlanet(planet obj)
            {
                sf::CircleShape circle;

                circle.setRadius(100 / (1 + exp(-obj.M)));
                circle.setOrigin(circle.getRadius(), circle.getRadius());
                
                circle.setFillColor(sf::Color(std::rand(), std::rand(), std::rand()));
                circle.setOutlineColor(sf::Color(std::rand(), std::rand(), std::rand()));
                circle.setOutlineThickness(5);

                return circle;
            }

            void drawPlanet(planet obj, sf::CircleShape circle, sf::RenderWindow *window)
            {
                sf::Vector2u size = (*window).getSize();
                unsigned int width = size.x;
                unsigned int height = size.y;
                circle.setPosition((size.x / 2) + obj.x, (size.y / 2) - obj.y);

                (*window).draw(circle);
            }

            bool show();        // Первый запуск окна с графикой

            bool update()
                std::srand(std::time(nullptr));

                planet Earth;

                // vector<Val_Type> data = planet.get_data();

                Earth.x = 0;
                Earth.y = 0;
                Earth.v_x = 0;
                Earth.v_y = 0;
                Earth.M = 0;

                sf::CircleShape image = setPlanet(Earth);
                
                {
                    sf::Event event;
                    
                    window.clear();
                    drawPlanet(Earth, image, &window);
                    window.display();
                };      // Обновление графики; точно не знаю, как реализуешь, но очень хочется, чтобы бросало исключение что-то типа std::user_interrupt

            bool close()
            {
                window.close();
            };       // Закрытие граф окна
    };
}
