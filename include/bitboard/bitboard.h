#if !defined BITBOARD_HEADER
#define BITBOARD_HEADER

#include <cstdint>   // for uint64_t
#include <string>
#include <list>

// base type for bitboard representation

namespace bitboard
{

  typedef uint64_t BitBoardState;

  // Typical bitboards configutations
  // Generic
  const BitBoardState BottomLeftUpperRightDiagonal = 0x8040201008040201;
  const BitBoardState BottomRightUpperLeftDiagonal = 0x0102040810204080;
  const BitBoardState BoardCenter                  = 0x0000001818000000;
  const BitBoardState Corners                      = 0x8100000000000081;

  // Chess related
  const BitBoardState CH_WhiteKingInitial          = 0x0000000000000010;
  const BitBoardState CH_BlackKingInitial          = 0x1000000000000000;
  const BitBoardState CH_WhiteQueenInitial         = 0x0000000000000008;
  const BitBoardState CH_BlackQueenInitial         = 0x0800000000000000;
  const BitBoardState CH_WhiteBishopsInitial       = 0x0000000000000042;
  const BitBoardState CH_BlackBishopsInitial       = 0x4200000000000000;
  const BitBoardState CH_WhiteKnightsInitial       = 0x0000000000000024;
  const BitBoardState CH_BlackKnightsInitial       = 0x2400000000000000;
  const BitBoardState CH_WhiteRooksInitial         = 0x0000000000000081;
  const BitBoardState CH_BlackRooksInitial         = 0x8100000000000000;
  const BitBoardState CH_WhitePawnsInitial         = 0x000000000000ff00;
  const BitBoardState CH_BlackPawnsInitial         = 0x00ff000000000000;
  const BitBoardState CH_BothKingsInitial          = CH_WhiteKingInitial | CH_BlackKingInitial;
  const BitBoardState CH_BothQueensInitial         = CH_WhiteQueenInitial | CH_BlackQueenInitial;
  const BitBoardState CH_BothBishopsInitial        = CH_WhiteBishopsInitial | CH_BlackBishopsInitial;
  const BitBoardState CH_BothKnightsInitial        = CH_WhiteKnightsInitial | CH_BlackKnightsInitial;
  const BitBoardState CH_BothRooksInitial          = CH_WhiteRooksInitial | CH_BlackRooksInitial;
  const BitBoardState CH_BothPawnsInitial          = CH_WhitePawnsInitial | CH_BlackPawnsInitial;
  const BitBoardState CH_WhiteFullInitial          = CH_WhiteKingInitial |
                                                     CH_WhiteQueenInitial |
                                                     CH_WhiteBishopsInitial |
                                                     CH_WhiteKnightsInitial |
                                                     CH_WhiteRooksInitial |
                                                     CH_WhitePawnsInitial;
  const BitBoardState CH_BlackFullInitial          = CH_BlackKingInitial |
                                                     CH_BlackQueenInitial |
                                                     CH_BlackBishopsInitial |
                                                     CH_BlackKnightsInitial |
                                                     CH_BlackRooksInitial |
                                                     CH_BlackPawnsInitial;
  const BitBoardState CH_FullInitial               = CH_WhiteFullInitial | CH_BlackFullInitial;


  class BitBoard
  {
  public:
    BitBoard() { reset(); }
    BitBoard(const std::string& pos);
    BitBoard(const std::list<std::string>& pos);

    void reset() { bbs = 0; }
    void setpos(const std::string &pos);
    void setpos(const std::list<std::string>& poslist);

    BitBoardState state() const {return bbs;}

  private:
    unsigned int posToBitpos(const std::string &pos) const;

    // ------------------------------------
    BitBoardState bbs;


  };

} // namespace bitboard

#endif // #if !defined BITBOARD_HEADER
