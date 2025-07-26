#ifndef TYPES_H_6BA095D505C6C541
#define TYPES_H_6BA095D505C6C541


#include <cstdint>
#include <cstddef>
#include <array>
#include <string>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// @section: Bitboards
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

using bitboard_t = uint64_t;

namespace Bitboard
{
    static constexpr bitboard_t RANK_1 { 0xFFULL };
    static constexpr bitboard_t RANK_2 { 0xFF00ULL };
    static constexpr bitboard_t RANK_3 { 0xFF0000ULL };
    static constexpr bitboard_t RANK_4 { 0xFF000000ULL };
    static constexpr bitboard_t RANK_5 { 0xFF00000000ULL };
    static constexpr bitboard_t RANK_6 { 0xFF0000000000ULL };
    static constexpr bitboard_t RANK_7 { 0xFF000000000000ULL };
    static constexpr bitboard_t RANK_8 { 0xFF00000000000000ULL };

    static constexpr bitboard_t FILE_A { 0x0101010101010101ULL };
    static constexpr bitboard_t FILE_B { 0x0202020202020202ULL };
    static constexpr bitboard_t FILE_C { 0x0404040404040404ULL };
    static constexpr bitboard_t FILE_D { 0x0808080808080808ULL };
    static constexpr bitboard_t FILE_E { 0x1010101010101010ULL };
    static constexpr bitboard_t FILE_F { 0x2020202020202020ULL };
    static constexpr bitboard_t FILE_G { 0x4040404040404040ULL };
    static constexpr bitboard_t FILE_H { 0x8080808080808080ULL };

    static constexpr bitboard_t A1 { FILE_A & RANK_1 };
    static constexpr bitboard_t B1 { FILE_B & RANK_1 };
    static constexpr bitboard_t C1 { FILE_C & RANK_1 };
    static constexpr bitboard_t D1 { FILE_D & RANK_1 };
    static constexpr bitboard_t E1 { FILE_E & RANK_1 };
    static constexpr bitboard_t F1 { FILE_F & RANK_1 };
    static constexpr bitboard_t G1 { FILE_G & RANK_1 };
    static constexpr bitboard_t H1 { FILE_H & RANK_1 };
    static constexpr bitboard_t A2 { FILE_A & RANK_2 };
    static constexpr bitboard_t B2 { FILE_B & RANK_2 };
    static constexpr bitboard_t C2 { FILE_C & RANK_2 };
    static constexpr bitboard_t D2 { FILE_D & RANK_2 };
    static constexpr bitboard_t E2 { FILE_E & RANK_2 };
    static constexpr bitboard_t F2 { FILE_F & RANK_2 };
    static constexpr bitboard_t G2 { FILE_G & RANK_2 };
    static constexpr bitboard_t H2 { FILE_H & RANK_2 };
    static constexpr bitboard_t A3 { FILE_A & RANK_3 };
    static constexpr bitboard_t B3 { FILE_B & RANK_3 };
    static constexpr bitboard_t C3 { FILE_C & RANK_3 };
    static constexpr bitboard_t D3 { FILE_D & RANK_3 };
    static constexpr bitboard_t E3 { FILE_E & RANK_3 };
    static constexpr bitboard_t F3 { FILE_F & RANK_3 };
    static constexpr bitboard_t G3 { FILE_G & RANK_3 };
    static constexpr bitboard_t H3 { FILE_H & RANK_3 };
    static constexpr bitboard_t A4 { FILE_A & RANK_4 };
    static constexpr bitboard_t B4 { FILE_B & RANK_4 };
    static constexpr bitboard_t C4 { FILE_C & RANK_4 };
    static constexpr bitboard_t D4 { FILE_D & RANK_4 };
    static constexpr bitboard_t E4 { FILE_E & RANK_4 };
    static constexpr bitboard_t F4 { FILE_F & RANK_4 };
    static constexpr bitboard_t G4 { FILE_G & RANK_4 };
    static constexpr bitboard_t H4 { FILE_H & RANK_4 };
    static constexpr bitboard_t A5 { FILE_A & RANK_5 };
    static constexpr bitboard_t B5 { FILE_B & RANK_5 };
    static constexpr bitboard_t C5 { FILE_C & RANK_5 };
    static constexpr bitboard_t D5 { FILE_D & RANK_5 };
    static constexpr bitboard_t E5 { FILE_E & RANK_5 };
    static constexpr bitboard_t F5 { FILE_F & RANK_5 };
    static constexpr bitboard_t G5 { FILE_G & RANK_5 };
    static constexpr bitboard_t H5 { FILE_H & RANK_5 };
    static constexpr bitboard_t A6 { FILE_A & RANK_6 };
    static constexpr bitboard_t B6 { FILE_B & RANK_6 };
    static constexpr bitboard_t C6 { FILE_C & RANK_6 };
    static constexpr bitboard_t D6 { FILE_D & RANK_6 };
    static constexpr bitboard_t E6 { FILE_E & RANK_6 };
    static constexpr bitboard_t F6 { FILE_F & RANK_6 };
    static constexpr bitboard_t G6 { FILE_G & RANK_6 };
    static constexpr bitboard_t H6 { FILE_H & RANK_6 };
    static constexpr bitboard_t A7 { FILE_A & RANK_7 };
    static constexpr bitboard_t B7 { FILE_B & RANK_7 };
    static constexpr bitboard_t C7 { FILE_C & RANK_7 };
    static constexpr bitboard_t D7 { FILE_D & RANK_7 };
    static constexpr bitboard_t E7 { FILE_E & RANK_7 };
    static constexpr bitboard_t F7 { FILE_F & RANK_7 };
    static constexpr bitboard_t G7 { FILE_G & RANK_7 };
    static constexpr bitboard_t H7 { FILE_H & RANK_7 };
    static constexpr bitboard_t A8 { FILE_A & RANK_8 };
    static constexpr bitboard_t B8 { FILE_B & RANK_8 };
    static constexpr bitboard_t C8 { FILE_C & RANK_8 };
    static constexpr bitboard_t D8 { FILE_D & RANK_8 };
    static constexpr bitboard_t E8 { FILE_E & RANK_8 };
    static constexpr bitboard_t F8 { FILE_F & RANK_8 };
    static constexpr bitboard_t G8 { FILE_G & RANK_8 };
    static constexpr bitboard_t H8 { FILE_H & RANK_8 };

