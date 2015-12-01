//
// Generated file, do not edit! Created by opp_msgc 4.4 from veins/modules/application/platooning/messages/UnicastProtocolControlMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "UnicastProtocolControlMessage_m.h"

USING_NAMESPACE

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(UnicastProtocolControlMessage);

UnicastProtocolControlMessage::UnicastProtocolControlMessage(const char *name, int kind) : ::cPacket(name,kind)
{
    this->controlCommand_var = 0;
    this->commandValue_var = 0;
}

UnicastProtocolControlMessage::UnicastProtocolControlMessage(const UnicastProtocolControlMessage& other) : ::cPacket(other)
{
    copy(other);
}

UnicastProtocolControlMessage::~UnicastProtocolControlMessage()
{
}

UnicastProtocolControlMessage& UnicastProtocolControlMessage::operator=(const UnicastProtocolControlMessage& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void UnicastProtocolControlMessage::copy(const UnicastProtocolControlMessage& other)
{
    this->controlCommand_var = other.controlCommand_var;
    this->commandValue_var = other.commandValue_var;
}

void UnicastProtocolControlMessage::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->controlCommand_var);
    doPacking(b,this->commandValue_var);
}

void UnicastProtocolControlMessage::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->controlCommand_var);
    doUnpacking(b,this->commandValue_var);
}

int UnicastProtocolControlMessage::getControlCommand() const
{
    return controlCommand_var;
}

void UnicastProtocolControlMessage::setControlCommand(int controlCommand)
{
    this->controlCommand_var = controlCommand;
}

int UnicastProtocolControlMessage::getCommandValue() const
{
    return commandValue_var;
}

void UnicastProtocolControlMessage::setCommandValue(int commandValue)
{
    this->commandValue_var = commandValue;
}

class UnicastProtocolControlMessageDescriptor : public cClassDescriptor
{
  public:
    UnicastProtocolControlMessageDescriptor();
    virtual ~UnicastProtocolControlMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(UnicastProtocolControlMessageDescriptor);

UnicastProtocolControlMessageDescriptor::UnicastProtocolControlMessageDescriptor() : cClassDescriptor("UnicastProtocolControlMessage", "cPacket")
{
}

UnicastProtocolControlMessageDescriptor::~UnicastProtocolControlMessageDescriptor()
{
}

bool UnicastProtocolControlMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<UnicastProtocolControlMessage *>(obj)!=NULL;
}

const char *UnicastProtocolControlMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int UnicastProtocolControlMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int UnicastProtocolControlMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *UnicastProtocolControlMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "controlCommand",
        "commandValue",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int UnicastProtocolControlMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "controlCommand")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "commandValue")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *UnicastProtocolControlMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *UnicastProtocolControlMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int UnicastProtocolControlMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    UnicastProtocolControlMessage *pp = (UnicastProtocolControlMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UnicastProtocolControlMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    UnicastProtocolControlMessage *pp = (UnicastProtocolControlMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getControlCommand());
        case 1: return long2string(pp->getCommandValue());
        default: return "";
    }
}

bool UnicastProtocolControlMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    UnicastProtocolControlMessage *pp = (UnicastProtocolControlMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setControlCommand(string2long(value)); return true;
        case 1: pp->setCommandValue(string2long(value)); return true;
        default: return false;
    }
}

const char *UnicastProtocolControlMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *UnicastProtocolControlMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    UnicastProtocolControlMessage *pp = (UnicastProtocolControlMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


