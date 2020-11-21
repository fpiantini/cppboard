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
  const BitBoardState ChTwoKingsInitial            = 0x1000000000000010;


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
