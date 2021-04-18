#include "platform.hpp"
// https://marcelbraghetto.github.io/a-simple-triangle/2019/03/09/part-04/

ast::Platform ast::getCurrentPlatform()
{
#if defined(__APPLE__)
#include "TargetConditionals.h"
#if TARGET_OS_IPHONE
    return ast::Platform::ios;
#else
    return ast::Platform::mac;
#endif
#endif
}