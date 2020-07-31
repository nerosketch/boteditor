//
// Created by ns on 7/31/20.
//
#include <QtWidgets/QPushButton>
#include "DialogOptionsWindow.hpp"

DialogOptionsWindow::DialogOptionsWindow(QWidget *parent) : QDialog( parent ), _lay(new QVBoxLayout)
{
    auto *_optsBtn = new QPushButton("Настройки");
    auto *_logicBtn = new QPushButton("Поведение");
    auto *_varsBtn = new QPushButton("Варианты");

    _lay->addWidget(_optsBtn);
    _lay->addWidget(_logicBtn);
    _lay->addWidget(_varsBtn);

    setLayout(_lay);
}

QString DialogOptionsWindow::getInput() const
{
    return QString("spdfjpsdf");
}

//void DialogOptionsWindow::applied()
//{
//
//}
