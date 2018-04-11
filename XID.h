
struct XID {
    int type;
    int id;
  public:
    XID(void);
    XID(int, int);
    bool operator==(const XID &) const;
    bool operator!=(const XID &) const;
    bool operator<(const XID &) const;
    bool IsActive(void) const;
    bool IsPlayerClass(void) const;
    bool IsPlayer(void) const;
    bool IsValid(void) const;
    bool IsErrorType(void) const;
}
