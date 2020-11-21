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
  const BitBoardState BottomLeftUpperRightDiagonal = 0x8040201008040201;
  const BitBoardState BottomRightUpperLeftDiagonal = 0x0102040810204080;
  const BitBoardState BoardCenter                  = 0x0000001818000000;
  const BitBoardState Corners                      = 0x8100000000000081;


  class BitBoard
  {
  public:
    void reset() { bbs = 0; }
    void setpos(const std::string &pos);
    void setpos(const std::list<std::string>& poslist);

    // ------------------------------------
  public: // to allow testing...
    BitBoardState bbs;

  private:
  unsigned int posToBitpos(const std::string &pos) const;



  };

} // namespace bitboard

#endif // #if !defined BITBOARD_HEADER
