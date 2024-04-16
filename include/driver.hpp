#pragma once

#include "include_lib.hpp"

// Released functionality for Val_Type = double

namespace Simulator {
    template <typename Val_Type>
    class Driver final{

        std::vector<std::unique_ptr<Planet<Val_Type>>> planets = {};

        Db_Loader<Val_Type> database;
        Evaluator<Val_Type> evaluator;
        Renderer<Val_Type> renderer;

        public:
            time_t curr_time = 0;
            time_t time_split = 1;
            bool time_limit_exedeed = 0;

            Driver(std::string db_path) : database(db_path, planets), evaluator(planets), renderer(planets) {
                database.load_data();
                renderer.show();
            }

            bool start(){                   // Returns 1 if time limit exeeded, 0 if failed with exception and unmount all interfaces
                if (time_limit_exedeed)
                    return 1;
                try
                {
                    while (curr_time > 0){
                        evaluator.eval_shift(time_split);
                        renderer.update();
                        curr_time += time_split;
                    }
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                    finish();
                    return 0;
                }
                return 1;
            }

            bool iterate(){                 // Returns 1 if time limit exeeded, 0 if ok, else throw exception
                if (time_limit_exedeed)
                    return 1;
                curr_time += time_split;
                evaluator.eval_shift(time_split);

                if (curr_time < 0){
                    return 1;
                }
                return 0;
            }

            bool finish(){
                renderer.close();
                return 0;
            }
    };
}
