#ifndef GAMESTATE_H_7408F476C6A3C845
#define GAMESTATE_H_7408F476C6A3C845

#include "types.h"


struct GameState
{
    bitboard_t P, N, B, R, Q, K; // uppercase and lowercase will represent white
    bitboard_t p, n, b, r, q, k; // and black respectively, as in FEN notation

    constexpr GameState(
        bitboard_t P, bitboard_t N, bitboard_t B, bitboard_t R, bitboard_t Q, bitboard_t K,
        bitboard_t p, bitboard_t n, bitboard_t b, bitboard_t r, bitboard_t q, bitboard_t k
    ):
        P(P), N(N), B(B), R(R), Q(Q), K(K), p(p), n(n), b(b), r(r), q(q), k(k)
    {}

    static consteval GameState INIT();  // returns the starting position as a GameState
    static consteval GameState EMPTY(); // returns a clear board as a GameState
};

consteval GameState GameState::INIT()
{
    return GameState(
        Bitboard::RANK_2,            // white pawns
        Bitboard::B1 | Bitboard::G1, // white knights
        Bitboard::C1 | Bitboard::F1, // white bishops
        Bitboard::A1 | Bitboard::H1, // white rooks
        Bitboard::D1,                // white queen
        Bitboard::E1,                // white king
        Bitboard::RANK_7,            // black pawns
        Bitboard::B8 | Bitboard::G8, // black knights
        Bitboard::C8 | Bitboard::F8, // black bishops
        Bitboard::A8 | Bitboard::H8, // black rooks
        Bitboard::D8,                // black queen
        Bitboard::E8                 // black king
    );
}

consteval GameState GameState::EMPTY() {
    return GameState(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}


#endif // GAMESTATE_H_7408F476C6A3C845
