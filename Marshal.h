#ifndef MARSHAL_HEADER
#define MARSHAL_HEADER

#include "Octets.h"

struct Marshal {
  public:
    virtual OctetsStream & marshal(OctetsStream &) const;
    virtual const OctetsStream & unmarshal(const OctetsStream &);
    ~Marshal(int);
};
struct OctetsStream {
  private:
    Octets data;
    unsigned int pos;
    unsigned int tranpos;

    unsigned char pop_byte_8(void) const;
    unsigned short pop_byte_16(void) const;
    unsigned long pop_byte_32(void) const;
    unsigned long long pop_byte_64(void) const;
    OctetsStream & compact_uint32(unsigned int);
    OctetsStream & compact_sint32(int);
    const OctetsStream & uncompact_uint32(const unsigned int &) const;
    const OctetsStream & uncompact_sint32(const int &) const;
  public:
    OctetsStream(void);
    OctetsStream(const Octets &);
    OctetsStream(const OctetsStream &);
    OctetsStream & operator=(const OctetsStream &);
    bool operator==(const OctetsStream &) const;
    bool operator!=(const OctetsStream &) const;
    size_t size(void) const;
    void swap(OctetsStream &);
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
    OctetsStream & operator<<(char);
    OctetsStream & operator<<(unsigned char);
    OctetsStream & operator<<(bool);
    OctetsStream & operator<<(short);
    OctetsStream & operator<<(unsigned short);
    OctetsStream & operator<<(int);
    OctetsStream & operator<<(unsigned int);
    OctetsStream & operator<<(long);
    OctetsStream & operator<<(unsigned long);
    OctetsStream & operator<<(long long);
    OctetsStream & operator<<(unsigned long long);
    OctetsStream & operator<<(float);
    OctetsStream & operator<<(double);
    OctetsStream & operator<<(const Marshal &);
    OctetsStream & operator<<(const Octets &);
    OctetsStream & push_byte(const char *, unsigned int);
    bool eos(void) const;
    const OctetsStream & operator>>(Transaction) const;
    const OctetsStream & operator>>(const char &) const;
    const OctetsStream & operator>>(const unsigned char &) const;
    const OctetsStream & operator>>(const bool &) const;
    const OctetsStream & operator>>(const short &) const;
    const OctetsStream & operator>>(const unsigned short &) const;
    const OctetsStream & operator>>(const int &) const;
    const OctetsStream & operator>>(const unsigned int &) const;
    const OctetsStream & operator>>(const long &) const;
    const OctetsStream & operator>>(const unsigned long &) const;
    const OctetsStream & operator>>(const long long &) const;
    const OctetsStream & operator>>(const unsigned long long &) const;
    const OctetsStream & operator>>(const float &) const;
    const OctetsStream & operator>>(const double &) const;
    const OctetsStream & operator>>(const Marshal &) const;
    const OctetsStream & operator>>(const Octets &) const;
    void pop_byte(char *, unsigned int) const;
};
enum Transaction {Begin, Commit, Rollback}
#endif // MARSHAL_HEADER
