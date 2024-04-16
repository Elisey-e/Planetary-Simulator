#pragma once

//------------------------
// Refers to github.com/alisavi
//------------------------

#include <iostream>
#include <vector>
#include <planet.hpp>
#include <memory>

using std::cin, std::cout, std::endl;

// Released functionality for Val_Type = double

namespace Simulator {
    template <typename Val_Type>
    class Db_Loader final{
        std::string DB; // Здесь должен быть указатель на объект sqlite
        std::vector<std::unique_ptr<Planet<Val_Type>>> & planets;     // Ссылка на вектор, работает также как вектор

        public:
            Db_Loader(std::string db_path, std::vector<std::unique_ptr<Planet<Val_Type>>> & pl) : DB(db_path), planets(pl) { // Конструктор, принимает название базы данных, открывает входной поток от БД
                size_t N = /*sizeofDB*/1000;
                planets.reserve(N);     // Получаем из БД число планет N, резервируем вектор на него

            }

            bool load_data();             // Считывает строку из/всю БД в std::vector curr_planet, возвращает удалось или нет(бонус: throw std::runtime_error("Error while reading database"))
    };
}
