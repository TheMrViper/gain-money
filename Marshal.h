#ifndef MARSHAL_HEADER
#define MARSHAL_HEADER

#include "Octets.h"

struct Marshal {
  public:
    virtual Marshal::OctetsStream & marshal(Marshal::OctetsStream &) const;
    virtual const Marshal::OctetsStream & unmarshal(const Marshal::OctetsStream &);
    ~Marshal(int);
};
struct Marshal::OctetsStream {
  private:
    Octets data;
    unsigned int pos;
    unsigned int tranpos;

    unsigned char pop_byte_8(void) const;
    unsigned short pop_byte_16(void) const;
    unsigned long pop_byte_32(void) const;
    unsigned long long pop_byte_64(void) const;
    Marshal::OctetsStream & compact_uint32(unsigned int);
    Marshal::OctetsStream & compact_sint32(int);
    const Marshal::OctetsStream & uncompact_uint32(const unsigned int &) const;
    const Marshal::OctetsStream & uncompact_sint32(const int &) const;
  public:
    OctetsStream(void);
    OctetsStream(const Octets &);
    OctetsStream(const Marshal::OctetsStream &);
    Marshal::OctetsStream & operator=(const Marshal::OctetsStream &);
    bool operator==(const Marshal::OctetsStream &) const;
    bool operator!=(const Marshal::OctetsStream &) const;
    size_t size(void) const;
    void swap(Marshal::OctetsStream &);
    operator Octets&(void);
    void * begin(void);
    const void * begin(void) const;
    void * end(void);
    const void * end(void) const;
    void reserve(unsigned int);
    void insert(void *, const void *, unsigned int);
    void insert(void *, const void *, const void *);
    void erase(void *, void *);
    void clear(void);
    Marshal::OctetsStream & operator<<(char);
    Marshal::OctetsStream & operator<<(unsigned char);
    Marshal::OctetsStream & operator<<(bool);
    Marshal::OctetsStream & operator<<(short);
    Marshal::OctetsStream & operator<<(unsigned short);
    Marshal::OctetsStream & operator<<(int);
    Marshal::OctetsStream & operator<<(unsigned int);
    Marshal::OctetsStream & operator<<(long);
    Marshal::OctetsStream & operator<<(unsigned long);
    Marshal::OctetsStream & operator<<(long long);
    Marshal::OctetsStream & operator<<(unsigned long long);
    Marshal::OctetsStream & operator<<(float);
    Marshal::OctetsStream & operator<<(double);
    Marshal::OctetsStream & operator<<(const Marshal &);
    Marshal::OctetsStream & operator<<(const Octets &);
    Marshal::OctetsStream & push_byte(const char *, unsigned int);
    bool eos(void) const;
    const Marshal::OctetsStream & operator>>(Marshal::Transaction) const;
    const Marshal::OctetsStream & operator>>(const char &) const;
    const Marshal::OctetsStream & operator>>(const unsigned char &) const;
    const Marshal::OctetsStream & operator>>(const bool &) const;
    const Marshal::OctetsStream & operator>>(const short &) const;
    const Marshal::OctetsStream & operator>>(const unsigned short &) const;
    const Marshal::OctetsStream & operator>>(const int &) const;
    const Marshal::OctetsStream & operator>>(const unsigned int &) const;
    const Marshal::OctetsStream & operator>>(const long &) const;
    const Marshal::OctetsStream & operator>>(const unsigned long &) const;
    const Marshal::OctetsStream & operator>>(const long long &) const;
    const Marshal::OctetsStream & operator>>(const unsigned long long &) const;
    const Marshal::OctetsStream & operator>>(const float &) const;
    const Marshal::OctetsStream & operator>>(const double &) const;
    const Marshal::OctetsStream & operator>>(const Marshal &) const;
    const Marshal::OctetsStream & operator>>(const Octets &) const;
    void pop_byte(char *, unsigned int) const;
};

#endif // MARSHAL_HEADER
