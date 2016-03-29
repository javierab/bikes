//
// Generated file, do not edit! Created by nedtool 4.6 from veins/modules/application/platooning/messages/BikesMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "BikesMessage_m.h"

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

Register_Class(BikesMessage);

BikesMessage::BikesMessage(const char *name, int kind) : ::cPacket(name,kind)
{
    this->vehicleType_var = 0;
    this->vehicleId_var = 0;
    this->platoonId_var = 0;
    this->messageType_var = 0;
    this->platoonSpeed_var = 0;
    this->platoonLane_var = 0;
    this->frontVehicleId_var = 0;
    this->followerVehicleId_var = 0;
    platoonFormation_arraysize = 0;
    this->platoonFormation_var = 0;
}

BikesMessage::BikesMessage(const BikesMessage& other) : ::cPacket(other)
{
    platoonFormation_arraysize = 0;
    this->platoonFormation_var = 0;
    copy(other);
}

BikesMessage::~BikesMessage()
{
    delete [] platoonFormation_var;
}

BikesMessage& BikesMessage::operator=(const BikesMessage& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void BikesMessage::copy(const BikesMessage& other)
{
    this->vehicleType_var = other.vehicleType_var;
    this->vehicleId_var = other.vehicleId_var;
    this->platoonId_var = other.platoonId_var;
    this->messageType_var = other.messageType_var;
    this->platoonSpeed_var = other.platoonSpeed_var;
    this->platoonLane_var = other.platoonLane_var;
    this->frontVehicleId_var = other.frontVehicleId_var;
    this->followerVehicleId_var = other.followerVehicleId_var;
    delete [] this->platoonFormation_var;
    this->platoonFormation_var = (other.platoonFormation_arraysize==0) ? NULL : new int[other.platoonFormation_arraysize];
    platoonFormation_arraysize = other.platoonFormation_arraysize;
    for (unsigned int i=0; i<platoonFormation_arraysize; i++)
        this->platoonFormation_var[i] = other.platoonFormation_var[i];
}

void BikesMessage::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->vehicleType_var);
    doPacking(b,this->vehicleId_var);
    doPacking(b,this->platoonId_var);
    doPacking(b,this->messageType_var);
    doPacking(b,this->platoonSpeed_var);
    doPacking(b,this->platoonLane_var);
    doPacking(b,this->frontVehicleId_var);
    doPacking(b,this->followerVehicleId_var);
    b->pack(platoonFormation_arraysize);
    doPacking(b,this->platoonFormation_var,platoonFormation_arraysize);
}

void BikesMessage::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->vehicleType_var);
    doUnpacking(b,this->vehicleId_var);
    doUnpacking(b,this->platoonId_var);
    doUnpacking(b,this->messageType_var);
    doUnpacking(b,this->platoonSpeed_var);
    doUnpacking(b,this->platoonLane_var);
    doUnpacking(b,this->frontVehicleId_var);
    doUnpacking(b,this->followerVehicleId_var);
    delete [] this->platoonFormation_var;
    b->unpack(platoonFormation_arraysize);
    if (platoonFormation_arraysize==0) {
        this->platoonFormation_var = 0;
    } else {
        this->platoonFormation_var = new int[platoonFormation_arraysize];
        doUnpacking(b,this->platoonFormation_var,platoonFormation_arraysize);
    }
}

int BikesMessage::getVehicleType() const
{
    return vehicleType_var;
}

void BikesMessage::setVehicleType(int vehicleType)
{
    this->vehicleType_var = vehicleType;
}

int BikesMessage::getVehicleId() const
{
    return vehicleId_var;
}

void BikesMessage::setVehicleId(int vehicleId)
{
    this->vehicleId_var = vehicleId;
}

int BikesMessage::getPlatoonId() const
{
    return platoonId_var;
}

void BikesMessage::setPlatoonId(int platoonId)
{
    this->platoonId_var = platoonId;
}

int BikesMessage::getMessageType() const
{
    return messageType_var;
}

void BikesMessage::setMessageType(int messageType)
{
    this->messageType_var = messageType;
}

double BikesMessage::getPlatoonSpeed() const
{
    return platoonSpeed_var;
}

void BikesMessage::setPlatoonSpeed(double platoonSpeed)
{
    this->platoonSpeed_var = platoonSpeed;
}

int BikesMessage::getPlatoonLane() const
{
    return platoonLane_var;
}

void BikesMessage::setPlatoonLane(int platoonLane)
{
    this->platoonLane_var = platoonLane;
}

int BikesMessage::getFrontVehicleId() const
{
    return frontVehicleId_var;
}

void BikesMessage::setFrontVehicleId(int frontVehicleId)
{
    this->frontVehicleId_var = frontVehicleId;
}

