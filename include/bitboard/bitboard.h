#if !defined BITBOARD_HEADER
#define BITBOARD_HEADER

#include <cstdint>   // for uint64_t
#include <string>
#include <set>

// base type for bitboard representation

namespace bitboard
{

  typedef uint64_t BitBoardState;

  // Typical bitboards configutations
  // Generic
  const BitBoardState ClearBoard                   = 0;
  const BitBoardState BottomLeftUpperRightDiagonal = 0x8040201008040201;
  const BitBoardState BottomRightUpperLeftDiagonal = 0x0102040810204080;
  const BitBoardState BoardCenter                  = 0x0000001818000000;
  const BitBoardState Corners                      = 0x8100000000000081;

  // Checkers related
  const BitBoardState CHK_WhiteInitial             = 0x000000000055AA55;
  const BitBoardState CHK_BlackInitial             = 0xAA55AA0000000000;
  const BitBoardState CHK_Initial                  = CHK_WhiteInitial | CHK_BlackInitial;

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
    BitBoard(BitBoardState initState) : BitBoard() { bbs = initState; }
    BitBoard(const std::string& pos) : BitBoard() { setPos(pos); }
    BitBoard(const std::set<std::string>& pos) : BitBoard() { setPos(pos); }

    void reset() { bbs = ClearBoard; }
    static BitBoardState generateStateFromPos(const std::string &pos) { return BitBoard(pos).state(); };
    void setPos(const std::string &pos);
    void setPos(const std::set<std::string>& poslist);
    void clearPos(const std::string &pos);
    void clearPos(const std::set<std::string>& poslist);
    void move(const std::string &from, const std::string &to);

    bool isBusy(const std::string &pos) const { return ((bbs & generateStateFromPos(pos)) != 0); }

    bool cellIsActive(std::string &pos);
    void activeCells(std::set<std::string> &actCells);

    BitBoardState state() const {return bbs;}

  private:
    static bool isValidPos(const std::string &pos);
    static bool isValidRow(char row);
    static bool isValidColumn(char col);
    static BitBoardState pos2mask(const std::string &pos);
    static unsigned int posToBitPos(const std::string &pos);

    // ------------------------------------
    BitBoardState bbs;


  };

} // namespace bitboard

#endif // #if !defined BITBOARD_HEADER
