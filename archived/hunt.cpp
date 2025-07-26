#include "persistence.h"
#include "movement.h"
#include "types.h"
#include <array>
#include <unordered_map>
#include <iostream>
#include <tuple>

std::array<bitboard_t, 64> rook_magics;
std::array<size_t,     64> rook_tsizes;

std::array<bitboard_t, 64> bishop_magics;
std::array<size_t,     64> bishop_tsizes;

template<PieceType Pt>
static consteval size_t min_tsize(Square s)
{
    const int rank{ static_cast<int>(s) / 8 };
    const int file{ static_cast<int>(s) % 8 };

    if constexpr (Pt == PieceType::ROOK)
    {
        return std::max(1, rank) * std::max(1, file) * std::max(1, 7 - rank) * std::max(1, 7 - file);
    }
    else if constexpr (Pt == PieceType::BISHOP)
    {
        return std::max(1, std::min(rank, file)) * std::max(1, std::min(rank, 7 - file))
             * std::max(1, std::min(7 - rank, file)) * std::max(1, std::min(7 - rank, 7 - file));
    }
    
    return -1;
}

static constexpr std::array<size_t, 64> rook_min_tsizes{
[](){
    std::array<size_t, 64> ret;
    for (Square s = Square::BEGIN; s < Square::END; ++s)
    {
        ret[static_cast<int>(s)] = min_tsize<PieceType::ROOK>(s);
    }
    return ret;
}() };

static constexpr std::array<size_t, 64> bishop_min_tsizes{
[](){
    std::array<size_t, 64> ret;
    for (Square s = Square::BEGIN; s < Square::END; ++s)
    {
        ret[static_cast<int>(s)] = min_tsize<PieceType::BISHOP>(s);
    }
    return ret;
}() };

static std::tuple<PieceType, Square> poorest_performing_magic()
{
    PieceType piece_type;
    Square square;
    double greatest_ratio{ 0 };

    for (Square s = Square::BEGIN; s < Square::END; ++s) for (PieceType pt: { PieceType::BISHOP, PieceType::ROOK })
    {
        const double ratio{
            pt == PieceType::ROOK 
            ? static_cast<double>(rook_tsizes[static_cast<int>(s)]) / rook_min_tsizes[static_cast<int>(s)]
            : static_cast<double>(bishop_tsizes[static_cast<int>(s)]) / bishop_min_tsizes[static_cast<int>(s)]
        };
        if (ratio > greatest_ratio)
        {
            greatest_ratio = ratio;
            piece_type = pt;
            square = s;
        }
    }

    return std::tuple<PieceType, Square>(piece_type, square);
}


int main()
{
    Persistence::load();

    auto x = poorest_performing_magic();
    std::cout << int(std::get<0>(x)) << std::endl;
    std::cout << int(std::get<1>(x)) << std::endl;

    Persistence::save();
}
