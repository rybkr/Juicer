#ifndef GAMESTATE_H_DED37AAE9DF157C8
#define GAMESTATE_H_DED37AAE9DF157C8

#ifndef GAMESTATE_H_C57D030CE03071BE
#define GAMESTATE_H_C57D030CE03071BE

#ifndef GAMESTATE_H_D26ACAF3AE400395
#define GAMESTATE_H_D26ACAF3AE400395

#ifndef GAMESTATE_H_D58D7D85F31E7D09
#define GAMESTATE_H_D58D7D85F31E7D09

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

template <Color C = Color::NONE, PieceType Pt = PieceType::NONE>
constexpr bitboard_t GameState::bitboard() {
    switch (enum_key(C, Pt)) {
    case enum_key(Color::WHITE, PieceType::PAWN):
        return P;
    case enum_key(Color::WHITE, PieceType::KNIGHT):
        return N;
    case enum_key(Color::WHITE, PieceType::BISHOP):
        return B;
    case enum_key(Color::WHITE, PieceType::ROOK):
        return R;
    case enum_key(Color::WHITE, PieceType::QUEEN):
        return Q;
    case enum_key(Color::WHITE, PieceType::KING):
        return K;
    case enum_key(Color::BLACK, PieceType::PAWN):
        return p;
    case enum_key(Color::BLACK, PieceType::KNIGHT):
        return n;
    case enum_key(Color::BLACK, PieceType::BISHOP):
        return b;
    case enum_key(Color::BLACK, PieceType::ROOK):
        return r;
    case enum_key(Color::BLACK, PieceType::QUEEN):
        return q;
    case enum_key(Color::BLACK, PieceType::KING):
        return k;
    }
}

consteval GameState GameState::INIT() {
    return GameState(Bitboard::RANK_2, Bitboard::B1 | Bitboard::G1,
                     Bitboard::C1 | Bitboard::F1, Bitboard::A1 | Bitboard::H1,
                     Bitboard::D1, Bitboard::E1, Bitboard::RANK_7,
                     Bitboard::B8 | Bitboard::G8, Bitboard::C8 | Bitboard::F8,
                     Bitboard::A8 | Bitboard::H8, Bitboard::D8, Bitboard::E8);
}

consteval GameState GameState::EMPTY() {
    return GameState(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

#endif // GAMESTATE_H_7408F476C6A3C845

#endif // GAMESTATE_H_D58D7D85F31E7D09

#endif // GAMESTATE_H_D26ACAF3AE400395

#endif // GAMESTATE_H_C57D030CE03071BE

#endif // GAMESTATE_H_DED37AAE9DF157C8
