#include <core/logger.h>
#include <core/asserts.h>

// TODO: Test
#include <platform/platform.h>

int main(void) {
    EPHFATAL("A test message: %f", 3.14f);
    EPHERROR("A test message: %f", 3.14f);
    EPHWARN("A test message: %f", 3.14f);
    EPHINFO("A test message: %f", 3.14f);
    EPHDEBUG("A test message: %f", 3.14f);
    EPHTRACE("A test message: %f", 3.14f);

    platform_state state;
    if(platform_startup(&state, "Elephant Engine Testbed", 100, 100, 1280, 720)){
        while(TRUE){
            platform_pump_messages(&state);
        }
    }
    platform_shutdown(&state);

    return 0;
}