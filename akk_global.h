#ifndef AKK_GLOBAL_H
#define AKK_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(AKK_LIBRARY)
#  define AKKSHARED_EXPORT Q_DECL_EXPORT
#else
#  define AKKSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // AKK_GLOBAL_H
