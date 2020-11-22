#if !defined CPPBOARD_BITBOARD_CHECKERSDEFS_HEADER
#define CPPBOARD_BITBOARD_CHECKERSDEFS_HEADER

#include "cppboard/bitboard.h"

namespace cppboard
{

  const BitBoardState CHK_WhiteInitial             = 0x000000000055AA55;
  const BitBoardState CHK_BlackInitial             = 0xAA55AA0000000000;
  const BitBoardState CHK_Initial                  = CHK_WhiteInitial | CHK_BlackInitial;

} // namespace cppboard

#endif // #if !defined CPPBOARD_BITBOARD_CHECKERSDEFS_HEADER
