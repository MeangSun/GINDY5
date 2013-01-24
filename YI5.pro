TEMPLATE = app
#TEMPLATE = lib
CONFIG += console
CONFIG += qt

QT += xml

SOURCES += main.cpp \
    ../../[A]Source/HDX.cpp

HEADERS += \
    ../../[A]Source/HDX.h

OTHER_FILES += \
    ../../[A]Source/InitD3Dconfig.xml

win32:LIBS += H:/[A][ALPHA]/[A]Centralhall/ADX/Lib/x86/d3d11.lib
win32:LIBS += H:/[A][ALPHA]/[A]Centralhall/ADX/Lib/x86/d3dx11.lib
win32:LIBS += H:/[A][ALPHA]/[A]Centralhall/ADX/Lib/x86/dxerr.lib
win32:LIBS += H:/[A][ALPHA]/[A]Centralhall/ADX/Lib/x86/dxgi.lib


win32:INCLUDEPATH += H:/[A][ALPHA]/[A]Source
win32:INCLUDEPATH += H:/[A][ALPHA]/[A]Centralhall/ADX/Include
