//
// Created by ns on 8/2/20.
//

//#include <iostream>
#include <QInputDialog>
#include "DialogVariantsWindow.hpp"


DialogVariantsWindow::DialogVariantsWindow(QWidget *parent) : QDialog(parent), _lay(new QVBoxLayout(this)), _list(new QListWidget), _delBtn(new QPushButton("Удалить"))
{
    auto *_optsBtn = new QPushButton("Добавить вариант");
    _optsBtn->setBackgroundRole(QPalette::ColorRole::Link);
    connect(_optsBtn, &QPushButton::clicked, this, &DialogVariantsWindow::onAddVarClick);

    _delBtn->setEnabled(false);
    connect(_delBtn, &QPushButton::clicked, this, &DialogVariantsWindow::onDelVarClick);

    connect(_list, &QListWidget::itemSelectionChanged, this, &DialogVariantsWindow::onListSelectChanged);

//    auto *_litem1 = new QListWidgetItem(tr("Oak"), _list);

    _lay->addWidget(_optsBtn);
    _lay->addWidget(_list);
    _lay->addWidget(_delBtn);

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
