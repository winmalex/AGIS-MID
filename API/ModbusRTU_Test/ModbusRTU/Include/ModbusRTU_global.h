#ifndef MODBUSRTU_GLOBAL_H
#define MODBUSRTU_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MODBUSRTU_LIBRARY)
#  define MODBUSRTU_EXPORT Q_DECL_EXPORT
#else
#  define MODBUSRTU_EXPORT Q_DECL_IMPORT
#endif

#endif // MODBUSRTU_GLOBAL_H
