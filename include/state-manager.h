#ifndef C_PONG_STATE_MANAGER_H
#define C_PONG_STATE_MANAGER_H

#include <stdbool.h>


typedef enum {
    MAIN_MENU,
    SETTINGS,
    GAMEPLAY,
    PAUSE,
} State;

typedef struct {
    bool is_running;
    State state;
    void (*draw)();
    void (*update)();
} StateManager;

extern StateManager state_manager;

/**
 * @brief Initializes the state manager and sets the initial state.
 * 
 * This function is used to initialize the global `state_manager` instance, setting
 * the initial state of the game and preparing the appropriate draw and update functions.
 * Typically called at the start of the game or application to set up the state manager.
 */
void init_state_manager();

/**
 * @brief Changes the current state of the game.
 * 
 * This function switches the current state of the game by setting the `state` field
 * of the `state_manager` and assigning appropriate functions for `draw` and `update`.
 * 
 * @param state The new state to switch to.
 */
void change_state_manager_state(const State state);

#endif /* C_PONG_STATE_MANAGER_H */