    // @brief: Returns the number of set bits in a bitboard.
    // ex.: popcount(1) == 1, popcount(2) == 1, popcount(15) == 4
    static constexpr size_t popcount(bitboard_t);
}; // namespace Bitboard


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// @section: Board Constructs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

enum class Square
{
    BEGIN,
    A1 = 0,  B1, C1, D1, E1, F1, G1, H1,
    A2 = 8,  B2, C2, D2, E2, F2, G2, H2,
    A3 = 16, B3, C3, D3, E3, F3, G3, H3,
    A4 = 24, B4, C4, D4, E4, F4, G4, H4,
    A5 = 32, B5, C5, D5, E5, F5, G5, H5,
    A6 = 40, B6, C6, D6, E6, F6, G6, H6,
    A7 = 48, B7, C7, D7, E7, F7, G7, H7,
    A8 = 56, B8, C8, D8, E8, F8, G8, H8,
    N,
    END = N,
    NONE,
};

constexpr Square& operator++(Square& s) { return s = static_cast<Square>(static_cast<int>(s) + 1); }
constexpr Square& operator--(Square& s) { return s = static_cast<Square>(static_cast<int>(s) - 1); }


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// @section: Game Constructs
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

enum class PieceType
{
    BEGIN,
    PAWN = 0, KNIGHT, BISHOP, ROOK, QUEEN, KING,
    N,
    END = N,
    NONE,
};


static constexpr size_t Bitboard::popcount(bitboard_t bb)
{
#if defined(__GNUC__)
    #define CONSTEXPR_POPCOUNT_AVAILABLE 1
    return __builtin_popcountll(bb);
#elif defined(_MSC_VER)
    #define CONSTEXPR_POPCOUNT_AVAILABLE 1
    return _mm_popcnt_u64(bb);
#else
    #define CONSTEXPR_POPCOUNT_AVAILABLE 0

    static constexpr std::array<uint8_t, 256> popcount_8 {
        [](){
            std::array<uint8_t, 256> ret { 0 };
            for (uint32_t i = 0; i < 256; ++i) for (uint32_t j = i; j; j &= j - 1)
            {
                ++ret[i];
            }
            return ret;
        }()
    };

    union {
        uint64_t u64;
        uint8_t  u8[8];
    } u { static_cast<uint64_t>(bb) };

    return popcnt[u.u8[0]] + popcnt[u.u8[1]] + popcnt[u.u8[2]] + popcnt[u.u8[3]]
         + popcnt[u.u8[4]] + popcnt[u.u8[5]] + popcnt[u.u8[6]] + popcnt[u.u8[7]];
#endif
}


#include "test_assert_bitboard.h"
#include "test_assert_squares.h"

#endif // TYPES_H_6BA095D505C6C541
