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

        tick_t fps = 50;    // Частота обновления экрана

        std::vector<std::unique_ptr<Planet<Val_Type>>> & planets;

        public:
            Renderer(std::vector<std::unique_ptr<Planet<Val_Type>>> & pl) : planets(pl) {// Конструктор, принимает название базы данных, открывает входной поток от БД

                // Создает объект типа Screen (из библиотеки с графикой)

            }

            tick_t get_fps(){
                return fps;
            }

            bool show();        // Первый запуск окна с графикой

            bool update();      // Обновление графики; точно не знаю, как реализуешь, но очень хочется, чтобы бросало исключение что-то типа std::user_interrupt

            bool close();       // Закрытие граф окна
    };
}