int BikesMessage::getFollowerVehicleId() const
{
    return followerVehicleId_var;
}

void BikesMessage::setFollowerVehicleId(int followerVehicleId)
{
    this->followerVehicleId_var = followerVehicleId;
}

void BikesMessage::setPlatoonFormationArraySize(unsigned int size)
{
    int *platoonFormation_var2 = (size==0) ? NULL : new int[size];
    unsigned int sz = platoonFormation_arraysize < size ? platoonFormation_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        platoonFormation_var2[i] = this->platoonFormation_var[i];
    for (unsigned int i=sz; i<size; i++)
        platoonFormation_var2[i] = 0;
    platoonFormation_arraysize = size;
    delete [] this->platoonFormation_var;
    this->platoonFormation_var = platoonFormation_var2;
}

unsigned int BikesMessage::getPlatoonFormationArraySize() const
{
    return platoonFormation_arraysize;
}

int BikesMessage::getPlatoonFormation(unsigned int k) const
{
    if (k>=platoonFormation_arraysize) throw cRuntimeError("Array of size %d indexed by %d", platoonFormation_arraysize, k);
    return platoonFormation_var[k];
}

void BikesMessage::setPlatoonFormation(unsigned int k, int platoonFormation)
{
    if (k>=platoonFormation_arraysize) throw cRuntimeError("Array of size %d indexed by %d", platoonFormation_arraysize, k);
    this->platoonFormation_var[k] = platoonFormation;
}

class BikesMessageDescriptor : public cClassDescriptor
{
  public:
    BikesMessageDescriptor();
    virtual ~BikesMessageDescriptor();

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

Register_ClassDescriptor(BikesMessageDescriptor);

BikesMessageDescriptor::BikesMessageDescriptor() : cClassDescriptor("BikesMessage", "cPacket")
{
}

BikesMessageDescriptor::~BikesMessageDescriptor()
{
}

bool BikesMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BikesMessage *>(obj)!=NULL;
}

const char *BikesMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BikesMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount(object) : 9;
}

unsigned int BikesMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *BikesMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "vehicleType",
        "vehicleId",
        "platoonId",
        "messageType",
        "platoonSpeed",
        "platoonLane",
        "frontVehicleId",
        "followerVehicleId",
        "platoonFormation",
    };
    return (field>=0 && field<9) ? fieldNames[field] : NULL;
}

int BikesMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "vehicleType")==0) return base+0;
    if (fieldName[0]=='v' && strcmp(fieldName, "vehicleId")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "platoonId")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageType")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "platoonSpeed")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "platoonLane")==0) return base+5;
    if (fieldName[0]=='f' && strcmp(fieldName, "frontVehicleId")==0) return base+6;
    if (fieldName[0]=='f' && strcmp(fieldName, "followerVehicleId")==0) return base+7;
    if (fieldName[0]=='p' && strcmp(fieldName, "platoonFormation")==0) return base+8;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BikesMessageDescriptor::getFieldTypeString(void *object, int field) const
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
        "double",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : NULL;
}

const char *BikesMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BikesMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BikesMessage *pp = (BikesMessage *)object; (void)pp;
    switch (field) {
        case 8: return pp->getPlatoonFormationArraySize();
        default: return 0;
    }
}

std::string BikesMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BikesMessage *pp = (BikesMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getVehicleType());
        case 1: return long2string(pp->getVehicleId());
        case 2: return long2string(pp->getPlatoonId());
        case 3: return long2string(pp->getMessageType());
        case 4: return double2string(pp->getPlatoonSpeed());
        case 5: return long2string(pp->getPlatoonLane());
        case 6: return long2string(pp->getFrontVehicleId());
        case 7: return long2string(pp->getFollowerVehicleId());
        case 8: return long2string(pp->getPlatoonFormation(i));
        default: return "";
    }
}

bool BikesMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BikesMessage *pp = (BikesMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setVehicleType(string2long(value)); return true;
        case 1: pp->setVehicleId(string2long(value)); return true;
        case 2: pp->setPlatoonId(string2long(value)); return true;
        case 3: pp->setMessageType(string2long(value)); return true;
        case 4: pp->setPlatoonSpeed(string2double(value)); return true;
        case 5: pp->setPlatoonLane(string2long(value)); return true;
        case 6: pp->setFrontVehicleId(string2long(value)); return true;
        case 7: pp->setFollowerVehicleId(string2long(value)); return true;
        case 8: pp->setPlatoonFormation(i,string2long(value)); return true;
        default: return false;
    }
}

const char *BikesMessageDescriptor::getFieldStructName(void *object, int field) const
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

void *BikesMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BikesMessage *pp = (BikesMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


