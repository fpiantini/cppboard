# cppboard
[![Build Status](https://travis-ci.org/fpiantini/cppboard.svg?branch=main)](https://travis-ci.org/fpiantini/cppboard)

A 8x8 Bitboard implementation in C++

## What's a Bitboard?

From [wikipedia]:

_A bitboard is a specialized bit array data structure commonly used in computer systems that play board games, where each bit corresponds to a game board space or piece. This allows parallel bitwise operations to set or query the game state, or determine moves or plays in the game._

_Bits in the same bitboard relate to each other by the rules of the game, often forming a game position when taken together. Other bitboards are commonly used as masks to transform or answer queries about positions. Bitboards are applicable to any game whose progress is represented by the state of, or presence of pieces on, discrete spaces of a gameboard, by mapping of the space states to bits in the data structure. Bitboards are a more efficient alternative board representation to the traditional mailbox representation, where each piece or space on the board is an array element._

_Bitboards are especially effective when the associated bits of various related states on the board fit into a single word or double word of the CPU architecture, so that single bitwise operators like AND and OR can be used to build or query game states._

_Among the computer game implementations that use bitboards are chess, checkers, othello and word games. The scheme was first employed in checkers programs in the 1950s, and since the mid-1970s has been the de facto standard for game board representation in computer automatons. [...]_

[wikipedia]: https://en.wikipedia.org/wiki/Bitboard