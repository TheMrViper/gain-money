#ifndef OCTETS_HEADER
#define OCTETS_HEADER

struct Rep {
    size_t cap;
    size_t len;
    size_t ref;
    static Rep null;
  public:
    void addref(void);
    void release(void);
    void * data(void);
    void * clone(void);
    void * unique(void);
    void * reserve(unsigned int);
    static size_t frob_size(unsigned int);
    static Rep * create(unsigned int);
    static void * operator new(unsigned int, unsigned int);
    static void operator delete(void *);
};

struct Octets {
  private:
    void *base;

    Rep * rep(void) const;
    void unique(void);
  public:
    Octets & reserve(unsigned int);
    Octets & replace(const void *, unsigned int);
    ~Octets();
    Octets(void);
    Octets(unsigned int);
    Octets(const void *, unsigned int);
    Octets(const void *, const void *);
    Octets(const Octets &);
    Octets & operator=(const Octets &);
    bool operator==(const Octets &) const;
    bool operator!=(const Octets &) const;
    Octets & swap(Octets &);
    void * begin(void);
    const void * begin(void) const;
    void * end(void);
    const void * end(void) const;
    size_t size(void) const;
    size_t capacity(void) const;
    Octets & clear(void);
    Octets & erase(void *, void *);
    Octets & insert(void *, const void *, unsigned int);
    Octets & insert(void *, const void *, const void *);
    Octets & resize(unsigned int);
    void dump(void);
};


#endif // OCTETS_HEADER
