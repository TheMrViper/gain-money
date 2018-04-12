#ifndef GROLEBASE_HEADER
#define GROLEBASE_HEADER

#include "Rpc.h"
#include "Octets.h"
#include "Marshal.h"

struct GRoleBase : public Data {
    char version;
    unsigned int id;
    Octets name;
    int race;
    int cls;
    unsigned char gender;
    Octets custom_data;
    Octets config_data;
    unsigned int custom_stamp;
    unsigned char status;
    int delete_time;
    int create_time;
    int lastlogin_time;
    GetRoleForbidRes::GRoleForbidVector forbid;
    Octets help_states;
    unsigned int spouse;
    int reserved1;
    int reserved2;
  public:
    GRoleBase(char, unsigned int, const Octets &, int, int, unsigned char, Octets, Octets, unsigned int,
        unsigned char, int, int, int, unsigned int, int, int);
    GRoleBase(const GRoleBase &);
    virtual Data * Clone(void) const;
    virtual Data & operator=(const Data &);
    GRoleBase & operator=(const GRoleBase &);
    virtual OctetsStream & marshal(OctetsStream &) const;
    virtual const OctetsStream & unmarshal(const OctetsStream &);
};

#endif // GROLEBASE_HEADER
