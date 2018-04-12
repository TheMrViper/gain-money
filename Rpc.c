struct Rpc::Data : public Marshal {
  public:
    ~Data(int);
    virtual Rpc::Data * Clone(void) const;
    virtual void Destroy(void);
    virtual Rpc::Data & operator=(const Rpc::Data &);
};
