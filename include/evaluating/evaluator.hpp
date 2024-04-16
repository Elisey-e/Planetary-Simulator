#pragma once

//------------------------
// Refers to github.com/Elisey-e
//------------------------

#include <iostream>
#include <vector>
#include "planet.hpp"
#include <memory>

using std::cin, std::cout, std::endl;

// Released functionality for Val_Type = double

namespace Simulator {
    template <typename Val_Type>
    class Evaluator final{

        std::vector<std::unique_ptr<Planet<Val_Type>>> & planets;

        public:
            Evaluator(){}

            bool eval_shift(time_t step);            // Calculate planet positions at moment, near current date, adjusted by step

    };
}
