#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>

using std::cin, std::cout, std::endl;

// Released functionality for Val_Type = double

namespace Simulator {
    template <typename Val_Type>
    class Planet{
        std::string name;
        std::vector<Val_Type> properties;   // Рассчитывать на 5 double параметра, пусть пока все параметры в СИ: x, y, v_x, v_y, масса M

        public:
            explicit Planet(std::string nm, std::vector<Val_Type> pr) : name(nm),  properties(pr) {}

            std::vector<Val_Type>* get_data() const noexcept {return &properties;}

            std::string* get_name() const noexcept {return &name;}

            virtual ~Planet() {}
    };
}
