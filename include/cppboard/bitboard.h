#if !defined CPPBOARD_BITBOARD_HEADER
#define CPPBOARD_BITBOARD_HEADER

#include <cstdint>   // for uint64_t
#include <string>
#include <set>

namespace cppboard
{

  typedef uint64_t BitBoardState;

  // Typical bitboards configutations
  // Generic
  const BitBoardState ClearBoard                   = 0;
  const BitBoardState BottomLeftUpperRightDiagonal = 0x8040201008040201;
  const BitBoardState BottomRightUpperLeftDiagonal = 0x0102040810204080;
  const BitBoardState BoardCenter                  = 0x0000001818000000;
  const BitBoardState Corners                      = 0x8100000000000081;

  const int INVALID_COORD = -1;

  // base class for bitboard representation
  class BitBoard
  {
  public:
    BitBoard() { reset(); }
    BitBoard(BitBoardState initState) : BitBoard() { bbs = initState; }
    BitBoard(const std::string& pos) : BitBoard() { setPos(pos); }
    BitBoard(const std::set<std::string>& pos) : BitBoard() { setPos(pos); }

    void reset() { bbs = ClearBoard; }
    static BitBoardState generateStateFromPos(const std::string &pos) { return BitBoard(pos).state(); };
    static BitBoardState generateStateFromPos(const std::set<std::string> &poslist);
    void setPos(const std::string &pos);
    void setPos(const std::set<std::string>& poslist);
    void clearPos(const std::string &pos);
    void clearPos(const std::set<std::string>& poslist);
    void move(const std::string &from, const std::string &to);

    bool cellActive(const std::string &pos) const { return ((bbs & generateStateFromPos(pos)) != 0); }

    void activeCells(std::set<std::string> &actCells) const;
    void activeCellsNdx(std::set<std::pair<int, int>> &actCellsNdx) const;

    BitBoardState state() const {return bbs;}
    static void stateToPosSet(BitBoardState s, std::set<std::string> &posSet);

    static std::pair<int,int> posToCoordinates(const std::string &pos);

    static bool isValidCoords(int row, int col) { return (row >= 0 && row < 8 && col >= 0 && col < 8); }

  private:
    static bool isValidPos(const std::string &pos);
    static bool isValidRow(char row);
    static bool isValidColumn(char col);
    static BitBoardState pos2state(const std::string &pos);
    static unsigned int posToBitPos(const std::string &pos);

    bool cellActiveByNdx(int row, int col) const;

    // ------------------------------------
    BitBoardState bbs;


  };

} // namespace cppboard

#endif // #if !defined CPPBOARD_BITBOARD_HEADER
