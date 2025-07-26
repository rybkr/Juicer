#ifndef PERSISTENCE_H_1E0865B02472BE44
#define PERSISTENCE_H_1E0865B02472BE44

#include <string>


namespace Persistence
{
    void load();
    void save();

    // relative to Juicer root
    static const std::string rook_filepath{ "./movegen/magics/rook_magics.txt" };
}


#endif // PERSISTENCE_H_1E0865B02472BE44
