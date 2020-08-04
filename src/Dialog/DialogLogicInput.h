//
// Created by ns on 8/4/20.
//

#ifndef BOTEDITOR_DIALOGLOGICINPUT_H
#define BOTEDITOR_DIALOGLOGICINPUT_H

#include <QtCore/QObject>
#include <nodes/NodeDataModel>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeDataType;

class DialogLogicInput : public NodeDataModel {
Q_OBJECT
public:
    DialogLogicInput();
    virtual ~DialogLogicInput();

};


#endif //BOTEDITOR_DIALOGLOGICINPUT_H
