
TEMPLATE = lib
LANGUAGE = C++
QT += widgets
QT += network
DEFINES -= UNICODE
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += debug_and_release warn_on

win32{
	QMAKE_CXXFLAGS += /MP /utf-8
}

QMAKE_CXXFLAGS_RELEASE += $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
QMAKE_LFLAGS_RELEASE   += $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO

CONFIG(debug,debug|release){
    TARGET = ClientUtilityd
    DESTDIR_LIB = ../build/debug
    DESTDIR = ../debug/
    TEMP_DESTDIR = ../build/intermediate/debug/$$TARGET
}
CONFIG(release,debug|release){
    TARGET = ClientUtility
    DESTDIR_LIB = ../build/release
    DESTDIR = ../release/
    TEMP_DESTDIR = ../build/intermediate/release/$$TARGET
}

MOC_DIR         = $$TEMP_DESTDIR/moc
RCC_DIR         = $$TEMP_DESTDIR/rcc
UI_DIR          = $$TEMP_DESTDIR/qui
OBJECTS_DIR     = $$TEMP_DESTDIR/obj

INCLUDEPATH  +=  \
        /gui
		$$TEMP_DESTDIR/qui

HEADERS +=  ClientUtility.h \
            clientutility_global.h \
            gui/FramelessDialog.h \
            gui/FramelessWindow.h

SOURCES += ClientUtility.cpp \
           gui/FramelessDialog.cpp \
           gui/FramelessWindow.cpp
