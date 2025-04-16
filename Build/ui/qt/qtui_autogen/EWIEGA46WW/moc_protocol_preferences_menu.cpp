/****************************************************************************
** Meta object code from reading C++ file 'protocol_preferences_menu.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/protocol_preferences_menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protocol_preferences_menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProtocolPreferencesMenu_t {
    const uint offsetsAndSize[32];
    char stringdata0[304];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ProtocolPreferencesMenu_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ProtocolPreferencesMenu_t qt_meta_stringdata_ProtocolPreferencesMenu = {
    {
QT_MOC_LITERAL(0, 23), // "ProtocolPreferencesMenu"
QT_MOC_LITERAL(24, 23), // "showProtocolPreferences"
QT_MOC_LITERAL(48, 0), // ""
QT_MOC_LITERAL(49, 11), // "module_name"
QT_MOC_LITERAL(61, 22), // "editProtocolPreference"
QT_MOC_LITERAL(84, 7), // "pref_t*"
QT_MOC_LITERAL(92, 4), // "pref"
QT_MOC_LITERAL(97, 9), // "module_t*"
QT_MOC_LITERAL(107, 6), // "module"
QT_MOC_LITERAL(114, 24), // "disableProtocolTriggered"
QT_MOC_LITERAL(139, 26), // "modulePreferencesTriggered"
QT_MOC_LITERAL(166, 25), // "editorPreferenceTriggered"
QT_MOC_LITERAL(192, 23), // "boolPreferenceTriggered"
QT_MOC_LITERAL(216, 23), // "enumPreferenceTriggered"
QT_MOC_LITERAL(240, 22), // "uatPreferenceTriggered"
QT_MOC_LITERAL(263, 40) // "enumCustomTCPOverridePreferen..."

    },
    "ProtocolPreferencesMenu\0showProtocolPreferences\0"
    "\0module_name\0editProtocolPreference\0"
    "pref_t*\0pref\0module_t*\0module\0"
    "disableProtocolTriggered\0"
    "modulePreferencesTriggered\0"
    "editorPreferenceTriggered\0"
    "boolPreferenceTriggered\0enumPreferenceTriggered\0"
    "uatPreferenceTriggered\0"
    "enumCustomTCPOverridePreferenceTriggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProtocolPreferencesMenu[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,
       4,    2,   71,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   76,    2, 0x08,    6 /* Private */,
      10,    0,   77,    2, 0x08,    7 /* Private */,
      11,    0,   78,    2, 0x08,    8 /* Private */,
      12,    0,   79,    2, 0x08,    9 /* Private */,
      13,    0,   80,    2, 0x08,   10 /* Private */,
      14,    0,   81,    2, 0x08,   11 /* Private */,
      15,    0,   82,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ProtocolPreferencesMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProtocolPreferencesMenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showProtocolPreferences((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->editProtocolPreference((*reinterpret_cast< std::add_pointer_t<pref_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<module_t*>>(_a[2]))); break;
        case 2: _t->disableProtocolTriggered(); break;
        case 3: _t->modulePreferencesTriggered(); break;
        case 4: _t->editorPreferenceTriggered(); break;
        case 5: _t->boolPreferenceTriggered(); break;
        case 6: _t->enumPreferenceTriggered(); break;
        case 7: _t->uatPreferenceTriggered(); break;
        case 8: _t->enumCustomTCPOverridePreferenceTriggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProtocolPreferencesMenu::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolPreferencesMenu::showProtocolPreferences)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProtocolPreferencesMenu::*)(pref_t * , module_t * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolPreferencesMenu::editProtocolPreference)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ProtocolPreferencesMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QMenu::staticMetaObject>(),
    qt_meta_stringdata_ProtocolPreferencesMenu.offsetsAndSize,
    qt_meta_data_ProtocolPreferencesMenu,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ProtocolPreferencesMenu_t
, QtPrivate::TypeAndForceComplete<ProtocolPreferencesMenu, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<pref_t *, std::false_type>, QtPrivate::TypeAndForceComplete<module_t *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ProtocolPreferencesMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProtocolPreferencesMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProtocolPreferencesMenu.stringdata0))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int ProtocolPreferencesMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ProtocolPreferencesMenu::showProtocolPreferences(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProtocolPreferencesMenu::editProtocolPreference(pref_t * _t1, module_t * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
