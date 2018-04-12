#ifndef GROLEBASE_HEADER
#define GROLEBASE_HEADER



struct GRoleBase {
    char version;
    unsigned int id;
    void * name;
    int race;
    int cls;
    unsigned char gender;
    void * custom_data;
    void * config_data;
    unsigned int custom_stamp;
    unsigned char status;
    int delete_time;
    int create_time;
    int lastlogin_time;
    void * forbid;
    Octets help_states;
    unsigned int spouse;
    int reserved1;
    int reserved2;

};

#endif // GROLEBASE_HEADER
