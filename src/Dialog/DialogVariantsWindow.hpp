//
// Created by ns on 8/2/20.
//

#ifndef BOTEDITOR_DIALOGVARIANTSWINDOW_HPP
#define BOTEDITOR_DIALOGVARIANTSWINDOW_HPP

#include <QtCore/QObject>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QDialog>


class DialogVariantsWindow : public QDialog {
Q_OBJECT
public:
    DialogVariantsWindow(QWidget *parent = nullptr);
    virtual ~DialogVariantsWindow();

    void addVariant(const QString& title);

private Q_SLOTS:
    void onAddVarClick();
    void onDelVarClick();
    void onListSelectChanged();

private:
    QVBoxLayout *_lay;
    QListWidget *_list;
    QPushButton *_delBtn;
};


#endif //BOTEDITOR_DIALOGVARIANTSWINDOW_HPP
