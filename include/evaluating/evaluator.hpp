#pragma once

//------------------------
// Refers to github.com/Elisey-e
//------------------------

#include <iostream>
#include <vector>
#include "planet.hpp"
#include <memory>
#include <cmath>
#include "time_type.hpp"
#include "/usr/lib/gcc/x86_64-linux-gnu/11/include/omp.h"


using std::cin, std::cout, std::endl;

// Released functionality for Val_Type = double

namespace Simulator {
    template <typename Val_Type>
    class Evaluator final{

        Time_types time_type;
        int time_multiplier;

        const double G = 6.6743 * 10e-11;

        std::vector<std::unique_ptr<Planet<Val_Type>>> & planets;

        public:
            Evaluator(Time_types type_) : time_type(type_) {
                switch (time_type)
                {
                case Time_types::SECONDS:
                    time_multiplier = Time_types_values[0];
                    break;
                case Time_types::MINUTES:
                    time_multiplier = Time_types_values[1];
                    break;
                case Time_types::HOURS:
                    time_multiplier = Time_types_values[2];
                    break;
                case Time_types::DAYS:
                    time_multiplier = Time_types_values[3];
                    break;
                case Time_types::YEARS:
                    time_multiplier = Time_types_values[4];
                    break;

                default:
                    throw std::runtime_error("Unknown time type!");
                }
            }

            bool eval_shift_cartesian(time_t step){
                for (auto elem : planets){
                    elem.get_data()[0] += elem.get_data()[2] * step;
                    elem.get_data()[1] += elem.get_data()[3] * step;
                }
                #pragma omp parallel
                {

                    #pragma omp for
                    {
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
                    }
                }

                return 0;

                // r_1 = r_0 + v_r * step
                // ф_1 = ф_0 + v_ф * step
            }            // Calculate planet positions at moment, near current date, adjusted by step

            bool eval_shift_polaric(time_t step);

            
    };
}
