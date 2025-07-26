#include "types.h"
#include <string>
#include <sstream>
#include <iostream>


std::string Bitboard::to_string(bitboard_t bb)
{
    std::ostringstream os {};
    os << "+---+---+---+---+---+---+---+---+\n";

    for (Board::Rank r = Board::Rank::RANK_8; r >= Board::Rank::RANK_1; --r)
    {
        for (Board::File f = Board::File::FILE_A; f <= Board::File::FILE_H; ++f)
        {
            os << '|' << ' ' << (bb & Bitboard::make_bb(f, r) ? '@' : ' ') << ' ';
        }
        os << '|' << ' ' << (1 + static_cast<int>(r)) << '\n';
        os << "+---+---+---+---+---+---+---+---+\n";
    }

    os << "  a   b   c   d   e   f   g   h";
    return os.str();
}
