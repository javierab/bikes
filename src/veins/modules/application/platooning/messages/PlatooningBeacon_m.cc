//
// Generated file, do not edit! Created by nedtool 4.6 from veins/modules/application/platooning/messages/PlatooningBeacon.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PlatooningBeacon_m.h"

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

Register_Class(PlatooningBeacon);

PlatooningBeacon::PlatooningBeacon(const char *name, int kind) : ::cPacket(name,kind)
{
    this->vehicleId_var = 0;
    this->relayerId_var = 0;
    this->acceleration_var = 0;
    this->speed_var = 0;
    this->positionX_var = 0;
    this->positionY_var = 0;
    this->time_var = 0;
    this->sequenceNumber_var = 0;
}

PlatooningBeacon::PlatooningBeacon(const PlatooningBeacon& other) : ::cPacket(other)
{
    copy(other);
}

PlatooningBeacon::~PlatooningBeacon()
{
}

PlatooningBeacon& PlatooningBeacon::operator=(const PlatooningBeacon& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void PlatooningBeacon::copy(const PlatooningBeacon& other)
{
    this->vehicleId_var = other.vehicleId_var;
    this->relayerId_var = other.relayerId_var;
    this->acceleration_var = other.acceleration_var;
    this->speed_var = other.speed_var;
    this->positionX_var = other.positionX_var;
    this->positionY_var = other.positionY_var;
    this->time_var = other.time_var;
    this->sequenceNumber_var = other.sequenceNumber_var;
}

void PlatooningBeacon::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->vehicleId_var);
    doPacking(b,this->relayerId_var);
    doPacking(b,this->acceleration_var);
    doPacking(b,this->speed_var);
    doPacking(b,this->positionX_var);
    doPacking(b,this->positionY_var);
    doPacking(b,this->time_var);
    doPacking(b,this->sequenceNumber_var);
}

void PlatooningBeacon::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->vehicleId_var);
    doUnpacking(b,this->relayerId_var);
    doUnpacking(b,this->acceleration_var);
    doUnpacking(b,this->speed_var);
    doUnpacking(b,this->positionX_var);
    doUnpacking(b,this->positionY_var);
    doUnpacking(b,this->time_var);
    doUnpacking(b,this->sequenceNumber_var);
}

int PlatooningBeacon::getVehicleId() const
{
    return vehicleId_var;
}

void PlatooningBeacon::setVehicleId(int vehicleId)
{
    this->vehicleId_var = vehicleId;
}

int PlatooningBeacon::getRelayerId() const
{
    return relayerId_var;
}

void PlatooningBeacon::setRelayerId(int relayerId)
{
    this->relayerId_var = relayerId;
}

double PlatooningBeacon::getAcceleration() const
{
    return acceleration_var;
}

void PlatooningBeacon::setAcceleration(double acceleration)
{
    this->acceleration_var = acceleration;
}

double PlatooningBeacon::getSpeed() const
{
    return speed_var;
}

void PlatooningBeacon::setSpeed(double speed)
{
    this->speed_var = speed;
}

double PlatooningBeacon::getPositionX() const
{
    return positionX_var;
}

void PlatooningBeacon::setPositionX(double positionX)
{
    this->positionX_var = positionX;
}

double PlatooningBeacon::getPositionY() const
{
    return positionY_var;
}

void PlatooningBeacon::setPositionY(double positionY)
{
    this->positionY_var = positionY;
}

double PlatooningBeacon::getTime() const
{
    return time_var;
}

void PlatooningBeacon::setTime(double time)
{
    this->time_var = time;
}

int PlatooningBeacon::getSequenceNumber() const
{
    return sequenceNumber_var;
}

void PlatooningBeacon::setSequenceNumber(int sequenceNumber)
{
    this->sequenceNumber_var = sequenceNumber;
}

class PlatooningBeaconDescriptor : public cClassDescriptor
{
  public:
    PlatooningBeaconDescriptor();
    virtual ~PlatooningBeaconDescriptor();

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

Register_ClassDescriptor(PlatooningBeaconDescriptor);

PlatooningBeaconDescriptor::PlatooningBeaconDescriptor() : cClassDescriptor("PlatooningBeacon", "cPacket")
{
}

PlatooningBeaconDescriptor::~PlatooningBeaconDescriptor()
{
}

bool PlatooningBeaconDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PlatooningBeacon *>(obj)!=NULL;
}

const char *PlatooningBeaconDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PlatooningBeaconDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int PlatooningBeaconDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *PlatooningBeaconDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "vehicleId",
        "relayerId",
        "acceleration",
        "speed",
        "positionX",
        "positionY",
        "time",
        "sequenceNumber",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int PlatooningBeaconDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "vehicleId")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "relayerId")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "acceleration")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "speed")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "positionX")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "positionY")==0) return base+5;
    if (fieldName[0]=='t' && strcmp(fieldName, "time")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumber")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PlatooningBeaconDescriptor::getFieldTypeString(void *object, int field) const
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
        "double",
        "double",
        "double",
        "double",
        "double",
        "int",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *PlatooningBeaconDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int PlatooningBeaconDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PlatooningBeacon *pp = (PlatooningBeacon *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PlatooningBeaconDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PlatooningBeacon *pp = (PlatooningBeacon *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getVehicleId());
        case 1: return long2string(pp->getRelayerId());
        case 2: return double2string(pp->getAcceleration());
        case 3: return double2string(pp->getSpeed());
        case 4: return double2string(pp->getPositionX());
        case 5: return double2string(pp->getPositionY());
        case 6: return double2string(pp->getTime());
        case 7: return long2string(pp->getSequenceNumber());
        default: return "";
    }
}

bool PlatooningBeaconDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PlatooningBeacon *pp = (PlatooningBeacon *)object; (void)pp;
    switch (field) {
        case 0: pp->setVehicleId(string2long(value)); return true;
        case 1: pp->setRelayerId(string2long(value)); return true;
        case 2: pp->setAcceleration(string2double(value)); return true;
        case 3: pp->setSpeed(string2double(value)); return true;
        case 4: pp->setPositionX(string2double(value)); return true;
        case 5: pp->setPositionY(string2double(value)); return true;
        case 6: pp->setTime(string2double(value)); return true;
        case 7: pp->setSequenceNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *PlatooningBeaconDescriptor::getFieldStructName(void *object, int field) const
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

void *PlatooningBeaconDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PlatooningBeacon *pp = (PlatooningBeacon *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


