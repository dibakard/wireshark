/****************************************************************************
** Meta object code from reading C++ file 'preference_editor_frame.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/preference_editor_frame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'preference_editor_frame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PreferenceEditorFrame_t {
    const uint offsetsAndSize[36];
    char stringdata0[327];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PreferenceEditorFrame_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PreferenceEditorFrame_t qt_meta_stringdata_PreferenceEditorFrame = {
    {
QT_MOC_LITERAL(0, 21), // "PreferenceEditorFrame"
QT_MOC_LITERAL(22, 23), // "showProtocolPreferences"
QT_MOC_LITERAL(46, 0), // ""
QT_MOC_LITERAL(47, 11), // "module_name"
QT_MOC_LITERAL(59, 14), // "editPreference"
QT_MOC_LITERAL(74, 7), // "pref_t*"
QT_MOC_LITERAL(82, 4), // "pref"
QT_MOC_LITERAL(87, 9), // "module_t*"
QT_MOC_LITERAL(97, 6), // "module"
QT_MOC_LITERAL(104, 22), // "uintLineEditTextEdited"
QT_MOC_LITERAL(127, 7), // "new_str"
QT_MOC_LITERAL(135, 24), // "stringLineEditTextEdited"
QT_MOC_LITERAL(160, 23), // "rangeLineEditTextEdited"
QT_MOC_LITERAL(184, 23), // "browsePushButtonClicked"
QT_MOC_LITERAL(208, 38), // "on_modulePreferencesToolButto..."
QT_MOC_LITERAL(247, 35), // "on_preferenceLineEdit_returnP..."
QT_MOC_LITERAL(283, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(305, 21) // "on_buttonBox_rejected"

    },
    "PreferenceEditorFrame\0showProtocolPreferences\0"
    "\0module_name\0editPreference\0pref_t*\0"
    "pref\0module_t*\0module\0uintLineEditTextEdited\0"
    "new_str\0stringLineEditTextEdited\0"
    "rangeLineEditTextEdited\0browsePushButtonClicked\0"
    "on_modulePreferencesToolButton_clicked\0"
    "on_preferenceLineEdit_returnPressed\0"
    "on_buttonBox_accepted\0on_buttonBox_rejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PreferenceEditorFrame[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    2,   89,    2, 0x0a,    3 /* Public */,
       4,    1,   94,    2, 0x2a,    6 /* Public | MethodCloned */,
       4,    0,   97,    2, 0x2a,    8 /* Public | MethodCloned */,
       9,    1,   98,    2, 0x08,    9 /* Private */,
      11,    1,  101,    2, 0x08,   11 /* Private */,
      12,    1,  104,    2, 0x08,   13 /* Private */,
      13,    0,  107,    2, 0x08,   15 /* Private */,
      14,    0,  108,    2, 0x08,   16 /* Private */,
      15,    0,  109,    2, 0x08,   17 /* Private */,
      16,    0,  110,    2, 0x08,   18 /* Private */,
      17,    0,  111,    2, 0x08,   19 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PreferenceEditorFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PreferenceEditorFrame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showProtocolPreferences((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->editPreference((*reinterpret_cast< std::add_pointer_t<pref_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<module_t*>>(_a[2]))); break;
        case 2: _t->editPreference((*reinterpret_cast< std::add_pointer_t<pref_t*>>(_a[1]))); break;
        case 3: _t->editPreference(); break;
        case 4: _t->uintLineEditTextEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->stringLineEditTextEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->rangeLineEditTextEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->browsePushButtonClicked(); break;
        case 8: _t->on_modulePreferencesToolButton_clicked(); break;
        case 9: _t->on_preferenceLineEdit_returnPressed(); break;
        case 10: _t->on_buttonBox_accepted(); break;
        case 11: _t->on_buttonBox_rejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PreferenceEditorFrame::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PreferenceEditorFrame::showProtocolPreferences)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PreferenceEditorFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<AccordionFrame::staticMetaObject>(),
    qt_meta_stringdata_PreferenceEditorFrame.offsetsAndSize,
    qt_meta_data_PreferenceEditorFrame,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PreferenceEditorFrame_t
, QtPrivate::TypeAndForceComplete<PreferenceEditorFrame, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<pref_t *, std::false_type>, QtPrivate::TypeAndForceComplete<module_t *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<pref_t *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PreferenceEditorFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PreferenceEditorFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PreferenceEditorFrame.stringdata0))
        return static_cast<void*>(this);
    return AccordionFrame::qt_metacast(_clname);
}

int PreferenceEditorFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AccordionFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void PreferenceEditorFrame::showProtocolPreferences(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
