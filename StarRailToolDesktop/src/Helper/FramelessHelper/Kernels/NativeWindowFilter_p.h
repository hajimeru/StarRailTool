#ifndef NATIVEWINDOWFILTER_P_H
#define NATIVEWINDOWFILTER_P_H

#include <QtCore/QHash>
#include <QtGui/QWindow>

#include "NativeWindowFilter.h"

class NativeWindowFilterPrivate
{
public:
    static QScopedPointer<NativeWindowFilter> instance;

    static QHash<NativeWindowHelper *, WId> windows;
    static QHash<QWindow *, WId> winIds;
    static QHash<WId, NativeWindowHelper *> helpers;
};

#endif // NATIVEWINDOWFILTER_P_H
