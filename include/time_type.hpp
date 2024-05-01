#pragma once
#include "vector"

namespace Simulator{
    enum class Time_types{
        SECONDS,
        MINUTES,
        HOURS,
        DAYS,
        YEARS,
    };

    std::vector<int> Time_types_values = {1, 60, 3600, 86400, 31536000};
}
