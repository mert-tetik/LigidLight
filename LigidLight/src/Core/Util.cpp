#include <iostream>

#include "Util.hpp"

#include <iostream>

glm::vec3 Util::vec3RGBscaleTo1(glm::vec3 i){
    i/=255.f;
    return i;
}