//
// Generated file, do not edit! Created by nedtool 4.6 from veins/modules/application/platooning/messages/UnicastMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "UnicastMessage_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("UnicastMessageType");
    if (!e) enums.getInstance()->add(e = new cEnum("UnicastMessageType"));
    e->insert(DATA, "DATA");
    e->insert(ACK, "ACK");
);

Register_Class(UnicastMessage);

UnicastMessage::UnicastMessage(const char *name, int kind) : ::cPacket(name,kind)
{
    this->destination_var = 0;
    this->source_var = 0;
    this->sequenceNumber_var = 0;
    this->type_var = 0;
    this->priority_var = 0;
    this->recvPower_dBm_var = 0;
    this->channel_var = 0;
}

UnicastMessage::UnicastMessage(const UnicastMessage& other) : ::cPacket(other)
{
    copy(other);
}

UnicastMessage::~UnicastMessage()
{
}

UnicastMessage& UnicastMessage::operator=(const UnicastMessage& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void UnicastMessage::copy(const UnicastMessage& other)
{
    this->destination_var = other.destination_var;
    this->source_var = other.source_var;
    this->sequenceNumber_var = other.sequenceNumber_var;
    this->type_var = other.type_var;
    this->priority_var = other.priority_var;
    this->recvPower_dBm_var = other.recvPower_dBm_var;
    this->channel_var = other.channel_var;
}

void UnicastMessage::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->destination_var);
    doPacking(b,this->source_var);
    doPacking(b,this->sequenceNumber_var);
    doPacking(b,this->type_var);
    doPacking(b,this->priority_var);
    doPacking(b,this->recvPower_dBm_var);
    doPacking(b,this->channel_var);
}

void UnicastMessage::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->destination_var);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->sequenceNumber_var);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->priority_var);
    doUnpacking(b,this->recvPower_dBm_var);
    doUnpacking(b,this->channel_var);
}

int UnicastMessage::getDestination() const
{
    return destination_var;
}

void UnicastMessage::setDestination(int destination)
{
    this->destination_var = destination;
}

int UnicastMessage::getSource() const
{
    return source_var;
}

void UnicastMessage::setSource(int source)
{
    this->source_var = source;
}

int UnicastMessage::getSequenceNumber() const
{
    return sequenceNumber_var;
}

void UnicastMessage::setSequenceNumber(int sequenceNumber)
{
    this->sequenceNumber_var = sequenceNumber;
}

int UnicastMessage::getType() const
{
    return type_var;
}

void UnicastMessage::setType(int type)
{
    this->type_var = type;
}

int UnicastMessage::getPriority() const
{
    return priority_var;
}

void UnicastMessage::setPriority(int priority)
{
    this->priority_var = priority;
}

double UnicastMessage::getRecvPower_dBm() const
{
    return recvPower_dBm_var;
}

void UnicastMessage::setRecvPower_dBm(double recvPower_dBm)
{
    this->recvPower_dBm_var = recvPower_dBm;
}

int UnicastMessage::getChannel() const
{
    return channel_var;
}

void UnicastMessage::setChannel(int channel)
{
    this->channel_var = channel;
}

class UnicastMessageDescriptor : public cClassDescriptor
{
  public:
    UnicastMessageDescriptor();
    virtual ~UnicastMessageDescriptor();

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

Register_ClassDescriptor(UnicastMessageDescriptor);

UnicastMessageDescriptor::UnicastMessageDescriptor() : cClassDescriptor("UnicastMessage", "cPacket")
{
}

UnicastMessageDescriptor::~UnicastMessageDescriptor()
{
}

bool UnicastMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<UnicastMessage *>(obj)!=NULL;
}

const char *UnicastMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int UnicastMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int UnicastMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *UnicastMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "destination",
        "source",
        "sequenceNumber",
        "type",
        "priority",
        "recvPower_dBm",
        "channel",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int UnicastMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destination")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumber")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "priority")==0) return base+4;
    if (fieldName[0]=='r' && strcmp(fieldName, "recvPower_dBm")==0) return base+5;
    if (fieldName[0]=='c' && strcmp(fieldName, "channel")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *UnicastMessageDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
        "int",
        "int",
        "double",
        "int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *UnicastMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 3:
            if (!strcmp(propertyname,"enum")) return "UnicastMessageType";
            return NULL;
        default: return NULL;
    }
}

int UnicastMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    UnicastMessage *pp = (UnicastMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UnicastMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    UnicastMessage *pp = (UnicastMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getDestination());
        case 1: return long2string(pp->getSource());
        case 2: return long2string(pp->getSequenceNumber());
        case 3: return long2string(pp->getType());
        case 4: return long2string(pp->getPriority());
        case 5: return double2string(pp->getRecvPower_dBm());
        case 6: return long2string(pp->getChannel());
        default: return "";
    }
}

bool UnicastMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    UnicastMessage *pp = (UnicastMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setDestination(string2long(value)); return true;
        case 1: pp->setSource(string2long(value)); return true;
        case 2: pp->setSequenceNumber(string2long(value)); return true;
        case 3: pp->setType(string2long(value)); return true;
        case 4: pp->setPriority(string2long(value)); return true;
        case 5: pp->setRecvPower_dBm(string2double(value)); return true;
        case 6: pp->setChannel(string2long(value)); return true;
        default: return false;
    }
}

const char *UnicastMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *UnicastMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    UnicastMessage *pp = (UnicastMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


