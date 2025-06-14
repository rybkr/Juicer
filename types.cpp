#include "types.h"
#include <string>
#include <sstream>
#include <iostream>


static std::string Bitboard::to_string(bitboard_t bb) {
    std::ostringstream os {};
    os << "+---+---+---+---+---+---+---+---+\n";

    for (Board::Rank r = Board::Rank::RANK_8; r >= Board::Rank::RANK_1; --r) {
        for (Board::File f = Board::File::FILE_A; f <= Board::File::FILE_H; ++f) {
            os << '|' << ' ' << (bb & Bitboard::make_square(f, r) ? '@' : ' ') << ' ';
        }
        os << '|' << ' ' << to_char(r) << '\n';
        os << "+---+---+---+---+---+---+---+---+\n";
    }

    os << "  a   b   c   d   e   f   g   h";
    return os.str();
}
