#ifndef GAMESTATE_H_7408F476C6A3C845
#define GAMESTATE_H_7408F476C6A3C845

#include "types.h"

struct GameState {
    bitboard_t P, N, B, R, Q, K; // uppercase and lowercase will represent white
    bitboard_t p, n, b, r, q, k; // and black respectively, as in FEN notation

    constexpr GameState(bitboard_t P, bitboard_t N, bitboard_t B, bitboard_t R,
                        bitboard_t Q, bitboard_t K, bitboard_t p, bitboard_t n,
                        bitboard_t b, bitboard_t r, bitboard_t q, bitboard_t k)
        : P(P), N(N), B(B), R(R), Q(Q), K(K), p(p), n(n), b(b), r(r), q(q),
          k(k) {}

    template <Color C, PieceType Pt> constexpr bitboard_t bitboard();

    static consteval GameState INIT();
    static consteval GameState EMPTY();
};

#endif // GAMESTATE_H_7408F476C6A3C845
