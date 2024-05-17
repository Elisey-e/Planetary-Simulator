#include "driver.hpp"
#include <iostream>


using namespace Simulator;

int main(){

    std::cout << "ok\n";

    std::vector<double> prop{1, 2, 3, 4, 5};

    std::string str{"Sun"};

    Planet<double> planet(str, prop);

    std::cout << planet.get_name() << "\n";

    return 0;
}

