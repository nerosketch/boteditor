//
// Created by ns on 8/2/20.
//

//#include <iostream>
#include <QInputDialog>
#include <QtWidgets/QHBoxLayout>
#include "DialogVariantsWindow.hpp"


DialogVariantsWindow::DialogVariantsWindow(QWidget *parent) : QDialog(parent),
_lay(new QVBoxLayout(this)),
_list(new QListWidget),
_delBtn(new QPushButton(tr("Удалить"))),
_okBtn(new QPushButton(tr("Ok")))
{
    auto *_optsBtn = new QPushButton("Добавить вариант");
    _optsBtn->setBackgroundRole(QPalette::ColorRole::Link);
    connect(_optsBtn, &QPushButton::clicked, this, &DialogVariantsWindow::onAddVarClick);

    _delBtn->setEnabled(false);
    connect(_delBtn, &QPushButton::clicked, this, &DialogVariantsWindow::onDelVarClick);

    connect(_list, &QListWidget::itemSelectionChanged, this, &DialogVariantsWindow::onListSelectChanged);

    connect(_okBtn, &QPushButton::clicked, this, &DialogVariantsWindow::_onOkSignalClicked);

//    auto *_litem1 = new QListWidgetItem(tr("Oak"), _list);

    _lay->addWidget(_optsBtn);
    _lay->addWidget(_list);

    auto _qhlay_widget = new QWidget;
    auto _hlay = new QHBoxLayout;
    _hlay->addWidget(_okBtn);
    _hlay->addWidget(_delBtn);
    _qhlay_widget->setLayout(_hlay);

    _lay->addWidget(_qhlay_widget);

    setLayout(_lay);
}

DialogVariantsWindow::~DialogVariantsWindow() = default;

void DialogVariantsWindow::onAddVarClick()
{
    bool ok;
    QString newVariantTitle = QInputDialog::getText(this, tr("Добавить вариант"), tr("Название варианта"), QLineEdit::Normal, tr("Новый вариант"), &ok);

    if (ok && !newVariantTitle.isEmpty())
    {
        addVariant(newVariantTitle);
    }
}

void DialogVariantsWindow::onDelVarClick()
{
    auto selected = _list->selectedItems();
    for (auto it : selected)
    {
        delete it;
    }
}

void DialogVariantsWindow::addVariant(const QString& title)
{
    auto *_litem = new QListWidgetItem(title);
    _list->addItem(_litem);
}

void DialogVariantsWindow::onListSelectChanged()
{
    auto selected = _list->selectedItems();
    _delBtn->setEnabled(!selected.empty());
}

void DialogVariantsWindow::_onOkSignalClicked()
{
    QStringList vars;
    for (int i=0; i < _list->count(); i++)
    {
        vars.append(_list->item(i)->text());
    }
    emit onOkSignal(vars);
    accept();
}
