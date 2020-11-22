#if !defined CPPBOARD_KNIGHTSBOARD_HEADER
#define CPPBOARD_KNIGHTSBOARD_HEADER

#include "cppboard/bitboard.h"
#include "cppboard/bbchessdefs.h"

namespace cppboard
{

  // class for bitboard representation of one side knights (white or black player)
  class KnightsBoard: public BitBoard
  {
    public:
      static const BitBoardState InitialWhite = CH_WhiteKnightsInitial;
      static const BitBoardState InitialBlack = CH_BlackKnightsInitial;

      KnightsBoard() : BitBoard() {};
      KnightsBoard(BitBoardState initState) : BitBoard(initState) {};

      void validMoves(std::set<std::string> &posSet) const;

    private:
      static void addValidMovesForPos(const std::string &c, std::set<std::string> &actCells);
  };

} // namespace cppboard

#endif // #if !defined CPPBOARD_KNIGHTSBOARD_HEADER
