#ifndef TYPES_H_453395D9343A5142
#define TYPES_H_453395D9343A5142

#include <cstdint>
#include <string>


namespace Board
{
    enum class Rank: int {
        RANK_1, RANK_2, RANK_3, RANK_4,
        RANK_5, RANK_6, RANK_7, RANK_8,
    };

    enum class File: int {
        FILE_A, FILE_B, FILE_C, FILE_D,
        FILE_E, FILE_F, FILE_G, FILE_H,
    };

    static constexpr File& operator++(File& f) { return f = File(int(f) + 1); }
    static constexpr File& operator--(File& f) { return f = File(int(f) - 1); }

    static constexpr Rank& operator++(Rank& r) { return r = Rank(int(r) + 1); }
    static constexpr Rank& operator--(Rank& r) { return r = Rank(int(r) - 1); }

    static constexpr char to_char(Rank r) { return '1' + int(r); }
    static constexpr char to_char(File f) { return 'a' + int(f); }

    enum class Square: int {
        A8 = 56, B8,  C8,  D8,  E8,  F8,  G8,  H8,
        A7 = 48, B7,  C7,  D7,  E7,  F7,  G7,  H7,
        A6 = 40, B6,  C6,  D6,  E6,  F6,  G6,  H6,
        A5 = 32, B5,  C5,  D5,  E5,  F5,  G5,  H5,
        A4 = 24, B4,  C4,  D4,  E4,  F4,  G4,  H4,
        A3 = 16, B3,  C3,  D3,  E3,  F3,  G3,  H3,
        A2 = 8,  B2,  C2,  D2,  E2,  F2,  G2,  H2,
        A1 = 0,  B1,  C1,  D1,  E1,  F1,  G1,  H1,
    };

    static constexpr Square& operator++(Square& s) { return s = Square(int(s) + 1); }
    static constexpr Square& operator--(Square& s) { return s = Square(int(s) - 1); }
} // namespace Board


using bitboard_t = uint64_t;

namespace Bitboard
{
    static constexpr bitboard_t RANK_1 { 0xFFULL };
    static constexpr bitboard_t RANK_2 { RANK_1 << 8  };
    static constexpr bitboard_t RANK_3 { RANK_1 << 16 };
    static constexpr bitboard_t RANK_4 { RANK_1 << 24 };
    static constexpr bitboard_t RANK_5 { RANK_1 << 32 };
    static constexpr bitboard_t RANK_6 { RANK_1 << 40 };
    static constexpr bitboard_t RANK_7 { RANK_1 << 48 };
    static constexpr bitboard_t RANK_8 { RANK_1 << 56 };

    static constexpr bitboard_t FILE_A { 0x0101010101010101ULL };
    static constexpr bitboard_t FILE_B { FILE_A << 1 };
    static constexpr bitboard_t FILE_C { FILE_A << 2 };
    static constexpr bitboard_t FILE_D { FILE_A << 3 };
    static constexpr bitboard_t FILE_E { FILE_A << 4 };
    static constexpr bitboard_t FILE_F { FILE_A << 5 };
    static constexpr bitboard_t FILE_G { FILE_A << 6 };
    static constexpr bitboard_t FILE_H { FILE_A << 7 };

#define BB_SQUARE(file, rank) static constexpr bitboard_t file##rank { FILE_##file & RANK_##rank }
    BB_SQUARE(A,8); BB_SQUARE(B,8); BB_SQUARE(C,8); BB_SQUARE(D,8); BB_SQUARE(E,8); BB_SQUARE(F,8); BB_SQUARE(G,8); BB_SQUARE(H,8);
    BB_SQUARE(A,7); BB_SQUARE(B,7); BB_SQUARE(C,7); BB_SQUARE(D,7); BB_SQUARE(E,7); BB_SQUARE(F,7); BB_SQUARE(G,7); BB_SQUARE(H,7);
    BB_SQUARE(A,6); BB_SQUARE(B,6); BB_SQUARE(C,6); BB_SQUARE(D,6); BB_SQUARE(E,6); BB_SQUARE(F,6); BB_SQUARE(G,6); BB_SQUARE(H,6);
    BB_SQUARE(A,5); BB_SQUARE(B,5); BB_SQUARE(C,5); BB_SQUARE(D,5); BB_SQUARE(E,5); BB_SQUARE(F,5); BB_SQUARE(G,5); BB_SQUARE(H,5);
    BB_SQUARE(A,4); BB_SQUARE(B,4); BB_SQUARE(C,4); BB_SQUARE(D,4); BB_SQUARE(E,4); BB_SQUARE(F,4); BB_SQUARE(G,4); BB_SQUARE(H,4);
    BB_SQUARE(A,3); BB_SQUARE(B,3); BB_SQUARE(C,3); BB_SQUARE(D,3); BB_SQUARE(E,3); BB_SQUARE(F,3); BB_SQUARE(G,3); BB_SQUARE(H,3);
    BB_SQUARE(A,2); BB_SQUARE(B,2); BB_SQUARE(C,2); BB_SQUARE(D,2); BB_SQUARE(E,2); BB_SQUARE(F,2); BB_SQUARE(G,2); BB_SQUARE(H,2);
    BB_SQUARE(A,1); BB_SQUARE(B,1); BB_SQUARE(C,1); BB_SQUARE(D,1); BB_SQUARE(E,1); BB_SQUARE(F,1); BB_SQUARE(G,1); BB_SQUARE(H,1);
#undef BB_SQUARE

    static constexpr bitboard_t make_square(Board::File f, Board::Rank r) { return 1ULL << ((int(r) * 8) + int(f)); }

    static std::string to_string(bitboard_t bb);
} // namespace Bitboard


#endif // TYPES_H_453395D9343A5142
