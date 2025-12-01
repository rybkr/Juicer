#ifndef TYPES_H_8A2E91C4B79D1C32
#define TYPES_H_8A2E91C4B79D1C32

#include <concepts>
#include <cstddef>
#include <type_traits>

// clang-format off
#define SQUARES                                                                \
    X(A1) X(B1) X(C1) X(D1) X(E1) X(F1) X(G1) X(H1)                            \
    X(A2) X(B2) X(C2) X(D2) X(E2) X(F2) X(G2) X(H2)                            \
    X(A3) X(B3) X(C3) X(D3) X(E3) X(F3) X(G3) X(H3)                            \
    X(A4) X(B4) X(C4) X(D4) X(E4) X(F4) X(G4) X(H4)                            \
    X(A5) X(B5) X(C5) X(D5) X(E5) X(F5) X(G5) X(H5)                            \
    X(A6) X(B6) X(C6) X(D6) X(E6) X(F6) X(G6) X(H6)                            \
    X(A7) X(B7) X(C7) X(D7) X(E7) X(F7) X(G7) X(H7)                            \
    X(A8) X(B8) X(C8) X(D8) X(E8) X(F8) X(G8) X(H8)

#define RANKS \
    X(RANK_1) X(RANK_2) X(RANK_3) X(RANK_4) X(RANK_5) X(RANK_6) X(RANK_7) X(RANK_8)

#define FILES \
    X(FILE_A) X(FILE_B) X(FILE_C) X(FILE_D) X(FILE_E) X(FILE_F) X(FILE_G) X(FILE_H)
// clang-format on

#define X(name) name,

enum class Square {
    SQUARES N,
    BEGIN = 0,
    END = N,
    NONE,
};

enum class Rank {
    RANKS N,
    BEGIN = 0,
    END = N,
    NONE,
};

enum class File {
    FILES N,
    BEGIN = 0,
    END = N,
    NONE,
};

#undef X

#define DEFINE_INCREMENT_DECREMENT_OPERATORS(T)                                \
    constexpr T &operator++(T &t) {                                            \
        return t = static_cast<T>(static_cast<int>(t) + 1);                    \
    };                                                                         \
    constexpr T &operator--(T &t) {                                            \
        return t = static_cast<T>(static_cast<int>(t) - 1);                    \
    };

DEFINE_INCREMENT_DECREMENT_OPERATORS(Square);
DEFINE_INCREMENT_DECREMENT_OPERATORS(Rank);
DEFINE_INCREMENT_DECREMENT_OPERATORS(File);

#undef DEFINE_INCREMENT_DECREMENT_OPERATORS

constexpr File file_of(const Square s) {
    return static_cast<File>(static_cast<int>(s) % 8);
}

constexpr Rank rank_of(const Square s) {
    return static_cast<Rank>(static_cast<int>(s) / 8);
}

using bitboard_t = uint64_t;

constexpr bitboard_t make_bb(const Rank r) {
    return 0xFFULL << (static_cast<int>(r) << 3);
}

constexpr bitboard_t make_bb(const File f) {
    return 0x0101010101010101ULL << static_cast<int>(f);
}

constexpr bitboard_t make_bb(const Square s) {
    return 1ULL << static_cast<int>(s);
}

namespace Bitboard
{

#define X(rank) static constexpr bitboard_t rank{ make_bb(Rank::rank) };
    RANKS
#undef X

#define X(file) static constexpr bitboard_t file{ make_bb(File::file) };
    FILES
#undef X

#define X(square) static constexpr bitboard_t square{ make_bb(Square::square) };
    SQUARES
#undef X

    // @brief: Returns the number of set bits in a bitboard
    // ex.: popcount(1) == 1, popcount(2) == 1, popcount(15) == 4
    static constexpr size_t popcount(bitboard_t);
}; // namespace Bitboard

enum class Color {
    BLACK,
    WHITE,
    N,
    NONE,
};

enum class PieceType {
    BEGIN,
    PAWN = 0,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    N,
    END = N,
    NONE,
};

template <typename... Es>
static consteval size_t enum_key(Es... es)
    requires((std::is_enum_v<Es> && ...))
{
    size_t idx{0};
    ((idx = idx * (1 + static_cast<size_t>(std::remove_cv_t<Es>::N)) +
            static_cast<size_t>(static_cast<std::underlying_type_t<Es>>(es))),
     ...);
    return idx;
}

static constexpr size_t Bitboard::popcount(bitboard_t bb) {
#if defined(__GNUC__)
    return __builtin_popcountll(bb);
#elif defined(_MSC_VER)
    return _mm_popcnt_u64(bb);
#else
    int popcnt{0};
    for (; bb; bb &= bb - 1) {
        ++popcnt;
    }
    return popcnt;
#endif
}

#include "test_assert_board_constructs.h"

#endif // TYPES_H_8A2E91C4B79D1C32
