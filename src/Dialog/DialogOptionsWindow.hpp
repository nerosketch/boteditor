//
// Created by ns on 7/31/20.
//

#ifndef BOTEDITOR_DIALOGOPTIONSWINDOW_HPP
#define BOTEDITOR_DIALOGOPTIONSWINDOW_HPP

#include <QtCore/QObject>
#include <QtWidgets/QVBoxLayout>
#include <QDialog>

class DialogOptionsWindow : public QDialog {
Q_OBJECT
public:
    DialogOptionsWindow(QWidget *parent = nullptr);
    virtual ~DialogOptionsWindow() = default;

    QString getInput() const;

signals:
//    void applied();

private:
    QVBoxLayout *_lay;
};


#endif //BOTEDITOR_DIALOGOPTIONSWINDOW_HPP
