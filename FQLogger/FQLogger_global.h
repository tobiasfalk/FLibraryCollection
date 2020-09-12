#ifndef FQLOGGER_GLOBAL_H
#define FQLOGGER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FQLOGGER_LIBRARY)
#  define FQLOGGER_EXPORT Q_DECL_EXPORT
#else
#  define FQLOGGER_EXPORT Q_DECL_IMPORT
#endif

#endif // FQLOGGER_GLOBAL_H
