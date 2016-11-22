#include <QtGui/QGuiApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

#include "credential_qt_utils.h"

QT_BEGIN_NAMESPACE

namespace ui_utils
{

    static inline void SetLabel(QLabel* lab, unsigned int w, unsigned int h, Qt::Alignment align, QColor clr, bool bold, unsigned int size)
    {
        lab->setAlignment(align);
        lab->setFixedSize(w, h);
        lab->setStyleSheet("QLabel{ background:transparent; color:" + clr.name() + "; }");

        QFont font = QGuiApplication::font();
        font.setBold(bold);
        font.setPointSize(size);
        lab->setFont(font);
    }

    void SetBackgroundColor(QWidget * pView, const QColor & color)
    {
        pView->setAutoFillBackground(true);

        QPalette palette;
        palette.setColor(QPalette::Background, color);
        pView->setPalette(palette);
    }

    QLabel* MakeLabel(QWidget* parent, unsigned int w, unsigned int h, Qt::Alignment align, QColor clr, bool bold, unsigned int size)
    {
        QLabel* lab = new QLabel(parent);
        SetLabel(lab, w, h, align, clr, bold, size);

        return lab;
    }

    QLabel * MakeMarkLabel(QWidget * parent, unsigned int w)
    {
        QLabel* lab = new QLabel("*", parent);
        SetLabel(lab, w, def_widget_h, Qt::AlignCenter, Qt::red, false, def_text_size);

        return lab;
    }

    QLabel* MakeStaticLabel(QWidget* parent, unsigned int w, const QColor& clr)
    {
        return MakeLabel(parent, w, def_widget_h, Qt::AlignVCenter | Qt::AlignRight, clr, false, def_text_size);
    }

    QLabel * MakeDynamicLabel(QWidget * parent, const QColor& clr, Qt::Alignment align)
    {
        QLabel* lab = new QLabel(parent);
        lab->setAlignment(align);
        lab->setFixedHeight(def_widget_h);
        lab->setStyleSheet("QLabel{ background:transparent; color:" + clr.name() + "; }");

        QFont font = QGuiApplication::font();
        font.setBold(false);
        font.setPointSize(def_text_size);
        lab->setFont(font);

        return lab;
    }

    QLineEdit * MakeLineEdit(QWidget * parent, unsigned int w, const QColor& clr)
    {
        QLineEdit* line = new QLineEdit(parent);
        line->setFixedSize(w, def_widget_h);
        line->setStyleSheet("QLineEdit{ color:" + clr.name() + "; }");

        QFont font = QGuiApplication::font();
        font.setPointSize(def_text_size);
        line->setFont(font);

        return line;
    }

    QLineEdit * MakePasswordLine(QWidget * parent, unsigned int w)
    {
        QLineEdit* line = new QLineEdit(parent);
        line->setFixedSize(w, def_widget_h);
        line->setEchoMode(QLineEdit::Password);
        line->setContextMenuPolicy(Qt::NoContextMenu);
        line->setStyleSheet("QLineEdit{ lineedit-password-character:42; }");

        QFont font = QGuiApplication::font();
        font.setPointSize(def_text_size);
        line->setFont(font);

        return line;
    }

    QLineEdit * MakeShowLine(QWidget * parent, const QColor & clr)
    {
        QLineEdit* line = new QLineEdit(parent);
        line->setReadOnly(true);
        line->setFixedHeight(def_widget_h);
        line->setStyleSheet("QLineEdit{ border:none; background:transparent; color:" + clr.name() + "; }");

        QFont font = QGuiApplication::font();
        font.setPointSize(def_text_size);
        line->setFont(font);

        return line;
    }

    QPushButton* MakeButton(QWidget* parent, unsigned int w)
    {
        QPushButton* button = new QPushButton(parent);
        button->setFixedSize(w, def_widget_h);
        button->setStyleSheet("QPushButton{ border:none; background-color:#40B040; color:white; }\n"
            "QPushButton:hover{ background-color:#FF4000; color:white; }\n"
            "QPushButton:pressed{ background-color:#4080FF; color:white; }");

        QFont font = QGuiApplication::font();
        font.setPointSize(def_text_size);
        button->setFont(font);

        return button;
    }

    bool ValidateName(const QString & strName)
    {
        if (strName.isEmpty()) return false;

        if (def_text_length < strName.size()) return false;

        for (auto character : strName)
        {
            if ('~' == character) return false;
            if ('!' == character) return false;
            if ('#' == character) return false;
            if ('$' == character) return false;
            if ('%' == character) return false;
            if ('^' == character) return false;
            if ('&' == character) return false;
            if ('*' == character) return false;
            if ('(' == character) return false;
            if (')' == character) return false;
            if ('[' == character) return false;
            if (']' == character) return false;
            if ('{' == character) return false;
            if ('}' == character) return false;
            if ('<' == character) return false;
            if ('>' == character) return false;
            if ('+' == character) return false;
            if ('|' == character) return false;
            if (':' == character) return false;
            if (';' == character) return false;
            if (',' == character) return false;
            if ('?' == character) return false;
            if ('/' == character) return false;
            if ('\\' == character) return false;
            if ('\'' == character) return false;
            if ('\"' == character) return false;
            if ('\n' == character) return false;
            if ('\t' == character) return false;
        }

        return true;
    }
}

QT_END_NAMESPACE
