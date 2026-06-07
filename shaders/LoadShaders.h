#ifndef PARTICLE_SIM_LOADSHADERS_H
#define PARTICLE_SIM_LOADSHADERS_H
#include <string>


class LoadShaders {
public:
    static unsigned int loadShaders(const std::string& vertexPath, const std::string& fragmentPath);
};


#endif //PARTICLE_SIM_LOADSHADERS_H