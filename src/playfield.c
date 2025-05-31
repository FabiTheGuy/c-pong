#include <math.h>
#include <stdio.h>

#include "playfield.h"
#include "config.h"
#include "layout.h"

Vector2 borderDimensions;
int borderGap;
int borderCount;


void initArena(void) {
    borderDimensions = (Vector2) {
        .x = WIN_PERC_X(BORDER_PERC_X),
        .y = WIN_PERC_Y(BORDER_PERC_Y),
    };
    borderGap = WIN_PERC_Y(BORDER_PERC_GAP);
    borderCount = ceil(winDimensions.y / (borderDimensions.y + borderGap)); 
}

void drawArena(void) {
    for (int i = 0; i < borderCount; i++) {
        DrawRectangle(
            winDimensions.x / 2 - borderDimensions.x / 2,
            /* borderDimensions.y / 2 makes the bar look a bit more natural */
            (borderDimensions.y / 2) + i * (borderDimensions.y + borderGap), 
            borderDimensions.x,
            borderDimensions.y,
            WHITE
        );
    }
}

void drawScore(const char* score, const enum SCORE_TYPE scoreType) {
    const int fontSize = WIN_PERC_Y(FONT_SIZE_PERC_Y);
    const Vector2 textMargin = (Vector2) {
        .x = WIN_PERC_X(TEXT_PERC_MARGIN_X),
        .y = WIN_PERC_Y(TEXT_PERC_MARGIN_Y),
    };
    
    const Vector2 textDimensions = MeasureTextEx(GetFontDefault(), score, fontSize, (float) fontSize / 10);
    int textPosX;

    if (scoreType == SCORE_1) {
        textPosX = (winDimensions.x / 2) - textMargin.y - textDimensions.x;
    } else {
        textPosX = (winDimensions.x / 2) + textMargin.y;
    }

    DrawText(score, textPosX, textMargin.y, fontSize, WHITE);
}
