#ifndef RPC_HEADER
#define RPC_HEADER

#include "Marshal.h"

struct Data : public Marshal {
  public:
    ~Data();
    virtual Data * Clone(void) const;
    virtual void Destroy(void);
    virtual Data & operator=(const Data &);
};

#endif // RPC_HEADER
