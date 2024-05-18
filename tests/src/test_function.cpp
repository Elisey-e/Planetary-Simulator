#include "driver.hpp"
#include <iostream>


using namespace Simulator;

int main(){

    std::cout << "ok\n";

    std::vector<double> prop{0, 0, 0, 0, 5};
    std::string str{"Sun"};
    Planet<double> sun(str, prop);

    std::vector<double> prop2{1, 0, 0, 0, 5};
    std::string str2{"earth"};
    Planet<double> earth(str2, prop2);

    Driver<double> DR{"path", Time_types::SECONDS};

    DR.planets.push_back(sun);
    DR.planets.push_back(earth);

    DR.start();




    std::cout << sun.get_name() << "\n";

    return 0;
}

