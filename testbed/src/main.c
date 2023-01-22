#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
    EPHFATAL("A test message: %f", 3.14f);
    EPHERROR("A test message: %f", 3.14f);
    EPHWARN("A test message: %f", 3.14f);
    EPHINFO("A test message: %f", 3.14f);
    EPHDEBUG("A test message: %f", 3.14f);
    EPHTRACE("A test message: %f", 3.14f);

    EPHASSERT(1 == 0);
    return 0;
}