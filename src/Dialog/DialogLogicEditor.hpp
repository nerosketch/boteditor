//
// Created by ns on 8/4/20.
//

#ifndef BOTEDITOR_DIALOGLOGICEDITOR_HPP
#define BOTEDITOR_DIALOGLOGICEDITOR_HPP

#include <QtCore/QObject>
#include <QDialog>
#include <nodes/FlowScene>
#include <nodes/FlowView>

using QtNodes::FlowView;
using QtNodes::FlowScene;

class DialogLogicEditor : public QDialog {
Q_OBJECT
public:
    DialogLogicEditor(QWidget *parent);
    virtual ~DialogLogicEditor();

public Q_SLOTS:
    void open() override;

private:
    FlowScene scene;
    FlowView *p_view;
};


#endif //BOTEDITOR_DIALOGLOGICEDITOR_HPP
