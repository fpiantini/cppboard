#if !defined BITBOARD_HEADER
#define BITBOARD_HEADER

#include <cstdint>   // for uint64_t
#include <string>
#include <list>

// base type for bitboard representation
typedef uint64_t BitBoardState;

namespace bitboard
{

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
