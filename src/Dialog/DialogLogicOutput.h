//
// Created by ns on 8/4/20.
//

#ifndef BOTEDITOR_DIALOGLOGICOUTPUT_H
#define BOTEDITOR_DIALOGLOGICOUTPUT_H

#include <QtCore/QObject>
#include <nodes/NodeDataModel>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeDataType;


class DialogLogicOutput : public NodeDataModel {
Q_OBJECT
public:
    DialogLogicOutput();
    virtual ~DialogLogicOutput();

};


#endif //BOTEDITOR_DIALOGLOGICOUTPUT_H
