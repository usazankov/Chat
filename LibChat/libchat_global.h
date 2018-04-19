#ifndef LIBCHAT_GLOBAL_H
#define LIBCHAT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBCHAT_LIBRARY)
#  define LIBCHATSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBCHATSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBCHAT_GLOBAL_H
