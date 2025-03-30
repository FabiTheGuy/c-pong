#include "state_manager.h"
#include "main-menu.h"
#include "settings-menu.h"


StateManager state_manager;


void init_state_manager() {
    state_manager = (StateManager) {0};

    state_manager.is_running = true;

    init_main_menu();
    init_settings_menu();

    change_state_manager_state(MAIN_MENU);
}

void change_state_manager_state(State state) {
    state_manager.state = state;
    
    switch (state) {
        case MAIN_MENU: {
            state_manager.draw = draw_main_menu;
            state_manager.update = update_main_menu;
            break;
        }
        case SETTINGS: {
            state_manager.draw = draw_settings_menu;
            state_manager.update = update_settings_menu;
            break;
        }
    }
}