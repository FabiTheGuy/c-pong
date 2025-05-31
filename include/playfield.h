#ifndef C_PONG_ARENA_H
#define C_PONG_ARENA_H

#include <raylib.h>

#define BORDER_PERC_X 1.5
#define BORDER_PERC_Y 5
#define BORDER_PERC_GAP 5
#define FONT_SIZE_PERC_Y 15
#define TEXT_PERC_MARGIN_X 5.75
#define TEXT_PERC_MARGIN_Y 5.75

extern Vector2 borderDimensions;
extern int borderGap;
extern int borderCount;

enum SCORE_TYPE {
    SCORE_1,
    SCORE_2,
};


void initArena(void);

void drawArena(void);

void drawScore(const char* score, const enum SCORE_TYPE scoreType);

#endif /* C_PONG_ARENA_H */
