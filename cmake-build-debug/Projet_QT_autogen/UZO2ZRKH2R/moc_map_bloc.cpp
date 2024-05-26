/****************************************************************************
** Meta object code from reading C++ file 'map_bloc.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Map/map_bloc.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'map_bloc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_bloc_herbe_t {
    uint offsetsAndSizes[2];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_bloc_herbe_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_bloc_herbe_t qt_meta_stringdata_bloc_herbe = {
    {
        QT_MOC_LITERAL(0, 10)   // "bloc_herbe"
    },
    "bloc_herbe"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_bloc_herbe[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject bloc_herbe::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_bloc_herbe.offsetsAndSizes,
    qt_meta_data_bloc_herbe,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_bloc_herbe_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<bloc_herbe, std::true_type>
    >,
    nullptr
} };

void bloc_herbe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *bloc_herbe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bloc_herbe::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_bloc_herbe.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int bloc_herbe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_stringdata_bloc_pierre_t {
    uint offsetsAndSizes[10];
    char stringdata0[12];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_bloc_pierre_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_bloc_pierre_t qt_meta_stringdata_bloc_pierre = {
    {
        QT_MOC_LITERAL(0, 11),  // "bloc_pierre"
        QT_MOC_LITERAL(12, 7),  // "clicked"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 12),  // "bloc_pierre*"
        QT_MOC_LITERAL(34, 4)   // "bloc"
    },
    "bloc_pierre",
    "clicked",
    "",
    "bloc_pierre*",
    "bloc"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_bloc_pierre[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject bloc_pierre::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_bloc_pierre.offsetsAndSizes,
    qt_meta_data_bloc_pierre,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_bloc_pierre_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<bloc_pierre, std::true_type>,
        // method 'clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bloc_pierre *, std::false_type>
    >,
    nullptr
} };

void bloc_pierre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<bloc_pierre *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< std::add_pointer_t<bloc_pierre*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< bloc_pierre* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (bloc_pierre::*)(bloc_pierre * );
            if (_t _q_method = &bloc_pierre::clicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *bloc_pierre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bloc_pierre::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_bloc_pierre.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int bloc_pierre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void bloc_pierre::clicked(bloc_pierre * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {
struct qt_meta_stringdata_bloc_chemin_t {
    uint offsetsAndSizes[2];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_bloc_chemin_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_bloc_chemin_t qt_meta_stringdata_bloc_chemin = {
    {
        QT_MOC_LITERAL(0, 11)   // "bloc_chemin"
    },
    "bloc_chemin"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_bloc_chemin[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject bloc_chemin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_bloc_chemin.offsetsAndSizes,
    qt_meta_data_bloc_chemin,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_bloc_chemin_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<bloc_chemin, std::true_type>
    >,
    nullptr
} };

void bloc_chemin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *bloc_chemin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bloc_chemin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_bloc_chemin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int bloc_chemin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_stringdata_chateau_t {
    uint offsetsAndSizes[6];
    char stringdata0[8];
    char stringdata1[15];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_chateau_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_chateau_t qt_meta_stringdata_chateau = {
    {
        QT_MOC_LITERAL(0, 7),  // "chateau"
        QT_MOC_LITERAL(8, 14),  // "chateauDetruit"
        QT_MOC_LITERAL(23, 0)   // ""
    },
    "chateau",
    "chateauDetruit",
    ""
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_chateau[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject chateau::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_chateau.offsetsAndSizes,
    qt_meta_data_chateau,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_chateau_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<chateau, std::true_type>,
        // method 'chateauDetruit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void chateau::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<chateau *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->chateauDetruit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (chateau::*)();
            if (_t _q_method = &chateau::chateauDetruit; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *chateau::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chateau::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_chateau.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int chateau::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void chateau::chateauDetruit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {
struct qt_meta_stringdata_map_bloc_t {
    uint offsetsAndSizes[16];
    char stringdata0[9];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[13];
    char stringdata5[5];
    char stringdata6[21];
    char stringdata7[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_map_bloc_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_map_bloc_t qt_meta_stringdata_map_bloc = {
    {
        QT_MOC_LITERAL(0, 8),  // "map_bloc"
        QT_MOC_LITERAL(9, 11),  // "abandonGame"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 9),  // "new_tower"
        QT_MOC_LITERAL(32, 12),  // "bloc_pierre*"
        QT_MOC_LITERAL(45, 4),  // "bloc"
        QT_MOC_LITERAL(50, 20),  // "handleChateauDetruit"
        QT_MOC_LITERAL(71, 15)   // "updateCountdown"
    },
    "map_bloc",
    "abandonGame",
    "",
    "new_tower",
    "bloc_pierre*",
    "bloc",
    "handleChateauDetruit",
    "updateCountdown"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_map_bloc[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   39,    2, 0x0a,    2 /* Public */,
       6,    0,   42,    2, 0x0a,    4 /* Public */,
       7,    0,   43,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject map_bloc::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_map_bloc.offsetsAndSizes,
    qt_meta_data_map_bloc,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_map_bloc_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<map_bloc, std::true_type>,
        // method 'abandonGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'new_tower'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bloc_pierre *, std::false_type>,
        // method 'handleChateauDetruit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateCountdown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void map_bloc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<map_bloc *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->abandonGame(); break;
        case 1: _t->new_tower((*reinterpret_cast< std::add_pointer_t<bloc_pierre*>>(_a[1]))); break;
        case 2: _t->handleChateauDetruit(); break;
        case 3: _t->updateCountdown(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< bloc_pierre* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (map_bloc::*)();
            if (_t _q_method = &map_bloc::abandonGame; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *map_bloc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *map_bloc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_map_bloc.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int map_bloc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void map_bloc::abandonGame()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
