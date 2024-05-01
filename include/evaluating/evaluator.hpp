#pragma once

//------------------------
// Refers to github.com/Elisey-e
//------------------------

#include <iostream>
#include <vector>
#include "planet.hpp"
#include <memory>
#include <cmath>

using std::cin, std::cout, std::endl;

// Released functionality for Val_Type = double

namespace Simulator {
    template <typename Val_Type>
    class Evaluator final{

        const double G = 6.6743 * 10e-11;

        std::vector<std::unique_ptr<Planet<Val_Type>>> & planets;

        public:
            Evaluator(){}

            bool eval_shift_cartesian(time_t step){
                for (auto elem : planets){
                    elem.get_data()[0] += elem.get_data()[2] * step;
                    elem.get_data()[1] += elem.get_data()[3] * step;
                }

                for (auto elem : planets){
                    for (auto src : planets){
                        if (src.get_name() == elem.get_name()){         // Тут добавить хеш
                            continue;
                        }
                        double Rpow2 = (elem.get_data()[0] - src.get_data()[0]) * (elem.get_data()[0] - src.get_data()[0]) + (elem.get_data()[1] - src.get_data()[1]) * (elem.get_data()[1] - src.get_data()[1]);
                        elem.get_data()[2] += G * std::pow(Rpow2, -1.5) * elem.get_data()[4] * src.get_data()[4] * (elem.get_data()[0] - src.get_data()[0]);
                        elem.get_data()[3] += G * std::pow(Rpow2, -1.5) * elem.get_data()[4] * src.get_data()[4] * (elem.get_data()[1] - src.get_data()[1]);
                    }
                }

                return 0;

                // r_1 = r_0 + v_r * step
                // ф_1 = ф_0 + v_ф * step
            }            // Calculate planet positions at moment, near current date, adjusted by step

            bool eval_shift_polaric(time_t step);
    };
}
