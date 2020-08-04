//
// Created by ns on 8/4/20.
//

#ifndef BOTEDITOR_DIALOGLOGICFIELD_H
#define BOTEDITOR_DIALOGLOGICFIELD_H

#include <QtCore/QObject>
#include <nodes/NodeDataModel>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;

class DialogLogicField : public NodeDataModel {
Q_OBJECT
public:
    DialogLogicField();
    virtual ~DialogLogicField();

    QString caption() const override
    {
        return QString("Поле учётной записи");
    }

    static QString
    Name()
    { return QString("My test text data source"); }

    QString
    name() const override
    { return TextSourceDataModel::Name(); }

};


#endif //BOTEDITOR_DIALOGLOGICFIELD_H
