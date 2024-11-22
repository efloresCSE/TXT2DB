TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    parser.cpp \
    random.cpp \
    record.cpp \
    sql.cpp \
    state_machine.cpp \
    stokenizer.cpp \
    table.cpp \
    token.cpp \
    ftokenizer.cpp

HEADERS += \
    arrayfunctions.h \
    bplustree.h \
    error.h \
    file_functions.h \
    map.h \
    mmap.h \
    mpair.h \
    mylib.h \
    pair.h \
    parser.h \
    random.h \
    record.h \
    sql.h \
    state_machine.h \
    stokenizer.h \
    table.h \
    test_functions.h \
    token.h \
    output.h \
    work_report.h \
    ftokenizer.h \
    mmap_output.h
