#ifndef GROLEBASE_HEADER
#define GROLEBASE_HEADER

#include "Rpc.h"
#include "Octets.h"
#include "Marshal.h"

struct GRoleBase : public Rpc::Data {
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
    virtual Rpc::Data * Clone(void) const;
    virtual Rpc::Data & operator=(const Rpc::Data &);
    GRoleBase & operator=(const GRoleBase &);
    virtual Marshal::OctetsStream & marshal(Marshal::OctetsStream &) const;
    virtual const Marshal::OctetsStream & unmarshal(const Marshal::OctetsStream &);
};

#endif // GROLEBASE_HEADER
