#include "persistence.h"
#include "types.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>


extern std::array<bitboard_t, 64> rook_magics;
extern std::array<size_t,     64> rook_tsizes;

void Persistence::load()
{
    if (!std::filesystem::exists(Persistence::rook_filepath))
    {
        std::fill(rook_magics.begin(), rook_magics.end(), UINT64_MAX);
        std::fill(rook_tsizes.begin(), rook_tsizes.end(), SIZE_MAX);
        Persistence::save();
        return;
    }

    std::ifstream ifs(Persistence::rook_filepath);
    std::string square;
    std::string line;

    for (Square s = Square::A1; s <= Square::H8; ++s)
    {
        std::getline(ifs, line);
        std::istringstream iss(line);
        iss >> square >> rook_magics[static_cast<int>(s)] >> rook_tsizes[static_cast<int>(s)];
    }

    ifs.close();
}

void Persistence::save()
{
    std::ofstream ofs(Persistence::rook_filepath, std::ios::trunc);

    for (Square s = Square::A1; s <= Square::H8; ++s)
    {
        ofs << std::setw(2)  << "ABCDEFGH"[static_cast<int>(s) % 8] << "12345678"[static_cast<int>(s) / 8] << ' ';
        ofs << std::setw(20) << rook_magics[static_cast<int>(s)] << ' ';
        ofs << std::setw(4)  << rook_tsizes[static_cast<int>(s)] << std::endl;
    }

    ofs.close();
}
