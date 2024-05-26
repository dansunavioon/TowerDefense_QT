/****************************************************************************
** Meta object code from reading C++ file 'MyScene.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MyScene.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyScene.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_Menu_t {
    uint offsetsAndSizes[14];
    char stringdata0[5];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[10];
    char stringdata5[19];
    char stringdata6[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Menu_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Menu_t qt_meta_stringdata_Menu = {
    {
        QT_MOC_LITERAL(0, 4),  // "Menu"
        QT_MOC_LITERAL(5, 17),  // "start_game_signal"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 6),  // "pseudo"
        QT_MOC_LITERAL(31, 9),  // "askPseudo"
        QT_MOC_LITERAL(41, 18),  // "afficherClassement"
        QT_MOC_LITERAL(60, 18)   // "showVolumeSettings"
    },
    "Menu",
    "start_game_signal",
    "",
    "pseudo",
    "askPseudo",
    "afficherClassement",
    "showVolumeSettings"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Menu[] = {

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
       1,    1,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   41,    2, 0x08,    3 /* Private */,
       5,    0,   42,    2, 0x08,    4 /* Private */,
       6,    0,   43,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Menu::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_Menu.offsetsAndSizes,
    qt_meta_data_Menu,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Menu_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Menu, std::true_type>,
        // method 'start_game_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'askPseudo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherClassement'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showVolumeSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Menu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->start_game_signal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->askPseudo(); break;
        case 2: _t->afficherClassement(); break;
        case 3: _t->showVolumeSettings(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Menu::*)(QString );
            if (_t _q_method = &Menu::start_game_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Menu.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Menu::start_game_signal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
